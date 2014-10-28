package JSTC_14_10_28_AWT;

import java.awt.Color;
import java.awt.Frame;
import java.awt.Panel;

public class FrameWithPanel extends Frame {

	public FrameWithPanel(String title) {
		super(title);
	}

	public static void main(String[] args) {

		FrameWithPanel frame = new FrameWithPanel("Frame with panel!");

		Panel panel = new Panel();

		frame.setSize(200, 200);
		frame.setBackground(Color.black);
		frame.setLayout(null);

		panel.setSize(100, 100);
		panel.setBackground(Color.yellow);

		frame.add(panel);
		frame.setVisible(true);

	}
}
