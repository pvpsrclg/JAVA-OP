Q1) Write a program to create parent class College(cno, cname, caddr) and derived class
Department(dno, dname) from College. Write a necessary methods to display College details.
// Parent class College
class College {
protected int cno;
// College number
protected String cname; // College name
protected String caddr; // College address
// Constructor for College
public College(int cno, String cname, String caddr) {
this.cno = cno;
this.cname = cname;
this.caddr = caddr;
}
// Method to display college details
public void displayCollegeDetails() {
System.out.println("College Number: " + cno);
System.out.println("College Name: " + cname);
System.out.println("College Address: " + caddr);
}
}
// Derived class Department
class Department extends College {
private int dno; // Department number
private String dname; // Department name
// Constructor for Department
public Department(int cno, String cname, String caddr, int dno, String
dname) {super(cno, cname, caddr); // Call to parent constructor
this.dno = dno;
this.dname = dname;
}
// Method to display department details
public void displayDepartmentDetails() {
// Display college details
displayCollegeDetails();
// Display department details
System.out.println("Department Number: " + dno);
System.out.println("Department Name: " + dname);
}
}
// Main class to test the implementation
public class CollegeDepartmentTest {
public static void main(String[] args) {
// Create a Department object
Department department = new Department(101, "ABC College", "123
Main St", 1, "Computer Science");
// Display college and department details
department.displayDepartmentDetails();
}
}
import javax.swing.*;import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
public class SimpleCalculator implements ActionListener {
// Frame
JFrame frame;
// Textfield to display the result
JTextField textField;
// Number buttons and function buttons
JButton[] numberButtons = new JButton[10];
JButton[] functionButtons = new JButton[8];
// Function buttons: add, subtract, multiply, divide, decimal, equals,
delete, clear
JButton addButton, subButton, mulButton, divButton;
JButton decButton, equButton, delButton, clrButton;
// Panel for grid layout
JPanel panel;
// Variables to store values and operations
double num1 = 0, num2 = 0, result = 0;
char operator;
public SimpleCalculator() {
// Create the frame
frame = new JFrame("Simple Calculator");
frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
frame.setSize(420, 550);
frame.setLayout(null);
// Create the text field to display results
textField = new JTextField();
textField.setBounds(50, 25, 300, 50);
textField.setEditable(false);// Create the function buttons
addButton = new JButton("+");
subButton = new JButton("-");
mulButton = new JButton("*");
divButton = new JButton("/");
decButton = new JButton(".");
equButton = new JButton("=");
delButton = new JButton("Del");
clrButton = new JButton("Clr");
// Add function buttons to the array
functionButtons[0] = addButton;
functionButtons[1] = subButton;
functionButtons[2] = mulButton;
functionButtons[3] = divButton;
functionButtons[4] = decButton;
functionButtons[5] = equButton;
functionButtons[6] = delButton;
functionButtons[7] = clrButton;
// Add action listeners to function buttons
for (int i = 0; i < 8; i++) {
functionButtons[i].addActionListener(this);
}
// Create number buttons
for (int i = 0; i < 10; i++) {
numberButtons[i] = new JButton(String.valueOf(i));
numberButtons[i].addActionListener(this);
}
// Panel for the grid layout
panel = new JPanel();
panel.setBounds(50, 100, 300, 300);
panel.setLayout(new GridLayout(4, 4, 10, 10));
// Add buttons to the panel
panel.add(numberButtons[1]);
panel.add(numberButtons[2]);
panel.add(numberButtons[3]);panel.add(addButton);
panel.add(numberButtons[4]);
panel.add(numberButtons[5]);
panel.add(numberButtons[6]);
panel.add(subButton);
panel.add(numberButtons[7]);
panel.add(numberButtons[8]);
panel.add(numberButtons[9]);
panel.add(mulButton);
panel.add(decButton);
panel.add(numberButtons[0]);
panel.add(equButton);
panel.add(divButton);
// Add components to the frame
frame.add(panel);
frame.add(textField);
frame.setVisible(true);
}
// Handling button clicks
public void actionPerformed(ActionEvent e) {
for (int i = 0; i < 10; i++) {
if (e.getSource() == numberButtons[i]) {
textField.setText(textField.getText().concat(String.valueOf(i)));
}
}
if (e.getSource() == decButton) {
textField.setText(textField.getText().concat("."));
}
if (e.getSource() == addButton) {
num1 = Double.parseDouble(textField.getText());
operator = '+';
textField.setText("");
}
if (e.getSource() == subButton) {
num1 = Double.parseDouble(textField.getText());
operator = '-';
textField.setText("");}
if (e.getSource() == mulButton) {
num1 = Double.parseDouble(textField.getText());
operator = '*';
textField.setText("");
}
if (e.getSource() == divButton) {
num1 = Double.parseDouble(textField.getText());
operator = '/';
textField.setText("");
}
if (e.getSource() == equButton) {
num2 = Double.parseDouble(textField.getText());
switch (operator) {
case '+':
result = num1 + num2;
break;
case '-':
result = num1 - num2;
break;
case '*':
result = num1 * num2;
break;
case '/':
result = num1 / num2;
break;
}
textField.setText(String.valueOf(result));
num1 = result;
}
if (e.getSource() == clrButton) {
textField.setText("");
}
if (e.getSource() == delButton) {
String string = textField.getText();
textField.setText("");
for (int i = 0; i < string.length() - 1; i++) {
textField.setText(textField.getText() + string.charAt(i));
}}
}
public static void main(String[] args) {
new SimpleCalculator();
}
}
