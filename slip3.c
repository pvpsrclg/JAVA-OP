Q1. Write a program to accept 'n' name of cities from the user and sort them in ascending order.
import java.util.Scanner;
import java.util.Arrays;
public class SortCities {
public static void main(String[] args) {
Scanner scanner = new Scanner(System.in);// Get the number of cities from the user
System.out.print("Enter the number of cities: ");
int n = scanner.nextInt();
scanner.nextLine(); // consume the newline character
// Create an array to store the city names
String[] cities = new String[n];
// Accept the city names from the user
for (int i = 0; i < n; i++) {
System.out.print("Enter city " + (i + 1) + ": ");
cities[i] = scanner.nextLine();
}
// Sort the city names in ascending order
Arrays.sort(cities);
// Display the sorted list of cities
System.out.println("\nCities in ascending order:");
for (String city : cities) {
System.out.println(city);
}
scanner.close();
}
}
Q2) Define a class patient (patient_name, patient_age, patient_oxy_level.patient_HRCT_report)
Create an object of patient. Handle appropriate exception while patient oxygen level less than
95% and HRCT scan report greater than 10, then throw user defined Exception "Patient is
Covid Positive(+) and Need to Hospitalized" otherwise display its information.
class Patient {
String patientName;
int patientAge;
double patientOxyLevel;
double patientHRCTReport;public Patient(String patientName, int patientAge, double
patientOxyLevel, double patientHRCTReport) {
this.patientName = patientName;
this.patientAge = patientAge;
this.patientOxyLevel = patientOxyLevel;
this.patientHRCTReport = patientHRCTReport;
}
public void checkPatientStatus() throws CovidPositiveException {
if (patientOxyLevel < 95 && patientHRCTReport > 10) {
throw new CovidPositiveException("Patient is Covid Positive(+)
and Need to Hospitalized");
} else {
displayPatientInfo();
}
}
public void displayPatientInfo() {
System.out.println("Patient Name: " + patientName);
System.out.println("Patient Age: " + patientAge);
System.out.println("Patient Oxygen Level: " + patientOxyLevel +
"%");
System.out.println("Patient HRCT Report: " + patientHRCTReport);
}
}
class CovidPositiveException extends Exception {
public CovidPositiveException(String message) {
super(message);
}
}
public class Main {
public static void main(String[] args) {
Patient patient = new Patient("John Doe", 45, 93.5, 12.0);
try {
patient.checkPatientStatus();
} catch (CovidPositiveException e) {
System.out.println(e.getMessage());}
}
}
