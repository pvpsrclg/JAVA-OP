Q1) Create an abstract class 'Bank' with an abstract method 'getBalance'. Rs. 100, Rs.150 and
Rs.200 are deposited in banks A, B and C respectively. 'BankA', 'BankB' and 'BankC aresubclasses of class 'Bank', each having a method named 'getBalance'. Call this method by
creating an object of each of the three classes.
// Abstract class Bank
abstract class Bank {
// Abstract method to get balance
public abstract int getBalance();
}
// Class BankA which extends Bank
class BankA extends Bank {
private int balance;
// Constructor to initialize balance
public BankA() {
this.balance = 100;
// Rs. 100 deposited
}
// Override the abstract method getBalance
@Override
public int getBalance() {
return balance;
}
}
// Class BankB which extends Bank
class BankB extends Bank {
private int balance;
// Constructor to initialize balance
public BankB() {
this.balance = 150;
// Rs. 150 deposited
}
// Override the abstract method getBalance
@Override
public int getBalance() {
return balance;
}
}// Class BankC which extends Bank
class BankC extends Bank {
private int balance;
// Constructor to initialize balance
public BankC() {
this.balance = 200;
// Rs. 200 deposited
}
// Override the abstract method getBalance
@Override
public int getBalance() {
return balance;
}
}
// Main class to test the program
public class BankTest {
public static void main(String[] args) {
// Create objects for BankA, BankB, and BankC
Bank bankA = new BankA();
Bank bankB = new BankB();
Bank bankC = new BankC();
// Display balances for each bank
System.out.println("Balance in Bank A: Rs. " +
bankA.getBalance());
System.out.println("Balance in Bank B: Rs. " +
bankB.getBalance());
System.out.println("Balance in Bank C: Rs. " +
bankC.getBalance());
}
}
Q2) Program that displays three concentric circles where ever the user clicks the mouse on a
frame. The program must exit when user clicks 'X' on the frame.import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
public class ConcentricCircles extends JFrame {
private int x = -100;
private int y = -100;
public ConcentricCircles() {
setTitle("Concentric Circles");
setSize(400, 400);
setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
// Add mouse listener to detect clicks on the frame
addMouseListener(new MouseAdapter() {
@Override
public void mouseClicked(MouseEvent e) {
// Update the coordinates with the mouse click location
x = e.getX();
y = e.getY();
repaint(); // Call repaint to redraw the circles
}
});
}
@Override
public void paint(Graphics g) {
super.paint(g);
// Draw three concentric circles centered at the clicked position
g.drawOval(x - 30, y - 30, 60, 60);
g.drawOval(x - 60, y - 60, 120, 120);
g.drawOval(x - 90, y - 90, 180, 180);}
public static void main(String[] args) {
// Create the frame and make it visible
ConcentricCircles frame = new ConcentricCircles();
frame.setVisible(true);
}
}
