Q1) Define a "Clock" class that does the following;
a. Accept Hours, Minutes and Seconds
b. Check the validity of numbers
c. Set the time to AM/PM mode
Use the necessary constructors and methods to do the above task
public class Clock {private int hours;
private int minutes;
private int seconds;
private String period; // "AM" or "PM"
// Constructor
public Clock(int hours, int minutes, int seconds) {
if (isValidTime(hours, minutes, seconds)) {
this.hours = hours;
this.minutes = minutes;
this.seconds = seconds;
this.period = (hours < 12) ? "AM" : "PM"; // Set AM/PM based
on hours
} else {
throw new IllegalArgumentException("Invalid time provided.");
}
}
// Method to validate time
private boolean isValidTime(int hours, int minutes, int seconds) {
return (hours >= 0 && hours < 24) && (minutes >= 0 && minutes <
60) && (seconds >= 0 && seconds < 60);
}
// Method to set the time
public void setTime(int hours, int minutes, int seconds) {
if (isValidTime(hours, minutes, seconds)) {
this.hours = hours;
this.minutes = minutes;
this.seconds = seconds;
this.period = (hours < 12) ? "AM" : "PM"; // Update AM/PM
based on new hours
} else {
throw new IllegalArgumentException("Invalid time provided.");
}
}
// Method to display the time in AM/PM format
public String displayTime() {int displayHours = (hours % 12 == 0) ? 12 : hours % 12; // Convert
0 to 12 for display
return String.format("%02d:%02d:%02d %s", displayHours, minutes,
seconds, period);
}
// Main method for testing
public static void main(String[] args) {
try {
// Create a Clock instance
Clock clock = new Clock(14, 30, 45); // 2:30:45 PM
System.out.println("Current Time: " + clock.displayTime());
// Set a new time
clock.setTime(10, 15, 20); // 10:15:20 AM
System.out.println("Updated Time: " + clock.displayTime());
} catch (IllegalArgumentException e) {
System.out.println(e.getMessage());
}
}
}
Q2) Write a program to using marker-interface create a class Product (product_id,
product_name, product_cost, product_quantity) default and parameterized constructor. Create
objects of class product and display the contents of each object and Also display the object
count.
// Marker interface
interface ProductMarker {
// This is a marker interface with no methods
}
// Product class implementing the marker interface
class Product implements ProductMarker {
private static int objectCount = 0; // Static variable to count
objects
private int productId;
private String productName;
private double productCost;private int productQuantity;
// Default constructor
public Product() {
this.productId = 0;
this.productName = "Unknown";
this.productCost = 0.0;
this.productQuantity = 0;
objectCount++; // Increment object count
}
// Parameterized constructor
public Product(int productId, String productName, double productCost,
int productQuantity) {
this.productId = productId;
this.productName = productName;
this.productCost = productCost;
this.productQuantity = productQuantity;
objectCount++; // Increment object count
}
// Method to display product details
public void displayProductDetails() {
System.out.printf("Product ID: %d, Product Name: %s, Product Cost:
%.2f, Product Quantity: %d%n",
productId, productName, productCost,
productQuantity);
}
// Static method to get the object count
public static int getObjectCount() {
return objectCount;
}
// Main method for testing
public static void main(String[] args) {
// Creating Product objects
Product product1 = new Product(101, "Laptop", 750.50, 5);
Product product2 = new Product(102, "Smartphone", 300.75, 10);
Product product3 = new Product(); // Using default constructor// Displaying product details
product1.displayProductDetails();
product2.displayProductDetails();
product3.displayProductDetails();
// Displaying the object count
System.out.println("Total Product Objects Created: " +
Product.getObjectCount());
}
}
