package JSTC_14_10_29;

import java.awt.BorderLayout;
import java.awt.Button;
import java.awt.Frame;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class TestButton {

	public static void main(String[] args) {

		Frame frame = new Frame();

		Button button = new Button("Press Me!");

		button.addActionListener(new MyButtonListener());

		frame.add(button, BorderLayout.CENTER);

		frame.setLocation(200, 200);

		frame.pack();

		frame.setVisible(true);

	}

}

// 自己定义事件监听器
class MyButtonListener implements ActionListener {

	@Override
	public void actionPerformed(ActionEvent e) {
		System.out.println("The Button is pressed!");
	}

}