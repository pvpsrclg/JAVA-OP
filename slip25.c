Q1) Create a class Student(rollno, name,class, per), to read student information from the
console and display them (Using BufferedReader class)
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
class Student {
// Data members of the Student class
private int rollno;
private String name;
private String studentClass;
private double percentage;
// Constructor to initialize student details
public Student(int rollno, String name, String studentClass, double
percentage) {
this.rollno = rollno;
this.name = name;
this.studentClass = studentClass;
this.percentage = percentage;
}
// Method to display student details
public void display() {
System.out.println("Student Roll No: " + rollno);
System.out.println("Student Name: " + name);
System.out.println("Student Class: " + studentClass);
System.out.println("Student Percentage: " + percentage + "%");
}}
public class StudentDetails {
public static void main(String[] args) throws IOException {
// Create a BufferedReader object to read input from the console
BufferedReader reader = new BufferedReader(new
InputStreamReader(System.in));
// Read student details from the console
System.out.print("Enter Student Roll No: ");
int rollno = Integer.parseInt(reader.readLine());
System.out.print("Enter Student Name: ");
String name = reader.readLine();
System.out.print("Enter Student Class: ");
String studentClass = reader.readLine();
System.out.print("Enter Student Percentage: ");
double percentage = Double.parseDouble(reader.readLine());
// Create a Student object with the provided information
Student student = new Student(rollno, name, studentClass,
percentage);
// Display the student details
System.out.println("\nStudent Information:");
student.display();
}
}
Q2) Create the following GUI screen using appropriate layout manager. Accept the name, class,
hobbies from the user and display the selected options in a textboximport javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
public class UserInfoForm {
public static void main(String[] args) {
// Frame creation
JFrame frame = new JFrame("User Info Form");
frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
frame.setSize(400, 300);
// Create a panel
JPanel panel = new JPanel();
panel.setLayout(new GridLayout(6, 2));
// Your Name
JLabel nameLabel = new JLabel("Your Name");
JTextField nameField = new JTextField();
panel.add(nameLabel);
panel.add(nameField);
// Your Class
JLabel classLabel = new JLabel("Your Class");
ButtonGroup classGroup = new ButtonGroup();
JRadioButton fyRadio = new JRadioButton("FY");
JRadioButton syRadio = new JRadioButton("SY");
JRadioButton tyRadio = new JRadioButton("TY");
classGroup.add(fyRadio);classGroup.add(syRadio);
classGroup.add(tyRadio);
panel.add(classLabel);
JPanel classPanel = new JPanel();
classPanel.setLayout(new GridLayout(3, 1));
classPanel.add(fyRadio);
classPanel.add(syRadio);
classPanel.add(tyRadio);
panel.add(classPanel);
// Your Hobbies
JLabel hobbiesLabel = new JLabel("Your Hobbies");
JCheckBox musicCheckBox = new JCheckBox("Music");
JCheckBox danceCheckBox = new JCheckBox("Dance");
JCheckBox sportsCheckBox = new JCheckBox("Sports");
panel.add(hobbiesLabel);
JPanel hobbiesPanel = new JPanel();
hobbiesPanel.setLayout(new GridLayout(3, 1));
hobbiesPanel.add(musicCheckBox);
hobbiesPanel.add(danceCheckBox);
hobbiesPanel.add(sportsCheckBox);
panel.add(hobbiesPanel);
// Output TextField
JTextField outputField = new JTextField();
outputField.setEditable(false);
// Submit Button
JButton submitButton = new JButton("Submit");
submitButton.addActionListener(new ActionListener() {
@Override
public void actionPerformed(ActionEvent e) {
String name = nameField.getText();
String selectedClass = fyRadio.isSelected() ? "FY" :
syRadio.isSelected() ? "SY" : tyRadio.isSelected() ? "TY" : "";
String hobbies = "";
if (musicCheckBox.isSelected()) hobbies += "Music ";if (danceCheckBox.isSelected()) hobbies += "Dance ";
if (sportsCheckBox.isSelected()) hobbies += "Sports ";
outputField.setText("Name: " + name + " | Class: " +
selectedClass + " | Hobbies: " + hobbies);
}
});
panel.add(submitButton);
panel.add(outputField);
// Add panel to frame and display
frame.add(panel);
frame.setVisible(true);
}
}
