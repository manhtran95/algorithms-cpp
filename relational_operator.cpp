#include <cstdio>
using namespace std;

int main(){
    int N;
    int a, b;
    scanf("%d", &N);
    for (int i=0; i<N; i++){
        scanf("%d %d", &a, &b);
        if (a < b)
            printf("<\n");
        else if (a > b)
            printf(">\n");
        else
        printf("=\n");
    }
}