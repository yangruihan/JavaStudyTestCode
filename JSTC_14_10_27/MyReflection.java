package JSTC_14_10_27;

import java.lang.annotation.Annotation;
import java.lang.reflect.Method;

public class MyReflection {

	public static void main(String[] args) throws Exception {
		MyTest myTest = new MyTest();

		Class<MyTest> myTestClass = MyTest.class;

		Method method = myTestClass.getMethod("output", new Class[] {});

		if (method.isAnnotationPresent(MyAnnotation.class)) {
			method.invoke(myTest, new Object[] {});

			Annotation ann = method.getAnnotation(MyAnnotation.class);

			String s1 = ((MyAnnotation) ann).value1();
			String s2 = ((MyAnnotation) ann).value2();

			System.out.println(s1 + " " + s2);
		}

		Annotation[] anns = method.getAnnotations();

		for (Annotation annTemp : anns) {
			System.out.println(annTemp.annotationType().getName());
		}

	}
}
