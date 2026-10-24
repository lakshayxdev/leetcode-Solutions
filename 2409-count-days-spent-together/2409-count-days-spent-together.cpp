class Solution {
public:
int findDate(string date) {
            int month=stoi(date.substr(0,2));
            int day=stoi(date.substr(3,2));
            int days[]={31,28,31,30,31,30,31,31,30,31,30,31};
            for(int i=0; i<month-1; i++) {
                day+=days[i];
            }
            return day;
        }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int a1=findDate(arriveAlice);
        int a2=findDate(leaveAlice);
        int b1=findDate(arriveBob);
        int b2=findDate(leaveBob);
        int start=max(a1,b1);
        int end=min(a2,b2);
        return max(0,end-start+1);

    }
};