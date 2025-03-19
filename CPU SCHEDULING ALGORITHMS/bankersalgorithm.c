#include <stdio.h>

struct Process {
    int max[10], allocated[10], need[10], before[10], after[10];
} p[10];

int main() {
    int i, j, k, l, r, n, tot[10], av[10], cn = 0, cz = 0, temp = 0, c = 0;
    
    printf("\n ENTER THE NO. OF PROCESSES: ");
    scanf("%d", &n);
    
    printf("\n ENTER THE NO. OF RESOURCES: ");
    scanf("%d", &r);
    
    for (i = 0; i < n; i++) {
        printf("PROCESS %d \n", i + 1);
        for (j = 0; j < r; j++) {
            printf("MAXIMUM VALUE FOR RESOURCE %d: ", j + 1);
            scanf("%d", &p[i].max[j]);
        }
        
        for (j = 0; j < r; j++) {
            printf("ALLOCATED FROM RESOURCE %d: ", j + 1);
            scanf("%d", &p[i].allocated[j]);
            p[i].need[j] = p[i].max[j] - p[i].allocated[j];
        }
    }
    
    for (i = 0; i < r; i++) {
        printf("ENTER TOTAL VALUE OF RESOURCE %d: ", i + 1);
        scanf("%d", &tot[i]);
    }
    
    for (i = 0; i < r; i++) {
        for (j = 0; j < n; j++) {
            temp += p[j].allocated[i];
        }
        av[i] = tot[i] - temp;
        temp = 0;
    }
    
    printf("\n\t RESOURCES ALLOCATED NEEDED TOTAL AVAILABLE\n");
    for (i = 0; i < n; i++) {
        printf("\n P%d \t", i + 1);
        for (j = 0; j < r; j++)
            printf("%d ", p[i].max[j]);
        printf("\t");
        
        for (j = 0; j < r; j++)
            printf("%d ", p[i].allocated[j]);
        printf("\t");
        
        for (j = 0; j < r; j++)
            printf("%d ", p[i].need[j]);
        printf("\t");
        
        if (i == 0) {
            for (j = 0; j < r; j++)
                printf("%d ", tot[j]);
            printf("\t");
            for (j = 0; j < r; j++)
                printf("%d ", av[j]);
        }
    }
    
    printf("\n\n\t AVAIL BEFORE\t AVAIL AFTER\n");
    for (l = 0; l < n; l++) {
        for (i = 0; i < n; i++) {
            cn = 0;
            cz = 0;
            for (j = 0; j < r; j++) {
                if (p[i].need[j] > av[j]) cn++;
                if (p[i].max[j] == 0) cz++;
            }
            
            if (cn == 0 && cz != r) {
                for (j = 0; j < r; j++) {
                    p[i].before[j] = av[j];
                    p[i].after[j] = av[j] + p[i].allocated[j];
                    av[j] = p[i].after[j];
                    p[i].max[j] = 0;
                }
                
                printf("\n P %d \t", i + 1);
                for (j = 0; j < r; j++)
                    printf("%d ", p[i].before[j]);
                printf("\t");
                
                for (j = 0; j < r; j++)
                    printf("%d ", p[i].after[j]);
                
                c++;
                break;
            }
        }
    }
    
    if (c == n)
        printf("\n THE ABOVE SEQUENCE IS A SAFE SEQUENCE\n");
    else
        printf("\n DEADLOCK OCCURRED\n");
    
    return 0;
}