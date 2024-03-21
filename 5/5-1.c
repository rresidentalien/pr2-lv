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

struct tocka *unesiTocke(struct tocka *tocke, int n) {
    int i;
    
    for (i = 0; i < n; ++i) {
        scanf("%d %d %d", &tocke[i].x, &tocke[i].y, &tocke[i].z);
    }

    return tocke;
}

int unesiTrokute(struct trokut *trokuti, struct tocka *tocke, int m) {
    int i;
    int ind1, ind2, ind3;

    for (i = 0; i < m; ++i) {
        scanf("%d %d %d", &ind1, &ind2, &ind3);
        trokuti[i].t1 = &tocke[ind1];
        trokuti[i].t2 = &tocke[ind2];
        trokuti[i].t3 = &tocke[ind3];
    }
}

float pronadjiNajveciOpseg(struct trokut *t, int m) {
    int i;
    float a, b, c;
    float max = 0.0;
    
    for (i = 0; i < m; ++i) {
        a = sqrt(pow(t[i].t1->x - t[i].t2->x, 2) + pow(t[i].t1->y - t[i].t2->y, 2) + pow(t[i].t1->z - t[i].t2->z, 2));
        b = sqrt(pow(t[i].t2->x - t[i].t3->x, 2) + pow(t[i].t2->y - t[i].t3->y, 2) + pow(t[i].t2->z - t[i].t3->z, 2));
        c = sqrt(pow(t[i].t1->x - t[i].t3->x, 2) + pow(t[i].t1->y - t[i].t3->y, 2) + pow(t[i].t1->z - t[i].t3->z, 2));

        float opseg = a + b + c;

        if (opseg > max) {
            max = opseg;
        }
    }

    return max;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct tocka tocke[100];
    unesiTocke(tocke, n);

    struct trokut trokuti[100];
    unesiTrokute(trokuti, tocke, m);

    float max = pronadjiNajveciOpseg(trokuti, m);

    printf("REZULTATI:\n");
    printf("%.2f\n", max);

    return 0;
}