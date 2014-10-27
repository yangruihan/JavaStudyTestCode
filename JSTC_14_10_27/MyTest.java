package JSTC_14_10_27;

@MyAnnotation(value1 = "Hello", value2 = "World")
public class MyTest {

	@MyAnnotation(value1 = "Hello", value2 = "World")
	@Deprecated
	@SuppressWarnings({ "deprecation", "unchecked" })
	public void output() {
		System.out.println("This is my Annotation test code");
	}
}
