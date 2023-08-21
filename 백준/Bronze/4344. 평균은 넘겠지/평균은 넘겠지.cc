#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
    int c;
    cin >> c;
    for (int i = 0; i < c; i++) {
        int student;
        int* grade;
        int sum = 0;
        cin >> student;
        grade = new int[student];
        for (int j = 0; j < student; j++) {
            cin >> grade[j];
            sum += grade[j];
        }
        double avg = (double)sum / (double)student;
        int count = 0;
        for (int j = 0; j < student; j++) {
            if (avg < (double)grade[j])
                count++;
        }
        printf("%.3f%%\n", (double)(count) / (double)student*100);
        delete[] grade;
    }
    return 0;
}