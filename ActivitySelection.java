import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Comparator;
import java.util.PriorityQueue;

class TimePair{
    int startTime,endTime;
    TimePair(int startTime, int endTime){
        this.startTime = startTime;
        this.endTime = endTime;
    }
}
public class ActivitySelection {
    public static void main(String args[]) throws Exception {

        // [[100, 200], [200, 1300], [1000, 1250], [2000, 3200]]


        System.out.println(new ActivitySelection().reverseBits( 43261596));

        /*
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int T = Integer.parseInt(br.readLine());
        while (T --> 0) {
            int N = Integer.parseInt(br.readLine());
            String line[] = br.readLine().split(" ");
            int startTimes[] = new int[N];
            for(int i=0;i<N;++i)
                startTimes[i] = Integer.parseInt(line[i]);
            line = br.readLine().split(" ");
            int endTimes[] = new int[N];
            for(int i=0;i<N;++i)
                endTimes[i] = Integer.parseInt(line[i]);
            System.out.println(selectActivities(startTimes,endTimes,N));
        }
        */
    }

    public int reverseBits(int n) {
        long N = n;
        long ans = 0;
        while(N!=0){
            ans= ans<<1;
            ans += ((N&1)==1)?1:0;
            N>>=1;
        }
        return (int)ans;
    }

    private static int selectActivities(int[] startTimes, int[] endTimes, int N) {
        PriorityQueue<TimePair> minHeap = new PriorityQueue<>(new Comparator<TimePair>() {
            @Override
            public int compare(TimePair p1, TimePair p2) {
                return (p1.endTime)-(p2.endTime);
            }
        });
        for(int i=0;i<N;++i){
            minHeap.add(new TimePair(startTimes[i],endTimes[i]));
        }
        int ans = 1;
        TimePair tp = minHeap.poll();
        while(!minHeap.isEmpty()){
            TimePair cur = minHeap.poll();
            if(cur.startTime>=tp.endTime){
                ans++;
                tp = cur;
            }

        }
        return ans;
    }

    public int scheduleCourse(int[][] courses) {
        PriorityQueue<TimePair> minheap = new PriorityQueue<>(new Comparator<TimePair>() {
            @Override
            public int compare(TimePair o1, TimePair o2) {
                return o1.endTime-o2.endTime;
            }
        });
        for (int i=0;i<courses.length;++i){

            minheap.add(new TimePair(courses[i][0],courses[i][1]));
        }

        int ans = 1;
        TimePair prev = minheap.poll();
        while (minheap.size()>0){
            TimePair cur = minheap.poll();
            if(prev.endTime<=cur.startTime){
                ans++;
                prev=cur;
            }
        }
        return ans;
    }
}
