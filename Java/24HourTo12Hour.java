import java.time.*;
import java.time.format.*;

public class Convert{

    public String conv24To12(LocalTime time){
         return time.format(DateTimeFormatter.ofPattern("h:mma"));
       	
    }
        

}
