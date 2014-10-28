package JSTC_14_10_28;

public class MyExceptionTest {

	public void method(String str) throws MyException, MyException2 {
		if (null == str) {
			throw new MyException("������ַ�����������Ϊnull");
		} else if ("hello".equals(str)) {
			throw new MyException2("�����ַ�������Ϊhello");
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
			System.out.println("�쳣�������");
		}
	}
}
