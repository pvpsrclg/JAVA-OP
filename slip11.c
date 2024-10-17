Q1) Define an interface "Operation" which has method volume().Define a constant PI having a
value 3.142 Create a class cylinder which implements this interface (members - radius, height).
Create one object and calculate the volume.
// Interface Operation
interface Operation {
double PI = 3.142; // Constant for PI
double volume();
// Method to calculate volume
}
// Class Cylinder implementing Operation interface
class Cylinder implements Operation {
private double radius;
private double height;
// Constructor to initialize radius and height
public Cylinder(double radius, double height) {
this.radius = radius;
this.height = height;
}
// Implementing the volume() method
@Override
public double volume() {
return PI * radius * radius * height; // Volume formula: πr²h
}
}
// Main class to test the Cylinder class
public class CylinderVolumeCalculator {public static void main(String[] args) {
// Create a Cylinder object with specific radius and height
Cylinder cylinder = new Cylinder(5.0, 10.0); // Example values:
radius = 5, height = 10
// Calculate and display the volume
double volume = cylinder.volume();
System.out.printf("The volume of the cylinder is: %.2f cubic
units%n", volume);
}
}
Q2) Write a program to accept the username and password from user if username and
password are not same then raise "Invalid Password" with appropriate msg.
import java.util.Scanner;
public class UserAuthentication {
public static void main(String[] args) {
Scanner scanner = new Scanner(System.in);
// Accepting username and password from the user
System.out.print("Enter Username: ");
String username = scanner.nextLine();
System.out.print("Enter Password: ");
String password = scanner.nextLine();
// Checking if username and password are the same
if (!username.equals(password)) {
// Raise "Invalid Password" message
System.out.println("Invalid Password: The username and
password cannot be the same.");
} else {
// Successful message (optional)
System.out.println("Access Granted: Welcome " + username +
"!");
}// Close the scanner
scanner.close();
}
}
