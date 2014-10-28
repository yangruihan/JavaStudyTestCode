package JSTC_14_10_28;

public class ExceptionTest2 {

	public void method() throws Exception {

		System.out.println("Hello Wolrd");

		throw new Exception();
	}

	public static void main(String[] args) throws Exception {
		ExceptionTest2 exceptionTest2 = new ExceptionTest2();

		try {
			exceptionTest2.method();
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			System.out.println("Welcome");
		}
	}
}
