Q1) Design a Super class Customer (name, phone-number). Derive a class Depositor(accno,
balance) from Customer. Again, derive a class Borrower (loan-no, loan-amt) from Depositor.
Write necessary member functions to read and display the details of 'n'customers.
import java.util.Scanner;
// Superclass: Customer
class Customer {
protected String name;
protected String phoneNumber;
// Method to read customer details
public void readCustomerDetails() {
Scanner scanner = new Scanner(System.in);
System.out.print("Enter Customer Name: ");
name = scanner.nextLine();
System.out.print("Enter Phone Number: ");
phoneNumber = scanner.nextLine();
}
// Method to display customer details
public void displayCustomerDetails() {
System.out.println("Customer Name: " + name);
System.out.println("Phone Number: " + phoneNumber);}
}
// Derived class: Depositor
class Depositor extends Customer {
protected String accNo;
protected double balance;
// Method to read depositor details
public void readDepositorDetails() {
readCustomerDetails(); // Call method from Customer
Scanner scanner = new Scanner(System.in);
System.out.print("Enter Account Number: ");
accNo = scanner.nextLine();
System.out.print("Enter Balance: ");
balance = scanner.nextDouble();
}
// Method to display depositor details
public void displayDepositorDetails() {
displayCustomerDetails(); // Call method from Customer
System.out.println("Account Number: " + accNo);
System.out.println("Balance: " + balance);
}
}
// Derived class: Borrower
class Borrower extends Depositor {
protected String loanNo;
protected double loanAmt;
// Method to read borrower details
public void readBorrowerDetails() {
readDepositorDetails(); // Call method from Depositor
Scanner scanner = new Scanner(System.in);
System.out.print("Enter Loan Number: ");
loanNo = scanner.nextLine();
System.out.print("Enter Loan Amount: ");
loanAmt = scanner.nextDouble();
}// Method to display borrower details
public void displayBorrowerDetails() {
displayDepositorDetails(); // Call method from Depositor
System.out.println("Loan Number: " + loanNo);
System.out.println("Loan Amount: " + loanAmt);
}
}
// Main class to test the implementation
public class CustomerDetailsDemo {
public static void main(String[] args) {
Scanner scanner = new Scanner(System.in);
System.out.print("Enter the number of customers: ");
int n = scanner.nextInt();
scanner.nextLine(); // Consume the newline character
Borrower[] customers = new Borrower[n];
// Reading details of n customers
for (int i = 0; i < n; i++) {
System.out.println("\nEntering details for Customer " + (i +
1) + ":");
customers[i] = new Borrower();
customers[i].readBorrowerDetails();
}
// Displaying details of n customers
System.out.println("\nCustomer Details:");
for (int i = 0; i < n; i++) {
System.out.println("\nDetails of Customer " + (i + 1) + ":");
customers[i].displayBorrowerDetails();
}
// Close the scanner
scanner.close();
}
}Q2) Write Java program to design three text boxes and two buttons using swing. Enter different
strings in first and second textbox. On clicking the First command button, concatenation of two
strings should be displayed in third text box and on clicking second command button, reverse of
string should display in third text box
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
public class StringManipulationApp {
public static void main(String[] args) {
// Create a JFrame
JFrame frame = new JFrame("String Manipulation");
frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
frame.setSize(400, 300);
frame.setLayout(new FlowLayout());
// Create text boxes
JTextField textField1 = new JTextField(15);
JTextField textField2 = new JTextField(15);
JTextField textField3 = new JTextField(15);
textField3.setEditable(false); // Make third text box read-only
// Create buttons
JButton concatButton = new JButton("Concatenate");
JButton reverseButton = new JButton("Reverse");
// Action listener for concatenation button
concatButton.addActionListener(new ActionListener() {
@Override
public void actionPerformed(ActionEvent e) {
String str1 = textField1.getText();
String str2 = textField2.getText();
String result = str1 + str2; // Concatenate strings
textField3.setText(result); // Display result
}
});
// Action listener for reverse buttonreverseButton.addActionListener(new ActionListener() {
@Override
public void actionPerformed(ActionEvent e) {
String str1 = textField1.getText();
String reversed = new
StringBuilder(str1).reverse().toString(); // Reverse string
textField3.setText(reversed); // Display result
}
});
// Add components to the frame
frame.add(new JLabel("String 1:"));
frame.add(textField1);
frame.add(new JLabel("String 2:"));
frame.add(textField2);
frame.add(concatButton);
frame.add(reverseButton);
frame.add(new JLabel("Result:"));
frame.add(textField3);
// Set the frame visibility
frame.setVisible(true);
}
}
