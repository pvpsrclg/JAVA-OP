Q1) Write a program to implement Border Layout Manager.
import javax.swing.*;
import java.awt.*;
public class BorderLayoutExample {
public static void main(String[] args) {
// Create a JFrame
JFrame frame = new JFrame("Border Layout Example");
frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
frame.setSize(400, 300);frame.setLayout(new BorderLayout());
// Create buttons for each region
JButton buttonNorth = new JButton("North");
JButton buttonSouth = new JButton("South");
JButton buttonEast = new JButton("East");
JButton buttonWest = new JButton("West");
JButton buttonCenter = new JButton("Center");
// Add buttons to the frame using BorderLayout
frame.add(buttonNorth, BorderLayout.NORTH);
frame.add(buttonSouth, BorderLayout.SOUTH);
frame.add(buttonEast, BorderLayout.EAST);
frame.add(buttonWest, BorderLayout.WEST);
frame.add(buttonCenter, BorderLayout.CENTER);
// Set the frame visibility
frame.setVisible(true);
}
}
Q2) Define a class CricketPlayer (name,no_of_innings,no_of_times_notout, totatruns, bat_avg).
Create an array of n player objects. Calculate the batting average for each player using static
method avg(). Define a static sort method which sorts the array on the basis of average. Display
the player details in sorted order.
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;
class CricketPlayer {
String name;
int noOfInnings;
int noOfTimesNotOut;
int totalRuns;
double batAvg;
// Constructorpublic CricketPlayer(String name, int noOfInnings, int
noOfTimesNotOut, int totalRuns) {
this.name = name;
this.noOfInnings = noOfInnings;
this.noOfTimesNotOut = noOfTimesNotOut;
this.totalRuns = totalRuns;
this.batAvg = avg(noOfInnings, noOfTimesNotOut, totalRuns);
}
// Static method to calculate batting average
public static double avg(int noOfInnings, int noOfTimesNotOut, int
totalRuns) {
if (noOfInnings - noOfTimesNotOut == 0) {
return 0; // Avoid division by zero
}
return (double) totalRuns / (noOfInnings - noOfTimesNotOut);
}
// Method to display player details
@Override
public String toString() {
return "Player Name: " + name + ", Innings: " + noOfInnings + ",
Not Out: " + noOfTimesNotOut +
", Total Runs: " + totalRuns + ", Batting Average: " +
batAvg;
}
}
public class CricketPlayerTest {
public static void main(String[] args) {
Scanner scanner = new Scanner(System.in);
System.out.print("Enter number of players: ");
int n = scanner.nextInt();
CricketPlayer[] players = new CricketPlayer[n];
// Input details for each player
for (int i = 0; i < n; i++) {
System.out.println("\nEnter details for Player " + (i + 1) +
":");System.out.print("Name: ");
String name = scanner.next();
System.out.print("Number of Innings: ");
int noOfInnings = scanner.nextInt();
System.out.print("Number of Times Not Out: ");
int noOfTimesNotOut = scanner.nextInt();
System.out.print("Total Runs: ");
int totalRuns = scanner.nextInt();
players[i] = new CricketPlayer(name, noOfInnings,
noOfTimesNotOut, totalRuns);
}
// Sort players based on batting average
Arrays.sort(players, new Comparator<CricketPlayer>() {
@Override
public int compare(CricketPlayer p1, CricketPlayer p2) {
return Double.compare(p2.batAvg, p1.batAvg); // Sort in
descending order
}
});
// Display player details in sorted order
System.out.println("\nPlayer details in sorted order based on
batting average:");
for (CricketPlayer player : players) {
System.out.println(player);
}
scanner.close();
}
}
