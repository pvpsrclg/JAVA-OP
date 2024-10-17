Q1) Create a class Sphere, to calculate the volume and surface area of sphere.
(Hint: Surface area=4*3.14(r*r), Volume=(4/3)3.14(r*r*r))
import java.util.Scanner;
public class Sphere {
private double radius;
// Constructor to initialize the radius
public Sphere(double radius) {
this.radius = radius;
}
// Method to calculate surface area
public double surfaceArea() {
return 4 * 3.14 * (radius * radius);
}
// Method to calculate volume
public double volume() {
return (4.0 / 3.0) * 3.14 * (radius * radius * radius);
}
public static void main(String[] args) {
Scanner scanner = new Scanner(System.in);
// Input the radius
System.out.print("Enter the radius of the sphere: ");double radius = scanner.nextDouble();
// Create a Sphere object
Sphere sphere = new Sphere(radius);
// Display surface area and volume
System.out.printf("Surface Area: %.2f%n", sphere.surfaceArea());
System.out.printf("Volume: %.2f%n", sphere.volume());
scanner.close();
}
}
Q2) Design a screen to handle the Mouse Events such as MOUSE_MOVED and
MOUSE_CLICKED and display the position of the Mouse_Click in a TextField
import javax.swing.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
public class MouseEventExample extends JFrame {
private JTextField textField;
public MouseEventExample() {
// Set up the frame
setTitle("Mouse Events Example");
setSize(400, 300);
setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
setLayout(null);
// Using null layout for manual positioning
// Create a text field
textField = new JTextField();
textField.setBounds(50, 200, 300, 30); // Set position and size
add(textField);
// Add mouse listener for handling mouse events
addMouseListener(new MouseAdapter() {
@Override
public void mouseClicked(MouseEvent e) {
// Get mouse click positionint x = e.getX();
int y = e.getY();
// Display position in the text field
textField.setText("Mouse Clicked at: (" + x + ", " + y +
")");
}
});
addMouseMotionListener(new MouseAdapter() {
@Override
public void mouseMoved(MouseEvent e) {
// Optionally display mouse position while moving
int x = e.getX();
int y = e.getY();
textField.setText("Mouse Moved at: (" + x + ", " + y +
")");
}
});
}
public static void main(String[] args) {
// Create and display the frame
MouseEventExample example = new MouseEventExample();
example.setVisible(true);
}
}
