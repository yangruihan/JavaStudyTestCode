package JSTC_14_10_28;

public class ExceptionTest {

	public static void main(String[] args) {

		int c = 0;

		try {
			int a = 3;
			int b = 0;

			c = a / b; // һ�������쳣������catch�����֣���������catch�е�����
						// û���쳣��catch����������ǲ��ᱻִ�е�
			
			System.out.println("Hello World");

		} catch (ArithmeticException e) {
			System.out.println("������Ϊ0");
			
//			e.printStackTrace();
		}
		finally { 
			System.out.println("Welcome");
		}

		System.out.println(c);

	}
}
