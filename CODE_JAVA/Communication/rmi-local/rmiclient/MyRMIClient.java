// MyRMIClient.java
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class MyRMIClient {
    public static void main(String args[]) {

        try {
            String name = "Calculator";
            String serverIP = "127.0.0.1";  // 注册中心的IP地址  
            int serverPort = 1099;// 注册中心的端口号
			//获取注册中心引用
			Registry registry = LocateRegistry.getRegistry(serverIP, serverPort);
			MyCalc mycalc = (MyCalc) registry.lookup(name);
            int result = mycalc.add(50, 30);
            System.out.println("Result:" + result);
        } catch (Exception e) {
            System.err.println("??? exception:");
            e.printStackTrace();
        }
    }
}