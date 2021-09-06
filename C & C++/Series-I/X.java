package y;
import java.time.LocalTime;
import java.time.format.DateTimeFormatter;
import java.io.*; 
import java.util.*;
import  java.nio.file.*;
public class Main {
    public static int i = 0;
    public static void main(String[] args) throws Exception{
 			        try { 
            String time = "12:00PM";
          LocalTime localTime = LocalTime.parse(time, DateTimeFormatter.ofPattern("hh:mma", Locale.getDefault())); 
         	String z = localTime.format(DateTimeFormatter.ofPattern("HH:mm:ss"));
         
          System.out.println(z);
        } 
        
        catch (Exception e) { System.err.println("Cannot create directories - " + e); 
            
        } 
    
     }
    }
    

