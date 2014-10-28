package JSTC_14_10_28;

public class MyExceptionTest {

	public void method(String str) throws MyException, MyException2 {
		if (null == str) {
			throw new MyException("传入的字符串参数不能为null");
		} else if ("hello".equals(str)) {
			throw new MyException2("传入字符串不能为hello");
		} else {
			System.out.println(str);
		}
	}

	public static void main(String[] args) {

		MyExceptionTest myExceptionTest = new MyExceptionTest();

		String str = "hello";

		try {
			myExceptionTest.method(str);
		} catch (MyException e) {
			System.out.println(e.getMessage());
			System.out.println("1");
		} catch (MyException2 e) {
			System.out.println(e.getMessage());
			System.out.println("2");
		} catch (Exception e) {
			System.out.println(e.getMessage());
			System.out.println("3");
		} finally {
			System.out.println("异常处理完毕");
		}
	}
}
