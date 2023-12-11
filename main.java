
public class NativeCallClass {
	public static void callNative(Runnable cb) {
		new Thread(() -> {
			try {
				Thread.sleep(2000);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}

			cb.run();
		}).start();
	}
}

// Call from JavaScript
/*
	jsb.reflection.callStaticMethod(
		"somePackage/NativeCallClass", 
		"callNative", 
		"(Ljava/lang/Runnable;)V", 
		cb
	);

*/

