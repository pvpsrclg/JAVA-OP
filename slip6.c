Q1) Write a program to display the Employee(Empid, Empname, Empdesignation, Empsal)
information using toString().
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
if (isPrime(number)) {System.out.println(number);
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
Q2) Create an abstract class "order" having members id, description. Create two subclasses
"Purchase Order" and "Sales Order" having members customer name and Vendor name
respectively. Definemethods accept and display in all cases. Create 3 objects each of Purchas
Order and Sales Order and accept and display details.
import java.util.Scanner;
// Abstract class Order
abstract class Order {
protected int id;
protected String description;
public Order(int id, String description) {
this.id = id;
this.description = description;
}
// Abstract methods to be implemented by subclassespublic abstract void acceptDetails();
public abstract void displayDetails();
}
// Subclass PurchaseOrder
class PurchaseOrder extends Order {
private String customerName;
public PurchaseOrder(int id, String description) {
super(id, description);
}
@Override
public void acceptDetails() {
Scanner scanner = new Scanner(System.in);
System.out.print("Enter Customer Name for Purchase Order (ID: " +
id + "): ");
customerName = scanner.nextLine();
}
@Override
public void displayDetails() {
System.out.println("Purchase Order ID: " + id);
System.out.println("Description: " + description);
System.out.println("Customer Name: " + customerName);
System.out.println();
}
}
// Subclass SalesOrder
class SalesOrder extends Order {
private String vendorName;
public SalesOrder(int id, String description) {
super(id, description);
}
@Override
public void acceptDetails() {
Scanner scanner = new Scanner(System.in);System.out.print("Enter Vendor Name for Sales Order (ID: " + id +
"): ");
vendorName = scanner.nextLine();
}
@Override
public void displayDetails() {
System.out.println("Sales Order ID: " + id);
System.out.println("Description: " + description);
System.out.println("Vendor Name: " + vendorName);
System.out.println();
}
}
// Main class
public class OrderTest {
public static void main(String[] args) {
// Create arrays for PurchaseOrder and SalesOrder
PurchaseOrder[] purchaseOrders = new PurchaseOrder[3];
SalesOrder[] salesOrders = new SalesOrder[3];
// Accept details for Purchase Orders
for (int i = 0; i < 3; i++) {
purchaseOrders[i] = new PurchaseOrder(i + 1, "Purchase Order
#" + (i + 1));
purchaseOrders[i].acceptDetails();
}
// Accept details for Sales Orders
for (int i = 0; i < 3; i++) {
salesOrders[i] = new SalesOrder(i + 1, "Sales Order #" + (i +
1));
salesOrders[i].acceptDetails();
}
// Display details of Purchase Orders
System.out.println("\nPurchase Orders Details:");
for (PurchaseOrder po : purchaseOrders) {
po.displayDetails();
}// Display details of Sales Orders
System.out.println("Sales Orders Details:");
for (SalesOrder so : salesOrders) {
so.displayDetails();
}
}
}
