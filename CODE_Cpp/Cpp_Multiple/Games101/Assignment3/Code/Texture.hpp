//
// Created by LEI XU on 4/27/19.
//

#ifndef RASTERIZER_TEXTURE_H
#define RASTERIZER_TEXTURE_H
#include "global.hpp"
#include <Eigen/Eigen>
#include <opencv2/opencv.hpp>
class Texture{
private:
    cv::Mat image_data;

public:
    Texture(const std::string& name)
    {
        image_data = cv::imread(name);
        cv::Mat downimage1;
        cv::pyrDown(image_data,downimage1,cv::Size(image_data.cols/2,image_data.rows/2));
        cv::Mat downimage2;
        cv::pyrDown(downimage1,downimage2,cv::Size(downimage1.cols/2,downimage1.rows/2));
        cv::cvtColor(downimage2, downimage2, cv::COLOR_RGB2BGR);
        //cv::cvtColor(image_data, image_data, cv::COLOR_RGB2BGR);
        width = image_data.cols;
        height = image_data.rows;
    }

    int width, height;

    Eigen::Vector3f getColor(float u, float v)
    {
        //limit the coords not to be minus
        if (u < 0) u = 0;
		if (u > 1) u = 1;
		if (v < 0) v = 0;
		if (v > 1) v = 1;
        auto u_img = u * width;
        auto v_img = (1 - v) * height;
        auto color = image_data.at<cv::Vec3b>(v_img, u_img);
        return Eigen::Vector3f(color[0], color[1], color[2]);
    }

    Eigen::Vector3f getColorBilinear(float u, float v)
    {
        if (u < 0) u = 0;
		if (u > 1) u = 1;
		if (v < 0) v = 0;
		if (v > 1) v = 1;
        float u_img = (float)u * width;
        float v_img = (float)(1 - v) * height;

        float u_min = std::floor(u_img);
        float u_max = std::ceil(u_img);
        float v_min = std::ceil(v_img);
        float v_max = std::floor(v_img);

        auto u00 = image_data.at<cv::Vec3b>(v_min, u_min);
        auto u01 = image_data.at<cv::Vec3b>(v_max, u_min);
        auto u10 = image_data.at<cv::Vec3b>(v_min, u_max);
        auto u11 = image_data.at<cv::Vec3b>(v_max, u_max);

        float rs = (u_img - u_min) / (u_max - u_min);
		float rt = (v_img - v_max) / (v_min - v_max);
        auto u0 = (1 - rs) * u00 + rs * u10;
        auto u1 = (1 - rs) * u01 + rs * u11;
        auto ut = (1 - rt) * u1 + rt * u0;

        return Eigen::Vector3f(ut[0], ut[1], ut[2]);
    }

};
#endif //RASTERIZER_TEXTURE_H
