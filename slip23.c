Q1) Define a class MyNumber having one private int data member. Write a default constructor
to initialize it to 0 and another constructor to initialize it to a value (Use this). Write methods
isNegative, is Positive, isZero, isOdd, isEven. Create an object in main. Use command line
arguments to pass a value to the Object.
class MyNumber {
// Private data member
private int number;
// Default constructor (initializes number to 0)
public MyNumber() {
this.number = 0;
}
// Parameterized constructor (initializes number to a given value)
public MyNumber(int number) {
this.number = number;
}
// Method to check if the number is negative
public boolean isNegative() {
return this.number < 0;
}
// Method to check if the number is positive
public boolean isPositive() {
return this.number > 0;}
// Method to check if the number is zero
public boolean isZero() {
return this.number == 0;
}
// Method to check if the number is odd
public boolean isOdd() {
return this.number % 2 != 0;
}
// Method to check if the number is even
public boolean isEven() {
return this.number % 2 == 0;
}
// Method to display the number and its properties
public void displayProperties() {
System.out.println("Number: " + number);
if (isNegative()) {
System.out.println("The number is Negative.");
} else if (isPositive()) {
System.out.println("The number is Positive.");
} else {
System.out.println("The number is Zero.");
}
if (isOdd()) {
System.out.println("The number is Odd.");
} else {
System.out.println("The number is Even.");
}
}
// Main method to create an object and pass command-line arguments
public static void main(String[] args) {
if (args.length == 0) {
System.out.println("Please provide a number as a command-line
argument.");return;
}
try {
// Parse the command-line argument to an integer
int inputNumber = Integer.parseInt(args[0]);
// Create an object of MyNumber using the parameterized
constructor
MyNumber myNum = new MyNumber(inputNumber);
// Display the properties of the number
myNum.displayProperties();
} catch (NumberFormatException e) {
System.out.println("Invalid input! Please enter a valid
integer.");
}
}
}
Q2) Write a simple currency converter, as shown in the figure. User can enter the amount of
"Singapore Dollars", "US Dollars", or "Euros", in floating-point number. The converted values
shall be displayed to 2 decimal places. Assume that 1 USD = 1.41 SGD, 1 USD = 0.92 Euro, 1
SGID=0.65 Euro.
import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;import java.text.DecimalFormat;
public class CurrencyConverter {
public static void main(String[] args) {
// Create JFrame
JFrame frame = new JFrame("Currency Converter");
frame.setSize(400, 200);
frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
frame.setLayout(null);
// Create text fields
JTextField sgdField = new JTextField();
sgdField.setBounds(150, 20, 100, 30);
frame.add(sgdField);
JTextField usdField = new JTextField();
usdField.setBounds(150, 60, 100, 30);
frame.add(usdField);
JTextField euroField = new JTextField();
euroField.setBounds(150, 100, 100, 30);
frame.add(euroField);
// Labels
JLabel sgdLabel = new JLabel("Singapore Dollars");
sgdLabel.setBounds(20, 20, 120, 30);
frame.add(sgdLabel);
JLabel usdLabel = new JLabel("US Dollars");
usdLabel.setBounds(20, 60, 120, 30);
frame.add(usdLabel);
JLabel euroLabel = new JLabel("Euros");
euroLabel.setBounds(20, 100, 120, 30);
frame.add(euroLabel);
// Button to calculate
JButton convertButton = new JButton("Convert");
convertButton.setBounds(270, 20, 100, 30);
frame.add(convertButton);// Conversion rates
double usdToSgd = 1.41;
double usdToEuro = 0.92;
double sgdToEuro = 0.65;
DecimalFormat df = new DecimalFormat("0.00");
// ActionListener for button
convertButton.addActionListener(new ActionListener() {
@Override
public void actionPerformed(ActionEvent e) {
String sgdText = sgdField.getText();
String usdText = usdField.getText();
String euroText = euroField.getText();
if (!sgdText.isEmpty()) {
double sgd = Double.parseDouble(sgdText);
usdField.setText(df.format(sgd / usdToSgd));
euroField.setText(df.format(sgd * sgdToEuro));
} else if (!usdText.isEmpty()) {
double usd = Double.parseDouble(usdText);
sgdField.setText(df.format(usd * usdToSgd));
euroField.setText(df.format(usd * usdToEuro));
} else if (!euroText.isEmpty()) {
double euro = Double.parseDouble(euroText);
usdField.setText(df.format(euro / usdToEuro));
sgdField.setText(df.format(euro / sgdToEuro));
}
}
});
frame.setVisible(true);
}
}
