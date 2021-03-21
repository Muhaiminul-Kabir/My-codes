
package nasa;
import exceptions.NoInformationFoundException;
import java.util.Scanner;

public class Nasa {
  
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        Transceiver obj = new Transceiver();
        int code = input.nextInt();
        Decoder obj2 = new Decoder();
        obj.setCode(code);
     try {
         obj.checkSignal();
         obj2.decodeSignal(obj.getCode());
         
     }catch(NoInformationFoundException e){
         System.out.println(e.getMessage());
     }    
     
    }
    
}
