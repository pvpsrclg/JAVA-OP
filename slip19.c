Q1) Write a program to accept the two dimensional array from user and display sum of its
diagonal elements.
import java.util.Scanner;public class DiagonalSum {
public static void main(String[] args) {
Scanner scanner = new Scanner(System.in);
// Accept the dimensions of the matrix
System.out.print("Enter the number of rows (n): ");
int n = scanner.nextInt();
System.out.print("Enter the number of columns (m): ");
int m = scanner.nextInt();
// Ensure it's a square matrix
if (n != m) {
System.out.println("Please enter a square matrix (same number
of rows and columns).");
return;
}
// Create a two-dimensional array
int[][] matrix = new int[n][m];
// Accept the elements of the matrix from the user
System.out.println("Enter the elements of the matrix:");
for (int i = 0; i < n; i++) {
for (int j = 0; j < m; j++) {
System.out.print("Element [" + i + "][" + j + "]: ");
matrix[i][j] = scanner.nextInt();
}
}
// Calculate the sum of diagonal elements
int primaryDiagonalSum = 0;
int secondaryDiagonalSum = 0;
for (int i = 0; i < n; i++) {
primaryDiagonalSum += matrix[i][i]; // Primary diagonal
secondaryDiagonalSum += matrix[i][n - 1 - i]; // Secondary
diagonal
}// Display the results
System.out.println("Sum of primary diagonal elements: " +
primaryDiagonalSum);
System.out.println("Sum of secondary diagonal elements: " +
secondaryDiagonalSum);
System.out.println("Total sum of diagonal elements: " +
(primaryDiagonalSum + secondaryDiagonalSum));
scanner.close();
}
}
Q2) Write a program which shows the combo box which includes list of T.Y.B.Sc.(Comp. Sci)
subjects. Display the selected subject in a text field.
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
public class SubjectSelector {
public static void main(String[] args) {
// Create the frame
JFrame frame = new JFrame("T.Y.B.Sc. (Comp. Sci) Subjects");
frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
frame.setSize(400, 200);
frame.setLayout(new FlowLayout());
// Create a combo box with subjects
String[] subjects = {
"Operating Systems",
"Database Management Systems",
"Software Engineering",
"Web Technology",
"Computer Networks",
"Data Structures",
"Object-Oriented Programming",
"Theory of Computation"
};JComboBox<String> subjectComboBox = new JComboBox<>(subjects);
frame.add(subjectComboBox);
// Create a text field to display selected subject
JTextField selectedSubjectField = new JTextField(20);
selectedSubjectField.setEditable(false); // Make it read-only
frame.add(selectedSubjectField);
// Add an ActionListener to the combo box
subjectComboBox.addActionListener(new ActionListener() {
@Override
public void actionPerformed(ActionEvent e) {
// Get the selected subject
String selectedSubject = (String)
subjectComboBox.getSelectedItem();
// Display the selected subject in the text field
selectedSubjectField.setText(selectedSubject);
}
});
// Set the frame to be visible
frame.setVisible(true);
}
}
