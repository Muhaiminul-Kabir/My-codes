import java.time.LocalTime;
import java.io.*; 
import java.util.TimerTask;
import  java.nio.file.*;
public class Main {
    
    public static void main(String[] args) throws Exception{
        Path path = Paths.get("src/StudyBase/To_do/../Settings/../Progress/../Study");
        try {
            Files.createDirectories(path);
        } catch (IOException e) { 
            System.err.println("Cannot create directories - " + e); 
            
        } 
    
     }
    }
    

