package JSTC_14_10_28_AWT;

import java.awt.Color;
import java.awt.Frame;

@SuppressWarnings("serial")
public class MyFrame extends Frame {

	public MyFrame(String title) {
		super(title);
	}

	public static void main(String[] args) {

		MyFrame frame = new MyFrame("First GUI app");
		
		frame.setSize(500,500);
		frame.setBackground(Color.CYAN);
		
		frame.setVisible(true);
	}

}
