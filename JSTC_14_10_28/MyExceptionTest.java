package JSTC_14_10_28;

public class MyExceptionTest {

	public void method(String str) throws MyException {
		if (null == str) {
			throw new MyException("传入的字符串参数不能为null");
		} else {
			System.out.println(str);
		}
	}

	public static void main(String[] args) {

		MyExceptionTest myExceptionTest = new MyExceptionTest();

		String str = null;
		try {
			myExceptionTest.method(str);
		} catch (Exception e) {
			((MyException) e).printStackTrace();
			System.out.println(e.getMessage());
			System.out.println("1");
		} finally {
			System.out.println("异常处理完毕");
		}
	}
}
