
package nasa;
public abstract class Receiver implements Signal  {
    private int code ;
    public void setCode(int code){
           this.code=code;
   }
   public int getCode()
   {
       return code;
   }
}
        