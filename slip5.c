Q1) Write a program for multilevel inheritance such that Country is inherited from Continent
State is inherited from Country. Display the place, State, Country and Continent
// Base class Continent
class Continent {
protected String continentName;
public Continent(String continentName) {
this.continentName = continentName;
}
}
// Intermediate class Country
class Country extends Continent {
protected String countryName;
public Country(String continentName, String countryName) {
super(continentName); // Call the constructor of Continent
this.countryName = countryName;
}}
// Derived class State
class State extends Country {
protected String stateName;
protected String placeName;
public State(String continentName, String countryName, String
stateName, String placeName) {
super(continentName, countryName); // Call the constructor of
Country
this.stateName = stateName;
this.placeName = placeName;
}
// Method to display details
public void displayDetails() {
System.out.println("Place: " + placeName);
System.out.println("State: " + stateName);
System.out.println("Country: " + countryName);
System.out.println("Continent: " + continentName);
}
}
// Main class
public class MultilevelInheritance {
public static void main(String[] args) {
// Create an object of State
State state = new State("Asia", "India", "Maharashtra", "Mumbai");
// Display details
state.displayDetails();
}
}
Q2) Write a menu driven program to perform the following operations on multidimensional array
ic matrices:
Addition
MultiplicationExit
import java.util.Scanner;
public class MatrixOperations {
// Method to input a matrix
public static int[][] inputMatrix(int rows, int cols) {
Scanner scanner = new Scanner(System.in);
int[][] matrix = new int[rows][cols];
System.out.println("Enter the elements of the matrix:");
for (int i = 0; i < rows; i++) {
for (int j = 0; j < cols; j++) {
matrix[i][j] = scanner.nextInt();
}
}
return matrix;
}
// Method to add two matrices
public static int[][] addMatrices(int[][] matrixA, int[][] matrixB) {
int rows = matrixA.length;
int cols = matrixA[0].length;
int[][] result = new int[rows][cols];
for (int i = 0; i < rows; i++) {
for (int j = 0; j < cols; j++) {
result[i][j] = matrixA[i][j] + matrixB[i][j];
}
}
return result;
}
// Method to multiply two matrices
public static int[][] multiplyMatrices(int[][] matrixA, int[][]
matrixB) {
int rowsA = matrixA.length;
int colsA = matrixA[0].length;
int rowsB = matrixB.length;
int colsB = matrixB[0].length;if (colsA != rowsB) {
throw new IllegalArgumentException("Matrices cannot be
multiplied: incompatible dimensions.");
}
int[][] result = new int[rowsA][colsB];
for (int i = 0; i < rowsA; i++) {
for (int j = 0; j < colsB; j++) {
for (int k = 0; k < colsA; k++) {
result[i][j] += matrixA[i][k] * matrixB[k][j];
}
}
}
return result;
}
// Method to print a matrix
public static void printMatrix(int[][] matrix) {
for (int[] row : matrix) {
for (int element : row) {
System.out.print(element + " ");
}
System.out.println();
}
}
public static void main(String[] args) {
Scanner scanner = new Scanner(System.in);
int choice;
do {
System.out.println("\nMenu:");
System.out.println("1. Addition of two matrices");
System.out.println("2. Multiplication of two matrices");
System.out.println("3. Exit");
System.out.print("Enter your choice: ");
choice = scanner.nextInt();switch (choice) {
case 1: {
System.out.print("Enter the number of rows: ");
int rows = scanner.nextInt();
System.out.print("Enter the number of columns: ");
int cols = scanner.nextInt();
System.out.println("Input first matrix:");
int[][] matrixA = inputMatrix(rows, cols);
System.out.println("Input second matrix:");
int[][] matrixB = inputMatrix(rows, cols);
int[][] sum = addMatrices(matrixA, matrixB);
System.out.println("Sum of the matrices:");
printMatrix(sum);
break;
}
case 2: {
System.out.print("Enter the number of rows for first
matrix: ");
int rowsA = scanner.nextInt();
System.out.print("Enter the number of columns for
first matrix: ");
int colsA = scanner.nextInt();
System.out.print("Enter the number of rows for second
matrix: ");
int rowsB = scanner.nextInt();
System.out.print("Enter the number of columns for
second matrix: ");
int colsB = scanner.nextInt();
if (colsA != rowsB) {
System.out.println("Matrices cannot be multiplied:
incompatible dimensions.");
break;
}
System.out.println("Input first matrix:");
int[][] matrixA = inputMatrix(rowsA, colsA);System.out.println("Input second matrix:");
int[][] matrixB = inputMatrix(rowsB, colsB);
int[][] product = multiplyMatrices(matrixA, matrixB);
System.out.println("Product of the matrices:");
printMatrix(product);
break;
}
case 3:
System.out.println("Exiting...");
break;
default:
System.out.println("Invalid choice! Please try
again.");
}
} while (choice != 3);
scanner.close();
}
}
