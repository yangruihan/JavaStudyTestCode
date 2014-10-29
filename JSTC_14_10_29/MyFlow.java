package JSTC_14_10_29;

import java.awt.Button;
import java.awt.FlowLayout;
import java.awt.Frame;

public class MyFlow {

	private Frame frame;

	private Button button1, button2, button3;

	public void go() {
		frame = new Frame("Flow Layout");

		// ÀûÓÃFlowLayoutÌæ´úBorderLayout
		frame.setLayout(new FlowLayout());

		button1 = new Button("Hello");

		button2 = new Button("World");

		button3 = new Button("Welcome");

		frame.add(button1);

		frame.add(button2);

		frame.add(button3);

		frame.setSize(100, 100);
		frame.setVisible(true);

	}

	public static void main(String[] args) {

		MyFlow flow = new MyFlow();

		flow.go();
	}
}
