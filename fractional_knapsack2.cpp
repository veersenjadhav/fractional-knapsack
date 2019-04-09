#include <iostream>
#include <stdio.h>

class fractionalKnapsack
{
private:
    int n = 5; // No. of items
    int c[10] = {12, 1, 2, 1, 4}; // Cost
    int v[10] = {4, 2, 2, 1, 10}; // Value
    int W = 15; // Max Weight

public:
    void sampleFill();
};

void fractionalKnapsack::sampleFill()
{
    int cur_w, i, maxi, used[10];
    float tot_v;
 
    for (i = 0; i < n; ++i)
        used[i] = 0;
 
    cur_w = W;
    while (cur_w > 0) 
    {
        maxi = -1;
        for (i = 0; i < n; ++i)
            if ((used[i] == 0) && ((maxi == -1) || ((float)v[i]/c[i] > (float)v[maxi]/c[maxi])))
                maxi = i;
 
        used[maxi] = 1;
        cur_w -= c[maxi];
        tot_v += v[maxi];
        if (cur_w >= 0)
            printf("Added object %d (%d Rs, %dKg) completely in the bag. Space left: %d.\n", maxi + 1, v[maxi], c[maxi], cur_w);
        else 
        {
            printf("Added %d%% (%d Rs, %dKg) of object %d in the bag.\n", (int)((1 + (float)cur_w/c[maxi]) * 100), v[maxi], c[maxi], maxi + 1);
            tot_v -= v[maxi];
            tot_v += (1 + (float)cur_w/c[maxi]) * v[maxi];
        }
    }
 
    printf("Filled the bag with objects worth %.2f Rs.\n", tot_v);
}

int main(int argc, char const *argv[])
{
    fractionalKnapsack fk;
    fk.sampleFill();
    return 0;
}
