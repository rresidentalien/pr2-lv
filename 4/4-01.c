#include <stdio.h>
#include <math.h>

struct tocka {
    int x;
    int y;
    int z;
};

struct trokut {
    struct tocka *t1;
    struct tocka *t2;
    struct tocka *t3;
};

float izracunOpsega(struct trokut t) {
    float a, b, c;
    a = sqrt(pow(t.t1->x - t.t2->x, 2) + pow(t.t1->y - t.t2->y, 2) + pow(t.t1->z - t.t2->z, 2));
    b = sqrt(pow(t.t2->x - t.t3->x, 2) + pow(t.t2->y - t.t3->y, 2) + pow(t.t2->z - t.t3->z, 2));
    c = sqrt(pow(t.t1->x - t.t3->x, 2) + pow(t.t1->y - t.t3->y, 2) + pow(t.t1->z - t.t3->z, 2));

    return a+b+c;
}

int main() {
    int n, m;
    int i;
    int ind1, ind2, ind3;

    scanf("%d %d", &n, &m);

    struct tocka tocke[n];
    struct trokut trokuti[m];
    float max = 0;

    for (i = 0; i < n; ++i) {
        scanf("%d %d %d", &tocke[i].x, &tocke[i].y, &tocke[i].z);
    }
    for (i = 0; i < m; ++i) {
        scanf("%d %d %d", &ind1, &ind2, &ind3);
        trokuti[i].t1 = &tocke[ind1];
        trokuti[i].t2 = &tocke[ind2];
        trokuti[i].t3 = &tocke[ind3];
    }

    for (i = 0; i < m; ++i) {
        float opseg = izracunOpsega(trokuti[i]);
        if (opseg > max) {
                max = opseg;
        }
    }

    printf("REZULTATI:\n");
    printf("%.2f\n", max);

    return 0;
}