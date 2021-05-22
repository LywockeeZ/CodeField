//MyRMIServer.java
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;

public class MyRMIServer {
    public static void main(String[] args) throws Exception {

        try {
            String name = "Calculator";
            MyCalc engine = new MyCalcImpl();
			// 生成包裹engine对象的容器对象，即skeleton对象
            MyCalc skeleton = (MyCalc) UnicastRemoteObject.exportObject(engine, 0);
			// 获取注册中心的引用，示例中，注册中心运行在本地计算机上。
			Registry registry = LocateRegistry.getRegistry("127.0.0.1", 1099);
            System.out.println("Registering Calculator Object");
            registry.rebind(name, skeleton);
        } catch (Exception e) {
            System.err.println("Exception:" + e);
            e.printStackTrace();
        }
    }
}