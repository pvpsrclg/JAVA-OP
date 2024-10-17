Q1) Write a program to create an abstract class named Shape that contains two integers and an
empty method named printArea(). Provide three classes named Rectangle, Triangle and Circle
such that each one of the classes extends the class Shape. Each one of the classes contain
only the method printArea() that prints the area of the given shape. (use method overriding).
// Abstract class Shape
abstract class Shape {
// Fields to store dimensions
int dim1, dim2;
// Abstract method to be implemented by subclasses
abstract void printArea();
}
// Rectangle class extends Shape
class Rectangle extends Shape {
// Constructor to initialize dimensions of the rectangle
Rectangle(int length, int breadth) {
this.dim1 = length;
this.dim2 = breadth;
}
// Overriding printArea() method to calculate and display the area of
a rectangle
@Overridevoid printArea() {
int area = dim1 * dim2;
System.out.println("Rectangle Area: " + area);
}
}
// Triangle class extends Shape
class Triangle extends Shape {
// Constructor to initialize base and height of the triangle
Triangle(int base, int height) {
this.dim1 = base;
this.dim2 = height;
}
// Overriding printArea() method to calculate and display the area of
a triangle
@Override
void printArea() {
double area = 0.5 * dim1 * dim2;
System.out.println("Triangle Area: " + area);
}
}
// Circle class extends Shape
class Circle extends Shape {
// Constructor to initialize radius of the circle
Circle(int radius) {
this.dim1 = radius; // Only one dimension needed for the circle
}
// Overriding printArea() method to calculate and display the area of
a circle
@Override
void printArea() {
double area = Math.PI * dim1 * dim1; // π * r^2
System.out.println("Circle Area: " + area);
}
}
// Main class to test the shapespublic class ShapeTest {
public static void main(String[] args) {
// Create objects of Rectangle, Triangle, and Circle
Rectangle rect = new Rectangle(10, 5); // length = 10, breadth = 5
Triangle tri = new Triangle(6, 8); // base = 6, height = 8
Circle cir = new Circle(7); // radius = 7
// Call printArea() method for each object
rect.printArea();
tri.printArea();
cir.printArea();
}
}
Q2) Write a program that handles all mouse events and shows the event name at the center of
the Window, red in color when a mouse event is fired. (Use adapter classes).
import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
public class MouseEventDemo extends JFrame {
// Label to display the mouse event name
private JLabel label;
public MouseEventDemo() {
// Set up the frame
setTitle("Mouse Event Demo");
setSize(400, 400);
setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
setLayout(new BorderLayout());
// Create a label to display the mouse event name
label = new JLabel("", SwingConstants.CENTER);
label.setFont(new Font("Arial", Font.BOLD, 20));
label.setForeground(Color.RED);
add(label, BorderLayout.CENTER);// Add a mouse listener using a MouseAdapter class
addMouseListener(new MouseAdapter() {
@Override
public void mouseClicked(MouseEvent e) {
label.setText("Mouse Clicked");
}
@Override
public void mouseEntered(MouseEvent e) {
label.setText("Mouse Entered");
}
@Override
public void mouseExited(MouseEvent e) {
label.setText("Mouse Exited");
}
@Override
public void mousePressed(MouseEvent e) {
label.setText("Mouse Pressed");
}
@Override
public void mouseReleased(MouseEvent e) {
label.setText("Mouse Released");
}
});
addMouseMotionListener(new MouseAdapter() {
@Override
public void mouseMoved(MouseEvent e) {
label.setText("Mouse Moved");
}
@Override
public void mouseDragged(MouseEvent e) {
label.setText("Mouse Dragged");
}
});// Set the frame visible
setVisible(true);
}
public static void main(String[] args) {
// Create the frame and show it
new MouseEventDemo();
}
}
