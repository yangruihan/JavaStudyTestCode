package JSTC_14_10_27;

import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;

@Retention(RetentionPolicy.RUNTIME)
public @interface MyAnnotation {

	String value1() default "Hello";
	String value2();
	
}
