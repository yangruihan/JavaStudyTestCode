package JSTC_14_10_28;

public class ExceptionTest4 {

	public void method() {
		try {
			System.out.println("进入try块");

			System.exit(0);

		} catch (Exception e) {
			System.out.println("异常发生了");
		} finally {
			System.out.println("进入到finally块");
		}

		System.out.println("异常处理后续的代码");
	}
	
	public static void main(String[] args) {
		
		ExceptionTest4 test = new ExceptionTest4();
		
		test.method();
	}
}
