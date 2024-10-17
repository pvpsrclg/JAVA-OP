Q1) Write a program to read the First Name and Last Name of a person, his weight and height
using command line arguments. Calculate the BMI Index which is defined as the individual's
body mass divided by the square of their height.
(Hint: BMI = Wts. In kgs / (ht)²)
public class BMICalculator {
public static void main(String[] args) {
if (args.length != 4) {
System.out.println("Usage: java BMICalculator <First Name>
<Last Name> <Weight (in kg)> <Height (in meters)>");
return;
}
// Read command line arguments
String firstName = args[0];
String lastName = args[1];
double weight = Double.parseDouble(args[2]);
// weight in
kilograms
double height = Double.parseDouble(args[3]);
// height in meters
// Calculate BMI
double bmi = weight / (height * height);
// Display result
System.out.println("Person: " + firstName + " " + lastName);
System.out.println("Weight: " + weight + " kg");
System.out.println("Height: " + height + " meters");
System.out.println("BMI Index: " + String.format("%.2f", bmi));
// Optional: Provide a basic interpretation of the BMI
if (bmi < 18.5) {
System.out.println("Underweight");
} else if (bmi >= 18.5 && bmi < 24.9) {
System.out.println("Normal weight");
} else if (bmi >= 25 && bmi < 29.9) {
System.out.println("Overweight");
} else {System.out.println("Obese");
}
}
}
Q2) Define a class CricketPlayer (name,no_of_innings,no_of_times_notout, totatruns, bat_avg).
Create an array of n player objects Calculate the batting average for each player using static
method avg(). Define a static sort method which sorts the array on the basis of average. Display
the player details in sorted order.
import java.util.Arrays;
import java.util.Scanner;
class CricketPlayer {
String name;
int noOfInnings;
int noOfTimesNotOut;
int totalRuns;
double batAvg;
// Constructor to initialize the player data
public CricketPlayer(String name, int noOfInnings, int
noOfTimesNotOut, int totalRuns) {
this.name = name;
this.noOfInnings = noOfInnings;
this.noOfTimesNotOut = noOfTimesNotOut;
this.totalRuns = totalRuns;
this.batAvg = 0.0;
}
// Static method to calculate the batting average
public static void avg(CricketPlayer player) {
if (player.noOfInnings - player.noOfTimesNotOut > 0) {
player.batAvg = (double) player.totalRuns /
(player.noOfInnings - player.noOfTimesNotOut);
} else {
player.batAvg = player.totalRuns;
average is total runs
}
// if no dismissals,}
// Static method to sort players based on batting average
public static void sort(CricketPlayer[] players) {
Arrays.sort(players, (p1, p2) -> Double.compare(p2.batAvg,
p1.batAvg)); // Sorting in descending order of average
}
// Method to display player details
public void display() {
System.out.println("Name: " + name);
System.out.println("Innings: " + noOfInnings);
System.out.println("Not Out: " + noOfTimesNotOut);
System.out.println("Total Runs: " + totalRuns);
System.out.println("Batting Average: " + String.format("%.2f",
batAvg));
System.out.println();
}
}
public class CricketPlayerTest {
public static void main(String[] args) {
Scanner scanner = new Scanner(System.in);
// Get the number of players
System.out.print("Enter the number of players: ");
int n = scanner.nextInt();
scanner.nextLine();
// consume newline
CricketPlayer[] players = new CricketPlayer[n];
// Input player details
for (int i = 0; i < n; i++) {
System.out.println("Enter details for player " + (i + 1));
System.out.print("Name: ");
String name = scanner.nextLine();
System.out.print("Number of innings: ");
int noOfInnings = scanner.nextInt();
System.out.print("Number of times not out: ");
int noOfTimesNotOut = scanner.nextInt();System.out.print("Total runs: ");
int totalRuns = scanner.nextInt();
scanner.nextLine();
// consume newline
players[i] = new CricketPlayer(name, noOfInnings,
noOfTimesNotOut, totalRuns);
}
// Calculate the batting average for each player
for (CricketPlayer player : players) {
CricketPlayer.avg(player);
}
// Sort players by their batting average
CricketPlayer.sort(players);
// Display the sorted player details
System.out.println("\nPlayer details in sorted order (based on
batting average):");
for (CricketPlayer player : players) {
player.display();
}
scanner.close();
}
}
