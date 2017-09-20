import java.io.*;
import java.util.ArrayList;

public class Point {
	public double x;
	public double y;
}

public class foo {
	public static void main(String args[]) {
		try {
			BufferedReader in = new BufferedReader(new FileReader(new File("input.txt")));
			String line = null;
			String num = null;
			String[] sxy = null;
			//read num
			num = in.readLine();
			int inum = Integer.parseInt(num.trim());
			ArrayList<Point> Px = new ArrayList<Point>();
			ArrayList<Point> Py = new ArrayList<Point>();
			Px.clear();
			Py.clear();
			for (int i=0; i<inum; i++)
			{
				line = in.readLine();
				sxy = line.split("\\s+");
				Point point = new Point();
				point.x = Integer.parseInt(sxy[0].trim());
				point.y = Integer.parseInt(sxy[1].trim());
				Px.add(point);
			}
			Py.addAll(Px);
			
			in.close();
		}
		catch(Exception ex){
		}
		try {
			BufferedWriter out = new BufferedWriter(new FileWriter(new File("output.txt")));
			String s = "this";

			out.write(s);
		}
		catch(Exception ex){
		}
	}

	private double ClosestPair(Px, Py) {
		
	}
}
