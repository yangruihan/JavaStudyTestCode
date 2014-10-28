package JSTC_14_10_28;

public class ExceptionTest {

	public static void main(String[] args) {

		int c = 0;

		try {
			int a = 3;
			int b = 0;

			c = a / b; // 一旦产生异常，就由catch来接手，继续运行catch中的内容
						// 没有异常，catch里面的内容是不会被执行的
			
			System.out.println("Hello World");

		} catch (ArithmeticException e) {
			System.out.println("被除数为0");
			
//			e.printStackTrace();
		}
		finally { 
			System.out.println("Welcome");
		}

		System.out.println(c);

	}
}
