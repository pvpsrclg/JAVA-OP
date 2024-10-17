Q1) Write a program to find the cube of given number using functional interface.
// Functional interface
@FunctionalInterface
interface CubeCalculator {
int calculateCube(int number);
}
public class CubeUsingFunctionalInterface {
public static void main(String[] args) {
// Lambda expression to calculate the cube
CubeCalculator cubeCalculator = (number) -> number * number *
number;
// Test the cube calculation
int number = 3; // You can change this value to test with
different numbers
int cube = cubeCalculator.calculateCube(number);
// Display the result
System.out.printf("The cube of %d is: %d%n", number, cube);
}
}Q2) Write a program to create a package name student. Define class StudentInfo with method
to display information about student such as follno, class, and percentage. Create another class
StudentPer with method to find percentage of the student. Accept student details like rollno,
name, class and marks of 6 subject from user
package student;
import java.util.Scanner;
public class StudentPer {
public static void main(String[] args) {
Scanner scanner = new Scanner(System.in);
// Accepting student details from the user
System.out.print("Enter Roll No: ");
int rollNo = scanner.nextInt();
scanner.nextLine(); // Consume newline
System.out.print("Enter Name: ");
String name = scanner.nextLine();
System.out.print("Enter Class: ");
String studentClass = scanner.nextLine();
double totalMarks = 0;
int subjects = 6;
// Accept marks for 6 subjects
for (int i = 1; i <= subjects; i++) {
System.out.print("Enter marks for subject " + i + ": ");
totalMarks += scanner.nextDouble();
}
// Calculate percentage
double percentage = (totalMarks / (subjects * 100)) * 100;
// Create a StudentInfo object
StudentInfo student = new StudentInfo(rollNo, name, studentClass,
percentage);// Display student information
student.displayInfo();
// Close the scanner
scanner.close();
}
}
