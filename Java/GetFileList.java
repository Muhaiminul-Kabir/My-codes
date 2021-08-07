import java.io.File;
import java.io.IOException;
public class GetFileList{
    public static void main x(){
        File x = new File("src/t");
        String[] y = x.list();
        for(int i = 0; i < y.length;i++){
            System.out.println(y[i]);
        }
    }
}
