package JSTC_14_10_29;

import java.awt.BorderLayout;
import java.awt.Button;
import java.awt.Frame;
import java.awt.Panel;

import javax.swing.border.Border;

public class ExGui3 {

	private Frame frame;
	private Panel panel;
	private Button b1, b2, b3, b4;

	public void go() {
		frame = new Frame("Complex Layout");

		b1 = new Button("West");
		b2 = new Button("Hello");

		frame.add(b1, BorderLayout.WEST);
		frame.add(b2, BorderLayout.CENTER);

		panel = new Panel();

		b3 = new Button("World");
		b4 = new Button("Welcome");

		panel.add(b3);
		panel.add(b4);

		frame.add(panel, BorderLayout.NORTH);

		frame.pack();
		frame.setVisible(true);

	}

	public static void main(String[] args) {
		ExGui3 frame = new ExGui3();

		frame.go();
	}
}
