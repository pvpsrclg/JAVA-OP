Q1) Define an Employee class with suitable attributes having getSalary() method, which returns
salary withdrawn by a particular employee. Write a class Manager which extends a classEmployee, override the getSalary() method, which will return salary of manager by adding
traveling allowance, house rent allowance etc.
// Base class Employee
class Employee {
// Attributes
private String name;
private double basicSalary;
// Constructor
public Employee(String name, double basicSalary) {
this.name = name;
this.basicSalary = basicSalary;
}
// Method to get the salary
public double getSalary() {
return basicSalary; // Base salary for employee
}
// Method to display employee details
public void displayDetails() {
System.out.println("Employee Name: " + name);
System.out.println("Basic Salary: " + basicSalary);
}
}
// Derived class Manager that extends Employee
class Manager extends Employee {
// Allowances
private double travelAllowance;
private double houseRentAllowance;
// Constructor
public Manager(String name, double basicSalary, double
travelAllowance, double houseRentAllowance) {
super(name, basicSalary); // Call to the superclass constructor
this.travelAllowance = travelAllowance;
this.houseRentAllowance = houseRentAllowance;
}// Overriding getSalary() method
@Override
public double getSalary() {
// Calculate manager's salary including allowances
return super.getSalary() + travelAllowance + houseRentAllowance;
}
// Method to display manager details
@Override
public void displayDetails() {
super.displayDetails(); // Call to the base class method
System.out.println("Travel Allowance: " + travelAllowance);
System.out.println("House Rent Allowance: " + houseRentAllowance);
System.out.println("Total Salary: " + getSalary());
}
}
// Main class to test the implementation
public class Main {
public static void main(String[] args) {
// Creating an Employee object
Employee emp1 = new Employee("John Doe", 50000);
emp1.displayDetails();
System.out.println("-----------------------------");
// Creating a Manager object
Manager mgr1 = new Manager("Alice Smith", 70000, 5000, 10000);
mgr1.displayDetails();
}
}
Q2) Write a program to accept a string as command line argument and check whether it is a file
or directory. Also perform operations as follows:
i) If it is a directory, delete all text files in that directory. Confirm delete operation from user
before deleting text files. Also, display a count showing the number of files deleted, if any, from
the directory.
ii)If it is a file display various details of that file.import java.io.File;
import java.util.Scanner;
public class FileDirectoryChecker {
public static void main(String[] args) {
// Check if a command line argument is provided
if (args.length != 1) {
System.out.println("Please provide a file or directory path as
a command line argument.");
return;
}
// Get the input path from the command line argument
String path = args[0];
File file = new File(path);
// Check if the path is a directory
if (file.isDirectory()) {
System.out.println("It is a directory. Deleting text
files...");
// Get the list of files in the directory
File[] files = file.listFiles();
if (files != null && files.length > 0) {
int deleteCount = 0;
Scanner scanner = new Scanner(System.in);
System.out.print("Are you sure you want to delete all text
files in this directory? (yes/no): ");
String confirmation = scanner.nextLine();
// Proceed if user confirms
if (confirmation.equalsIgnoreCase("yes")) {
for (File f : files) {
// Check if the file is a text file
if (f.isFile() && f.getName().endsWith(".txt")) {
if (f.delete()) {
System.out.println("Deleted: " +
f.getName());
deleteCount++;} else {
System.out.println("Failed to delete: " +
f.getName());
}
}
}
} else {
System.out.println("Delete operation canceled.");
}
// Display the number of files deleted
System.out.println("Total text files deleted: " +
deleteCount);
} else {
System.out.println("The directory is empty or does not
exist.");
}
}
// Check if the path is a file
else if (file.isFile()) {
System.out.println("It is a file. Displaying file details:");
System.out.println("File Name: " + file.getName());
System.out.println("File Path: " + file.getAbsolutePath());
System.out.println("File Size: " + file.length() + " bytes");
System.out.println("Is Readable: " + file.canRead());
System.out.println("Is Writable: " + file.canWrite());
System.out.println("Is Executable: " + file.canExecute());
}
// If neither, display a message
else {
System.out.println("The specified path is neither a file nor a
directory.");
}
}
}
