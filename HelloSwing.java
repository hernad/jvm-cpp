//package start;

/*
 * HelloWorldSwing.java requires no other files. 
 */
import javax.swing.*;        
import java.awt.*;
import java.awt.event.*;

public class HelloSwing {
    /**
     * Create the GUI and show it.  For thread safety,
     * this method should be invoked from the
     * event-dispatching thread.
     */

    private static void createAndShowGUI() {
        //Create and set up the window.
        
         JMenuBar menuBar = new JMenuBar();
         JFrame frame = new JFrame("HelloSwing");
         //static final long serialVersionUID = 1L;
         JMenu file = new JMenu("File");
         JMenuItem exit = new JMenuItem("Exit");


        file.add(exit);
        menuBar.add(file);
       
        ActionListener action = new ActionListener() {
   
          @Override
          public void actionPerformed(ActionEvent e) {
                System.exit(0);
          }
    
        };

        exit.addActionListener(action);

        WindowListener exitListener = new WindowAdapter() {

            @Override
            public void windowClosing(WindowEvent e) {
                /* final int confirm = JOptionPane.showOptionDialog(frame,
                        "Are You Sure to Close this Application?",
                        "Exit Confirmation", JOptionPane.YES_NO_OPTION,
                        JOptionPane.QUESTION_MESSAGE, null, null, null);
                if (confirm == JOptionPane.YES_OPTION) {
                    System.exit(0);
                }
                */
                System.exit(0);
            }
        };


        frame.addWindowListener(exitListener);

        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setJMenuBar(menuBar);

        //Add the ubiquitous "Hello World" label.
        JLabel label = new JLabel("Hello World");
        frame.getContentPane().add(label);

        frame.setPreferredSize(new Dimension(400, 300));
        frame.setLocation(100,100);
        
        //Display the window.
        frame.pack();
        frame.setVisible(true);
    }



    public static void main() {
           String[] args = {};
           main(args);
    }

    public static void main(String[] args) {
        //Schedule a job for the event-dispatching thread:
        //creating and showing this application's GUI.
        javax.swing.SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                createAndShowGUI();
            }
        });
    }

}
