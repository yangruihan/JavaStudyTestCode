package JSTC_14_10_28;

public class ExceptionTest4 {

	public void method() {
		try {
			System.out.println("����try��");

			System.exit(0);

		} catch (Exception e) {
			System.out.println("�쳣������");
		} finally {
			System.out.println("���뵽finally��");
		}

		System.out.println("�쳣��������Ĵ���");
	}
	
	public static void main(String[] args) {
		
		ExceptionTest4 test = new ExceptionTest4();
		
		test.method();
	}
}
