Q1) Define a class MyDate(Day, Month, year) with methods to accept and display a
MyDateobject. Accept date as dd,mm,yyyy. Throw user defined exception
"InvalidDateException" if the date is invalid.
import java.util.Scanner;
// Custom exception class for invalid date
class InvalidDateException extends Exception {
public InvalidDateException(String message) {
super(message);
}
}
// Class to represent a date
class MyDate {
private int day;
private int month;
private int year;
// Constructor
public MyDate(int day, int month, int year) throws
InvalidDateException {
if (!isValidDate(day, month, year)) {
throw new InvalidDateException("Invalid Date: " + day + "/" +
month + "/" + year);
}
this.day = day;
this.month = month;
this.year = year;
}
// Method to check if the date is valid
private boolean isValidDate(int day, int month, int year) {
if (month < 1 || month > 12) {
return false;}
if (day < 1 || day > daysInMonth(month, year)) {
return false;
}
return true;
}
// Method to get the number of days in a month, considering leap years
private int daysInMonth(int month, int year) {
switch (month) {
case 1: case 3: case 5: case 7: case 8: case 10: case 12:
return 31;
case 4: case 6: case 9: case 11:
return 30;
case 2:
if (isLeapYear(year)) {
return 29;
} else {
return 28;
}
default:
return 0;
}
}
// Method to check if a year is a leap year
private boolean isLeapYear(int year) {
if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)) {
return true;
}
return false;
}
// Method to display the date
public void displayDate() {
System.out.println("Date: " + day + "/" + month + "/" + year);
}
// Method to accept the date from user input
public static MyDate acceptDate() throws InvalidDateException {Scanner scanner = new Scanner(System.in);
System.out.print("Enter day: ");
int day = scanner.nextInt();
System.out.print("Enter month: ");
int month = scanner.nextInt();
System.out.print("Enter year: ");
int year = scanner.nextInt();
// Return the created MyDate object
return new MyDate(day, month, year);
}
}
// Test class to demonstrate the MyDate class and exception handling
public class TestDate {
public static void main(String[] args) {
try {
// Accept date from user and display
MyDate date = MyDate.acceptDate();
date.displayDate();
} catch (InvalidDateException e) {
// Catch and display the invalid date exception message
System.out.println(e.getMessage());
}
}
}
Q2) Create an employee class(id, name, deptname, salary). Define a default and parameterized
constructor. Use 'this' keyword to initialize instance variables. Keep a count of objects created.
Create objects using parameterized constructor and display the object count after each object is
created. (Use static member and method). Also display the contents of each object.
class Employee {
private int id;
private String name;
private String deptname;
private double salary;
private static int objectCount = 0;
of object count
// Static variable to keep track// Default constructor
public Employee() {
this(0, "Unknown", "Unknown", 0.0); // Default values, using the
parameterized constructor
}
// Parameterized constructor
public Employee(int id, String name, String deptname, double salary) {
this.id = id;
this.name = name;
this.deptname = deptname;
this.salary = salary;
objectCount++;
// Increment object count when an object is
created
}
// Static method to get the current object count
public static int getObjectCount() {
return objectCount;
}
// Method to display the contents of the object
public void display() {
System.out.println("ID: " + this.id);
System.out.println("Name: " + this.name);
System.out.println("Department Name: " + this.deptname);
System.out.println("Salary: " + this.salary);
System.out.println("-----------------------");
}
public static void main(String[] args) {
// Creating first employee object
Employee emp1 = new Employee(101, "John Doe", "IT", 55000.0);
emp1.display();
System.out.println("Number of Employee objects created: " +
Employee.getObjectCount());
// Creating second employee object
Employee emp2 = new Employee(102, "Jane Smith", "HR", 60000.0);emp2.display();
System.out.println("Number of Employee objects created: " +
Employee.getObjectCount());
// Creating third employee object
Employee emp3 = new Employee(103, "David Johnson", "Finance",
75000.0);
emp3.display();
System.out.println("Number of Employee objects created: " +
Employee.getObjectCount());
}
}
