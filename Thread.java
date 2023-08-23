import java.io.*;
import java.util.*;

class A implements Runnable {
	public void run(){
		for(int i=0;i<10;i++){
			System.out.println("Therad A-:"+i);
		}
	}
}
	

class thread1 extends A implements Runnable{

	public static void main(String[]args){
		
		thread1 a=new thread1();
		Thread t=new Thread(thread1());
		a.start();
		
	}
}