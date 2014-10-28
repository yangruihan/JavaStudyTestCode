package JSTC_14_10_28;

public class MyException extends Exception {

	/**
	 * 自定义构造函数
	 */
	public MyException() {
		super();
	}

	/**
	 * 自定义带参数的构造函数
	 * 
	 * @param message
	 */
	public MyException(String message) {
		super(message);
	}
	
	

}
