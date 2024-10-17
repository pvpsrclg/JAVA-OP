Q1) Write a program to accept a number from the user, if number is zero then throw user
defined exception "Number is 0" otherwise check whether no is prime or not (Use static
keyword).
import java.util.Scanner;
// Custom exception classclass ZeroException extends Exception {
public ZeroException(String message) {
super(message);
}
}
public class PrimeChecker {
// Static method to check if a number is prime
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
public static void main(String[] args) {
Scanner scanner = new Scanner(System.in);
System.out.print("Enter a number: ");
int number = scanner.nextInt();
try {
// Check if the number is zero and throw exception
if (number == 0) {
throw new ZeroException("Number is 0");
}
// Check if the number is prime
if (isPrime(number)) {
System.out.println(number + " is a prime number.");
} else {
System.out.println(number + " is not a prime number.");
}
} catch (ZeroException e) {System.out.println(e.getMessage());
} finally {
scanner.close();
}
}
}
Q2) Write a Java program to create a Package "SY" which has a class SYMarks (members -
ComputerTotal, MathsTotal, and ElectronicsTotal). Create another package TY which has a
class TYMarks (members - Theory, Practicals). Create 'n' objects of Student class (having
rollNumber, name, SYMarks and TYMarks). Add the marks of SY and TY computer subjects
and calculate the Grade ('A' for >= 70, 'B' for >= 60 'C' for >= 50, Pass Class for >=40 else
FAIL') and display the result of the student in proper format.
import SY.SYMarks;
import TY.TYMarks;
import java.util.Scanner;
class Student {
private String rollNumber;
private String name;
private SYMarks syMarks;
private TYMarks tyMarks;
public Student(String rollNumber, String name, SYMarks syMarks,
TYMarks tyMarks) {
this.rollNumber = rollNumber;
this.name = name;
this.syMarks = syMarks;
this.tyMarks = tyMarks;
}
public void calculateGrade() {
int totalComputerMarks = syMarks.getComputerTotal() +
tyMarks.getTheory();
String grade;
if (totalComputerMarks >= 70) {
grade = "A";} else if (totalComputerMarks >= 60) {
grade = "B";
} else if (totalComputerMarks >= 50) {
grade = "C";
} else if (totalComputerMarks >= 40) {
grade = "Pass Class";
} else {
grade = "FAIL";
}
displayResult(grade);
}
public void displayResult(String grade) {
System.out.printf("Roll Number: %s, Name: %s, Total Computer
Marks: %d, Grade: %s%n",
rollNumber, name, (syMarks.getComputerTotal() +
tyMarks.getTheory()), grade);
}
public static void main(String[] args) {
Scanner scanner = new Scanner(System.in);
System.out.print("Enter number of students: ");
int n = scanner.nextInt();
scanner.nextLine(); // Consume newline
for (int i = 0; i < n; i++) {
System.out.printf("Enter details for student %d:\n", (i + 1));
System.out.print("Roll Number: ");
String rollNumber = scanner.nextLine();
System.out.print("Name: ");
String name = scanner.nextLine();
System.out.print("SY Computer Marks: ");
int syComputer = scanner.nextInt();
System.out.print("SY Maths Marks: ");int syMaths = scanner.nextInt();
System.out.print("SY Electronics Marks: ");
int syElectronics = scanner.nextInt();
System.out.print("TY Theory Marks: ");
int tyTheory = scanner.nextInt();
System.out.print("TY Practical Marks: ");
int tyPracticals = scanner.nextInt();
scanner.nextLine(); // Consume newline
SYMarks syMarks = new SYMarks(syComputer, syMaths,
syElectronics);
TYMarks tyMarks = new TYMarks(tyTheory, tyPracticals);
Student student = new Student(rollNumber, name, syMarks,
tyMarks);
student.calculateGrade();
}
scanner.close();
}
}
