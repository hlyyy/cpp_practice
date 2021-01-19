#include<iostream>
#include<cstdio>
using namespace std;

int main() {
    int x, y, z, sum = 0;

    cout << "方法一:" << endl;
    for (x = 0; x <= 20; x++) {
        for (y = 0; y <= 33; y++) {
            for (z = 0; z <= 300; z++) {
                sum++;
                if (z % 3 == 0 && x + y + z == 100 && 5 * x + 3 * y + z / 3 == 100) {
                    printf("方法一：第%d次找到，母鸡%d只，公鸡%d只，小鸡%d只\n", sum, x, y, z);
                }
            }
        }
    }
    printf("共执行了%d次\n", sum);

    sum = 0;
    printf("\n方法二:\n");
    for (x = 0; x <= 20; x++) {
        for (y = 0; y <= 33; y++) {
            sum++;
            z = 100 - x - y;
            if (z % 3 == 0 && 5 * x + 3 * y + z / 3 == 100) {
                    printf("第%d次找到，母鸡%d只，公鸡%d只，小鸡%d只\n", sum, x, y, z);
            }
        }
    }
    printf("共执行了%d次\n", sum);

    sum = 0;
    printf("\n方法三：\n");
    for (x = 0; x <= 12; x = x + 4) {
        y = (100 - 7 * x) / 4;
        z = 100 - x - y;
        sum++;
        printf("第%d次找到，母鸡%d只，公鸡%d只，小鸡%d只\n", sum, x, y, z);
    }
    printf("共执行了%d次\n", sum);

    return 0;
}