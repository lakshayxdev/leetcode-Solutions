
class Solution {
public:
    int getDay(string date) {
        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));

        int days[] = {31, 28, 31, 30, 31, 30,
                      31, 31, 30, 31, 30, 31};

        for (int i = 0; i < month - 1; i++) {
            day += days[i];
        }

        return day;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        int a1 = getDay(arriveAlice);
        int a2 = getDay(leaveAlice);
        int b1 = getDay(arriveBob);
        int b2 = getDay(leaveBob);

        int start = max(a1, b1);
        int end = min(a2, b2);

        return max(0, end - start + 1);
    }
};
