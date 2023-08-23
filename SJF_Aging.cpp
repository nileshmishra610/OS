import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

class Process {
    String name;
    int arrivalTime;
    int burstTime;
    int age = 2;

    public Process(String name, int arrivalTime, int burstTime) {
        this.name = name;
        this.arrivalTime = arrivalTime;
        this.burstTime = burstTime;
    }
}

// sort based on arrival time
class ArrivalComparator implements Comparator<Process> {
    public int compare(Process p1, Process p2) {
        if (p1.arrivalTime < p2.arrivalTime)
            return -1;
        else if (p1.arrivalTime > p2.arrivalTime)
            return 1;
        else
            return 0;
    }
}

// sort based on burst time
class BurstComparator implements Comparator<Process> {
    public int compare(Process p1, Process p2) {
        if (p1.burstTime < p2.burstTime)
            return -1;
        else if (p1.burstTime > p2.burstTime)
            return 1;
        else
            return 0;
    }
}

public class SJFWithAging {
    static float averageWaitingTime = 0;
    static float averageTurnaroundTime = 0;
    static ArrayList<Process> processes = new ArrayList<>();
    static ArrayList<Process> temp = new ArrayList<>();
    static int currentTime = 0;

    public static void calculate(Process p) {
        int st = currentTime;
        int ct = st + p.burstTime;
        currentTime = ct;

        int tat = ct - p.arrivalTime;
        int wt = tat - p.burstTime;
        averageWaitingTime += wt;
        averageTurnaroundTime += tat;

        System.out.println(p.name + "\t\t" + p.arrivalTime + "\t\t" + p.burstTime + "\t\t" + st + "\t\t\t" + ct + "\t\t\t" + tat + "\t\t\t" + wt);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the number of processes: ");
        int n = sc.nextInt();

        System.out.print("Enter process Arrival & Burst time :\n");
        for (int i = 0; i < n; i++) {
            System.out.println("For Process " + (i+1) + ":");
            int arrivalTime = sc.nextInt();
            int burstTime = sc.nextInt();

            processes.add(new Process("P" + (i+1), arrivalTime, burstTime));
        }

        // sort based on arrival time
        Collections.sort(processes, new ArrivalComparator());

        System.out.println("PID\t\t" + "Arrival\t\t" + "Burst\t\t" + "Starting\t\t" + "Completion\t\t" + "TurnAround\t\t" + "Waiting");

        // calculate 1st process
        calculate(processes.get(0));
        processes.remove(0);

        while (!processes.isEmpty() || !temp.isEmpty()) {
            // add process which has arrived into temporary list
            if (!processes.isEmpty()) {
                for (int i = 0; i < processes.size(); i++) {
                    if (processes.get(i).arrivalTime <= currentTime) {
                        temp.add(processes.get(i));
                        processes.remove(processes.get(i));
                    }
                }
            }

            // sort based on burst time
            Collections.sort(temp, new BurstComparator());

            for (int i = 0; i < temp.size(); i++) {
                if (temp.get(i).age == 0) {
                    calculate(temp.get(i));
                    temp.remove(temp.get(i));
                } else {
                    temp.get(i).age--;
                }
            }

            if (!temp.isEmpty()) {
                calculate(temp.get(0));
                for (Process p : temp) {
                    p.age++;
                }
                temp.remove(0);
            }
        }

        averageWaitingTime /= n;
        averageTurnaroundTime /= n;

        System.out.println("Average Waiting Time : " + averageWaitingTime);
        System.out.println("Average Turn Around Time : " + averageTurnaroundTime);
    }
}
