Q1) Write a Program to print all Prime numbers in an array of 'n' elements. (use command line
arguments)
public class PrimeNumbers {
public static void main(String[] args) {
if (args.length == 0) {
System.out.println("Please provide numbers as command line
arguments.");
return;
}
System.out.println("Prime numbers in the array:");
for (String arg : args) {
try {
int number = Integer.parseInt(arg);
if (isPrime(number)) {
System.out.println(number);
}
} catch (NumberFormatException e) {
System.out.println(arg + " is not a valid number.");
}
}
}
// Method to check if a number is prime
public static boolean isPrime(int number) {
if (number <= 1) {
return false; // 0 and 1 are not prime numbers
}
for (int i = 2; i <= Math.sqrt(number); i++) {
if (number % i == 0) {
return false; // Found a divisor, not prime
}
}
return true; // No divisors found, it is prime
}
}

Q2) Define an abstract class Staff with protected members id and name. Define a
parameterized constructor. Define one subclass OfficeStaff with member department. Create n
objects of OfficeStaff and display all details.
import java.util.Scanner;
// Abstract class Staff
abstract class Staff {
protected int id;
protected String name;
// Parameterized constructor
public Staff(int id, String name) {
this.id = id;
this.name = name;
}
// Abstract method to display details
public abstract void displayDetails();
}
// Subclass OfficeStaff
class OfficeStaff extends Staff {
private String department;
// Parameterized constructor
public OfficeStaff(int id, String name, String department) {
super(id, name); // Call the constructor of the abstract class
this.department = department;
}
// Implementation of the abstract method
@Override
public void displayDetails() {
System.out.println("ID: " + id);
System.out.println("Name: " + name);
System.out.println("Department: " + department);
System.out.println();
}}
// Main class
public class StaffTest {
public static void main(String[] args) {
Scanner scanner = new Scanner(System.in);
System.out.print("Enter the number of Office Staff: ");
int n = scanner.nextInt();
scanner.nextLine(); // Consume the newline character
OfficeStaff[] staffArray = new OfficeStaff[n];
// Input details for each OfficeStaff
for (int i = 0; i < n; i++) {
System.out.println("Enter details for Office Staff " + (i +
1));
System.out.print("ID: ");
int id = scanner.nextInt();
scanner.nextLine(); // Consume the newline character
System.out.print("Name: ");
String name = scanner.nextLine();
System.out.print("Department: ");
String department = scanner.nextLine();
staffArray[i] = new OfficeStaff(id, name, department);
}
// Display details of all Office Staff
System.out.println("\nDetails of Office Staff:");
for (OfficeStaff staff : staffArray) {
staff.displayDetails();
}
scanner.close();
}
}




