
package nasa;
import exceptions.NoInformationFoundException;
public class Transceiver  extends Receiver {
    @Override
    public void checkSignal() throws NoInformationFoundException {
        int code = getCode();
    
        while (code%2 == 0){
            code/=2;
        }
        while (code%3 == 0){
            code/=3;
        }
        while (code%5 == 0){
            code/=5;
        }
        if(code!= 1 )
        {
            throw new NoInformationFoundException ("Invalid Signal Received! Please Discard it.");
        }
        else 
            throw new NoInformationFoundException("Signal Received with Information!");
    
}
}
