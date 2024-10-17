Q1) Write a program to find the Square of given number using function interface
import java.util.Scanner;
// Functional interface
@FunctionalInterface
interface Square {
double calculateSquare(double number);
}
public class SquareCalculator {
public static void main(String[] args) {
Scanner scanner = new Scanner(System.in);
// Create a lambda expression for calculating the square
Square squareFunction = (number) -> number * number;
// Accept input from the user
System.out.print("Enter a number to find its square: ");
double inputNumber = scanner.nextDouble();
// Calculate the square using the functional interface
double result = squareFunction.calculateSquare(inputNumber);
// Display the resultSystem.out.println("The square of " + inputNumber + " is: " +
result);
// Close the scanner
scanner.close();
}
}
Q2) Write a program to design a screen using Awt that,
import java.awt.*;
import java.awt.event.*;
public class MenuExample {
// Constructor
MenuExample() {
// Creating a frame
Frame frame = new Frame("Java AWT Examples");
frame.setSize(400, 300);
// Creating a menu bar
MenuBar menuBar = new MenuBar();
// Creating "File" menu and adding items
Menu fileMenu = new Menu("File");
MenuItem newFile = new MenuItem("New");
MenuItem openFile = new MenuItem("Open");
MenuItem saveFile = new MenuItem("Save");MenuItem showAbout = new MenuItem("Show About");
MenuItem exitFile = new MenuItem("Exit");
// Adding items to "File" menu
fileMenu.add(newFile);
fileMenu.add(openFile);
fileMenu.add(saveFile);
fileMenu.addSeparator();
fileMenu.add(showAbout);
fileMenu.addSeparator();
fileMenu.add(exitFile);
// Creating "Edit" and "About" menus (with no items for now)
Menu editMenu = new Menu("Edit");
Menu aboutMenu = new Menu("About");
// Adding menus to the menu bar
menuBar.add(fileMenu);
menuBar.add(editMenu);
menuBar.add(aboutMenu);
// Adding the menu bar to the frame
frame.setMenuBar(menuBar);
// Adding a simple action listener to "Exit"
exitFile.addActionListener(new ActionListener() {
public void actionPerformed(ActionEvent e) {
System.exit(0); // Exit the application
}
});
// Show About Action
showAbout.addActionListener(new ActionListener() {
public void actionPerformed(ActionEvent e) {
System.out.println("About Selected!");
}
});
// Closing the window
frame.addWindowListener(new WindowAdapter() {public void windowClosing(WindowEvent we) {
System.exit(0);
}
});
// Making the frame visible
frame.setVisible(true);
}
public static void main(String[] args) {
new MenuExample(); // Calling the constructor
}
}
