import sys
sys.path.append('/Users/kb/bin/opencv-3.1.0/build/lib/')

import cv2
import numpy as np

def cross_correlation_2d(img, kernel):
    new_img = np.zeros((img.shape[0], img.shape[1], 3))

    #判断是否是灰度图，若是灰度图放入一个三维数组中，并将flag置为1
    if len(img.shape) < 3:
        new_img[:, :, 0] = img[:, :]
        flag = 1
    else:
        new_img = img
        flag = 0

    #分别得到图像与核的维度
    im_dim = img.shape
    flt_dim = kernel.shape
    img_dim1 = im_dim[0]
    img_dim2 = im_dim[1]
    flt_dim1 = flt_dim[0]
    flt_dim2 = flt_dim[1]

    #要拓展的行数和列数
    pad_dim1 = int((flt_dim1 - 1) / 2)
    pad_dim2 = int((flt_dim2 - 1) / 2)
    #将图像矩阵拓展
    pad_mat = np.zeros((img_dim1 + 2 * pad_dim1, img_dim2 + 2 * pad_dim2, 3))
    pad_mat[pad_dim1: img_dim1 + pad_dim1, pad_dim2: img_dim2 + pad_dim2] = new_img
    
    output = np.zeros((img_dim1, img_dim2, 3))

    for d in range(3):
        for i in range(img_dim1):
            for j in range(img_dim2):
                #sum()是对最外层维度求和，所以要求和两次
                output[i][j][d] = sum(sum(np.multiply(kernel, pad_mat[i:i + flt_dim1, j:j + flt_dim2, d])))

    if flag == 1 :
        new_output = np.zeros((img_dim1, img_dim2))
        new_output[:, :] = output[:, :, 0]
        return new_output

    return output


def convolve_2d(img, kernel):
    #卷积就是对图像旋转180度进行相关操作
    new_kernel = np.rot90(kernel, 2)
    return cross_correlation_2d(img, new_kernel)
    

def gaussian_blur_kernel_2d(sigma, height, width):
    kernel = np.zeros([height, width])
    center_x = height // 2
    center_y = width // 2
    
    s = 2*(sigma**2)
    sum_val = 0
    for i in range(0,height):
        for j in range(0,width):
            x = i-center_x
            y = j-center_y
            kernel[i,j] = np.exp(-(x**2+y**2) / s)
            sum_val += kernel[i,j]
    #相当于/(np.pi * s), 当权重核不是正方形时要保证权重核之和为1
    sum_val = 1/sum_val
    return kernel * sum_val
    

def low_pass(img, sigma, size):
    kernel = gaussian_blur_kernel_2d(sigma, size, size)
    return convolve_2d(img, kernel)
    

def high_pass(img, sigma, size):
    return img - low_pass(img, sigma, size)
    

def create_hybrid_image(img1, img2, sigma1, size1, high_low1, sigma2, size2,
        high_low2, mixin_ratio):
    '''This function adds two images to create a hybrid image, based on
    parameters specified by the user.'''
    high_low1 = high_low1.lower()
    high_low2 = high_low2.lower()

    if img1.dtype == np.uint8:
        img1 = img1.astype(np.float32) / 255.0
        img2 = img2.astype(np.float32) / 255.0

    if high_low1 == 'low':
        img1 = low_pass(img1, sigma1, size1)
    else:
        img1 = high_pass(img1, sigma1, size1)

    if high_low2 == 'low':
        img2 = low_pass(img2, sigma2, size2)
    else:
        img2 = high_pass(img2, sigma2, size2)

    img1 *= 2 * (1 - mixin_ratio)
    img2 *= 2 * mixin_ratio
    hybrid_img = (img1 + img2)
   #return (hybrid_img * 255).clip(0, 255).astype(np.uint8)
    min_h=np.amin(hybrid_img)
    max_h=np.amax(hybrid_img)
    return ((hybrid_img-min_h)/(max_h-min_h) * 255).clip(0, 255).astype(np.uint8)



