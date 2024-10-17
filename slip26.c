Q1) Define a Item class (item_number, item_name, item_price). Define a default and
parameterized constructor. Keep a count of objects created. Create objects using parameterized
constructor and display the object count after each object is created. (Use static member and
method). Also display the contents of each object.
class Item {
// Instance variables
private int item_number;
private String item_name;
private double item_price;
// Static member to keep track of object count
private static int itemCount = 0;
// Default constructor
public Item() {
this.item_number = 0;
this.item_name = "Unknown";
this.item_price = 0.0;
itemCount++; // Increment item count when an object is created
}// Parameterized constructor
public Item(int item_number, String item_name, double item_price) {
this.item_number = item_number;
this.item_name = item_name;
this.item_price = item_price;
itemCount++; // Increment item count when an object is created
}
// Static method to return the count of objects created
public static int getItemCount() {
return itemCount;
}
// Method to display item details
public void displayItem() {
System.out.println("Item Number: " + item_number);
System.out.println("Item Name: " + item_name);
System.out.println("Item Price: $" + item_price);
System.out.println();
}
// Main method to test the functionality
public static void main(String[] args) {
// Creating objects using the parameterized constructor
Item item1 = new Item(101, "Laptop", 1500.99);
System.out.println("Item 1 Details:");
item1.displayItem();
System.out.println("Total Items Created: " + Item.getItemCount());
Item item2 = new Item(102, "Smartphone", 999.99);
System.out.println("Item 2 Details:");
item2.displayItem();
System.out.println("Total Items Created: " + Item.getItemCount());
Item item3 = new Item(103, "Headphones", 199.99);
System.out.println("Item 3 Details:");
item3.displayItem();
System.out.println("Total Items Created: " + Item.getItemCount());
}
}Q2) Define a class 'Donor' to store the below mentioned details of a blood donor. name, age,
address, contactnumber, bloodgroup, date of last donation. Create 'n' objects of this class for all
the regular donors at Pune. Write these objects to a file. Read these objects from the file and
display only those donors' details whose blood group is 'A+ve' and had not donated for the
recent six months.
import java.io.*;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.time.temporal.ChronoUnit;
class Donor implements Serializable {
// Donor class attributes
private String name;
private int age;
private String address;
private String contactNumber;
private String bloodGroup;
private String lastDonationDate;
// Parameterized constructor
public Donor(String name, int age, String address, String
contactNumber, String bloodGroup, String lastDonationDate) {
this.name = name;
this.age = age;
this.address = address;
this.contactNumber = contactNumber;
this.bloodGroup = bloodGroup;
this.lastDonationDate = lastDonationDate;
}
// Method to check if the donor is A+ and hasn't donated in the last 6
months
public boolean isEligibleDonor() {
if (!bloodGroup.equals("A+ve")) {
return false; // Filter only A+ve blood group
}
// Check if last donation date is older than 6 monthsDateTimeFormatter formatter =
DateTimeFormatter.ofPattern("dd/MM/yyyy");
LocalDate lastDonation = LocalDate.parse(lastDonationDate,
formatter);
LocalDate currentDate = LocalDate.now();
long monthsSinceLastDonation =
ChronoUnit.MONTHS.between(lastDonation, currentDate);
return monthsSinceLastDonation >= 6;
}
// Method to display donor details
public void displayDonorDetails() {
System.out.println("Name: " + name);
System.out.println("Age: " + age);
System.out.println("Address: " + address);
System.out.println("Contact Number: " + contactNumber);
System.out.println("Blood Group: " + bloodGroup);
System.out.println("Last Donation Date: " + lastDonationDate);
System.out.println("------------------------------");
}
// Main method to create donor objects and write/read them to/from a
file
public static void main(String[] args) {
Donor[] donors = {
new Donor("John Doe", 35, "Pune", "1234567890", "A+ve",
"01/01/2023"),
new Donor("Jane Smith", 28, "Pune", "0987654321", "B+ve",
"15/03/2023"),
new Donor("Mark Taylor", 42, "Pune", "5556667777", "A+ve",
"05/10/2022"),
new Donor("Emily Clark", 31, "Pune", "8889991111", "O+ve",
"02/02/2023"),
new Donor("Lucas Adams", 29, "Pune", "2223334444", "A+ve",
"10/07/2023")
};
// File where donor objects will be stored
String fileName = "donors.dat";// Write donor objects to the file
try (ObjectOutputStream oos = new ObjectOutputStream(new
FileOutputStream(fileName))) {
for (Donor donor : donors) {
oos.writeObject(donor);
}
System.out.println("Donor objects written to file
successfully.");
} catch (IOException e) {
e.printStackTrace();
}
// Read donor objects from the file and filter based on blood
group and donation date
System.out.println("\nDonors with A+ve blood group who haven't
donated in the last 6 months:");
try (ObjectInputStream ois = new ObjectInputStream(new
FileInputStream(fileName))) {
while (true) {
try {
Donor donor = (Donor) ois.readObject();
if (donor.isEligibleDonor()) {
donor.displayDonorDetails();
}
} catch (EOFException eof) {
break; // End of file reached
}
}
} catch (IOException | ClassNotFoundException e) {
e.printStackTrace();
}
}
}
