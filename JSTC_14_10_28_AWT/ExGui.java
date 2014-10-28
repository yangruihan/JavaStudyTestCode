package JSTC_14_10_28_AWT;

import java.awt.Button;
import java.awt.FlowLayout;
import java.awt.Frame;

public class ExGui {

	private Frame frame;

	private Button button1;

	private Button button2;

	public void go() {
		frame = new Frame("Gui Example");

		frame.setLayout(new FlowLayout());

		button1 = new Button("Button1");

		button2 = new Button("Button2");

		frame.add(button1);
		frame.add(button2);

		frame.setLocation(500, 500);

		frame.pack();
		frame.setVisible(true);

	}

	public static void main(String[] args) {

		ExGui window = new ExGui();

		window.go();
	}
}
