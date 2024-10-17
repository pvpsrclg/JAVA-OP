Q1) Write a program to create a class Customer(custno,custname,contactnumber,custaddr).
Write a method to search the customer name with given contact number and display the details.
import java.util.ArrayList;
import java.util.Scanner;
class Customer {
private int custNo;
private String custName;
private String contactNumber;
private String custAddr;
// Constructor
public Customer(int custNo, String custName, String contactNumber,
String custAddr) {
this.custNo = custNo;
this.custName = custName;
this.contactNumber = contactNumber;
this.custAddr = custAddr;
}
// Method to display customer details
public void displayDetails() {
System.out.println("Customer Number: " + custNo);
System.out.println("Customer Name: " + custName);
System.out.println("Contact Number: " + contactNumber);
System.out.println("Customer Address: " + custAddr);
}
// Getter for contact number
public String getContactNumber() {
return contactNumber;
}
}
public class CustomerSearch {
public static void main(String[] args) {
// Create a list to store customers
ArrayList<Customer> customerList = new ArrayList<>();// Sample customers
customerList.add(new Customer(1, "Alice Smith", "1234567890", "123
Main St"));
customerList.add(new Customer(2, "Bob Johnson", "9876543210", "456
Elm St"));
customerList.add(new Customer(3, "Charlie Brown", "5551234567",
"789 Oak St"));
// Scanner for user input
Scanner scanner = new Scanner(System.in);
System.out.print("Enter contact number to search: ");
String contactNumber = scanner.nextLine();
// Search for customer by contact number
boolean found = false;
for (Customer customer : customerList) {
if (customer.getContactNumber().equals(contactNumber)) {
customer.displayDetails();
found = true;
break;
}
}
if (!found) {
System.out.println("Customer not found with contact number: "
+ contactNumber);
}
scanner.close();
}
}
