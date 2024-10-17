Q1) Write a program to print an array after changing the rows and columns of a given
two-dimensional array.
import java.util.Scanner;
public class TransposeMatrix {
public static void main(String[] args) {
Scanner scanner = new Scanner(System.in);
// Input the dimensions of the matrix
System.out.print("Enter the number of rows: ");
int rows = scanner.nextInt();
System.out.print("Enter the number of columns: ");
int cols = scanner.nextInt();
// Create a 2D array
int[][] matrix = new int[rows][cols];
// Input the elements of the matrix
System.out.println("Enter the elements of the matrix:");
for (int i = 0; i < rows; i++) {
for (int j = 0; j < cols; j++) {
matrix[i][j] = scanner.nextInt();
}
}
// Transpose the matrix (swap rows with columns)
int[][] transpose = new int[cols][rows];
for (int i = 0; i < rows; i++) {
for (int j = 0; j < cols; j++) {
transpose[j][i] = matrix[i][j];
}
}// Display the transposed matrix
System.out.println("Transposed matrix:");
for (int i = 0; i < cols; i++) {
for (int j = 0; j < rows; j++) {
System.out.print(transpose[i][j] + " ");
}
System.out.println();
}
scanner.close();
}
}
Q2) Write a program to design a screen using Awt that will take a user name and password. It
the user name and Jpassword are not same, raise an Exception with appropriate message User
can have 3 login chances only. Use clear button to clear the TextFields.
import java.awt.*;
import java.awt.event.*;
class LoginScreenAWT extends Frame implements ActionListener {
Label userLabel, passLabel, messageLabel;
TextField userField;
TextField passField;
Button loginButton, clearButton;
int attempts = 0;
public LoginScreenAWT() {
setTitle("Login Screen");
setSize(400, 200);
setLayout(new GridLayout(4, 2));
userLabel = new Label("Username:");
passLabel = new Label("Password:");
userField = new TextField();
passField = new TextField();
passField.setEchoChar('*');loginButton = new Button("Login");
clearButton = new Button("Clear");
messageLabel = new Label();
add(userLabel);
add(userField);
add(passLabel);
add(passField);
add(loginButton);
add(clearButton);
add(messageLabel);
loginButton.addActionListener(this);
clearButton.addActionListener(this);
setVisible(true);
addWindowListener(new WindowAdapter() {
public void windowClosing(WindowEvent we) {
dispose();
}
});
}
public void actionPerformed(ActionEvent e) {
if (e.getSource() == clearButton) {
userField.setText("");
passField.setText("");
messageLabel.setText("");
} else if (e.getSource() == loginButton) {
String username = userField.getText();
String password = passField.getText();
if (attempts < 3) {
if (username.equals(password)) {
messageLabel.setText("Login Successful!");
} else {
attempts++;messageLabel.setText("Incorrect Login. Attempts left:
" + (3 - attempts));
if (attempts >= 3) {
messageLabel.setText("Login Failed. No more
attempts.");
loginButton.setEnabled(false);
}
}
}
}
}
public static void main(String[] args) {
new LoginScreenAWT();
}
}
