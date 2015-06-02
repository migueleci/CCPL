import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Calendar;
import java.util.GregorianCalendar;
import java.util.TimeZone;

public class y3k {

	public static void main(String[] args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String[] entrada;
		entrada=br.readLine().trim().split("\\s+");
		GregorianCalendar calendar;
		int[] fecha=new int[4];;
		for(int i = 0; i < 4; i++) fecha[i]=Integer.parseInt(entrada[i]); 
		while(fecha[0]+fecha[2]+fecha[3]+fecha[1]>0){
			calendar=new GregorianCalendar(fecha[3],fecha[2]-1,fecha[1]);
			calendar.add(calendar.DATE, fecha[0]);
			calendar.setTimeZone(TimeZone.getTimeZone("GMT"));
			System.out.println(calendar.get(Calendar.DAY_OF_MONTH)+" "+(calendar.get(Calendar.MONTH)+1)+" "+calendar.get(Calendar.YEAR));
			entrada=br.readLine().trim().split("\\s+");
			for(int i = 0; i < 4; i++) fecha[i]=Integer.parseInt(entrada[i]);
		}
		br.close();
	}

}
