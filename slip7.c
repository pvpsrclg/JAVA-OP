Q1) Design a class for Bank. Bank Class should support following operations;
a. Deposit a certain amount into an account
b. Withdraw a certain amount from an account
c. Return a Balance value specifying the amount with details
import java.util.Scanner;
// BankAccount class
class BankAccount {
private String accountHolder;
private double balance;
public BankAccount(String accountHolder) {
this.accountHolder = accountHolder;
this.balance = 0.0; // Initial balance is zero
}
public void deposit(double amount) {
if (amount > 0) {
balance += amount;
System.out.println("Deposited: $" + amount);
} else {
System.out.println("Deposit amount must be positive.");
}
}public void withdraw(double amount) {
if (amount > 0 && amount <= balance) {
balance -= amount;
System.out.println("Withdrawn: $" + amount);
} else if (amount > balance) {
System.out.println("Insufficient funds for withdrawal.");
} else {
System.out.println("Withdrawal amount must be positive.");
}
}
public double getBalance() {
return balance;
}
public String getAccountHolder() {
return accountHolder;
}
}
// Bank class
public class Bank {
public static void main(String[] args) {
Scanner scanner = new Scanner(System.in);
// Create a bank account
System.out.print("Enter account holder name: ");
String accountHolderName = scanner.nextLine();
BankAccount account = new BankAccount(accountHolderName);
while (true) {
System.out.println("\nBank Operations Menu:");
System.out.println("1. Deposit");
System.out.println("2. Withdraw");
System.out.println("3. Check Balance");
System.out.println("4. Exit");
System.out.print("Select an option: ");
int choice = scanner.nextInt();switch (choice) {
case 1:
System.out.print("Enter amount to deposit: $");
double depositAmount = scanner.nextDouble();
account.deposit(depositAmount);
break;
case 2:
System.out.print("Enter amount to withdraw: $");
double withdrawAmount = scanner.nextDouble();
account.withdraw(withdrawAmount);
break;
case 3:
System.out.println("Current Balance for " +
account.getAccountHolder() + ": $" + account.getBalance());
break;
case 4:
System.out.println("Exiting...");
scanner.close();
return;
default:
System.out.println("Invalid option. Please try
again.");
}
}
}
}
Q2) Write a program to accept a text file from user and display the contents of a file in reverse
order and change its case.
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;public class ReverseCaseFileContent {
public static void main(String[] args) {
Scanner scanner = new Scanner(System.in);
System.out.print("Enter the path of the text file: ");
String filePath = scanner.nextLine();
StringBuilder content = new StringBuilder();
// Reading the file and storing the content
try (BufferedReader br = new BufferedReader(new
FileReader(filePath))) {
String line;
while ((line = br.readLine()) != null) {
content.append(line).append("\n");
}
} catch (IOException e) {
System.out.println("Error reading the file: " +
e.getMessage());
return;
}
// Displaying the content in reverse order with changed case
String reversedContent = content.reverse().toString();
String result = changeCase(reversedContent);
System.out.println("Contents in reverse order and changed
case:\n");
System.out.println(result);
scanner.close();
}
// Method to change the case of each character
private static String changeCase(String str) {
StringBuilder changedCase = new StringBuilder();
for (char c : str.toCharArray()) {
if (Character.isLowerCase(c)) {
changedCase.append(Character.toUpperCase(c));
} else if (Character.isUpperCase(c)) {
changedCase.append(Character.toLowerCase(c));} else {
changedCase.append(c); // Non-alphabetic characters remain
unchanged
}
}
return changedCase.toString();
}
}
