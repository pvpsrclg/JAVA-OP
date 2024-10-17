Q1) Write a program to accept a file name from command prompt, if the file exits then display
number of words and lines in that file.
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
public class FileWordLineCounter {
public static void main(String[] args) {
// Check if a file name is provided
if (args.length == 0) {
System.out.println("Please provide a file name as a command
line argument.");
return;
}
// Get the file name from command line argument
String fileName = args[0];
File file = new File(fileName);
// Check if the file exists
if (!file.exists()) {
System.out.println("The file '" + fileName + "' does not
exist.");
return;
}
// Initialize counters for lines and words
int lineCount = 0;int wordCount = 0;
// Read the file and count lines and words
try (BufferedReader br = new BufferedReader(new FileReader(file)))
{
String line;
while ((line = br.readLine()) != null) {
lineCount++; // Increment line count
// Split the line into words and count them
String[] words = line.trim().split("\\s+"); // Split by
whitespace
wordCount += words.length; // Increment word count
}
} catch (IOException e) {
System.out.println("An error occurred while reading the file:
" + e.getMessage());
return;
}
// Display the results
System.out.println("File: " + fileName);
System.out.println("Number of lines: " + lineCount);
System.out.println("Number of words: " + wordCount);
}
}
Q2) Write a program to display the system date and time in various formats shown below:
Current date is: 31/08/2021
Current date is : 08-31-2021
Current date is: Tuesday August 31 2021
Current date and time is: Fri August 31 15:25:59 IST 2021
Current date and time is: 31/08/21 15:25:59 PM +0530
import java.time.LocalDateTime;
import java.time.ZoneId;
import java.time.format.DateTimeFormatter;import java.time.format.FormatStyle;
import java.util.Date;
public class DateTimeFormats {
public static void main(String[] args) {
// Get the current date and time
LocalDateTime now = LocalDateTime.now();
// Define formatters for different formats
DateTimeFormatter format1 =
DateTimeFormatter.ofPattern("dd/MM/yyyy");
DateTimeFormatter format2 =
DateTimeFormatter.ofPattern("MM-dd-yyyy");
DateTimeFormatter format3 = DateTimeFormatter.ofPattern("EEEE MMMM
dd yyyy");
DateTimeFormatter format4 = DateTimeFormatter.ofPattern("EEE MMMM
dd HH:mm:ss zzz yyyy");
DateTimeFormatter format5 = DateTimeFormatter.ofPattern("dd/MM/yy
hh:mm:ss a Z");
// Display the current date and time in various formats
System.out.println("Current date is: " + now.format(format1));
System.out.println("Current date is: " + now.format(format2));
System.out.println("Current date is: " + now.format(format3));
System.out.println("Current date and time is: " +
now.format(format4));
System.out.println("Current date and time is: " +
now.format(format5));
}
}
