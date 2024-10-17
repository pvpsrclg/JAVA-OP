Q1) Write a Program to illustrate multilevel Inheritance such that country is inherited from
continent. State is inherited from country. Display the place, state, country and continent.
// Base class
class Continent {
protected String continentName;
public Continent(String continentName) {
this.continentName = continentName;
}
public String getContinentName() {
return continentName;}
}
// Derived class from Continent
class Country extends Continent {
protected String countryName;
public Country(String continentName, String countryName) {
super(continentName); // Call to the constructor of the base class
this.countryName = countryName;
}
public String getCountryName() {
return countryName;
}
}
// Further derived class from Country
class State extends Country {
private String stateName;
private String placeName;
public State(String continentName, String countryName, String
stateName, String placeName) {
super(continentName, countryName); // Call to the constructor of
the Country class
this.stateName = stateName;
this.placeName = placeName;
}
public void displayDetails() {
System.out.println("Place: " + placeName);
System.out.println("State: " + stateName);
System.out.println("Country: " + getCountryName());
System.out.println("Continent: " + getContinentName());
}
}
public class MultilevelInheritanceDemo {
public static void main(String[] args) {// Creating an object of the State class
State state = new State("Asia", "India", "Maharashtra", "Mumbai");
// Displaying the details
state.displayDetails();
}
}
Q2) Write a package for Operation, which has two classes, Addition and Maximum. Addition has
two methods add () and subtract (), which are used to add two integers and subtract two, float
values respectively. Maximum has a method max () to display the maximum of two integers
import java.util.Scanner;
// Class for Addition
class Addition {
// Method to add two integers
public int add(int a, int b) {
return a + b;
}
// Method to subtract two float values
public float subtract(float a, float b) {
return a - b;
}
}
// Class for Maximum
class Maximum {
// Method to find the maximum of two integers
public int max(int a, int b) {
return (a > b) ? a : b;
}
}
// Test class to demonstrate functionality
public class TestOperation {
public static void main(String[] args) {
Scanner scanner = new Scanner(System.in);// Create objects of Addition and Maximum classes
Addition addition = new Addition();
Maximum maximum = new Maximum();
// Input two integers for addition and maximum
System.out.print("Enter first integer for addition: ");
int num1 = scanner.nextInt();
System.out.print("Enter second integer for addition: ");
int num2 = scanner.nextInt();
// Demonstrate addition
int sum = addition.add(num1, num2);
System.out.println("Sum of " + num1 + " and " + num2 + ": " +
sum);
// Input two float values for subtraction
System.out.print("Enter first float for subtraction: ");
float float1 = scanner.nextFloat();
System.out.print("Enter second float for subtraction: ");
float float2 = scanner.nextFloat();
// Demonstrate subtraction
float difference = addition.subtract(float1, float2);
System.out.println("Difference between " + float1 + " and " +
float2 + ": " + difference);
// Input two integers for maximum calculation
System.out.print("Enter first integer for maximum: ");
int maxNum1 = scanner.nextInt();
System.out.print("Enter second integer for maximum: ");
int maxNum2 = scanner.nextInt();
// Demonstrate maximum
int max = maximum.max(maxNum1, maxNum2);
System.out.println("Maximum of " + maxNum1 + " and " + maxNum2 +
": " + max);
// Close scanner
scanner.close();}
}
