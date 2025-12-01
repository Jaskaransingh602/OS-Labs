#include <iostream>
using namespace std;
int main() {
    int p, r;
    cin >> p >> r;
    int alloc[p][r], maxm[p][r], need[p][r], avail[r];
    for(int i=0;i<p;i++)
        for(int j=0;j<r;j++)
            cin >> alloc[i][j];

    for(int i=0;i<p;i++)
        for(int j=0;j<r;j++)
            cin >> maxm[i][j];

    for(int j=0;j<r;j++)
        cin >> avail[j];

    for(int i=0;i<p;i++)
        for(int j=0;j<r;j++)
            need[i][j] = maxm[i][j] - alloc[i][j];

    int done = 0, safe[p] = {0}, seq[p], idx = 0;
    while(done < p) {
        bool ok = false;
        for(int i=0;i<p;i++) {
            if(!safe[i]) {
                bool can = true;
                for(int j=0;j<r;j++)
                    if(need[i][j] > avail[j]) can = false;
                if(can) {
                    for(int j=0;j<r;j++)
                        avail[j] += alloc[i][j];
                    safe[i] = 1;
                    seq[idx++] = i;
                    done++;
                    ok = true;
                }
            }
    }
        if(!ok) break;
    }
    if(done == p) {
        cout << "Safe sequence: ";
        for(int i=0;i<p;i++) cout << seq[i] << " ";
    } else {
        cout << "Not safe";
    }
}