void convertInt(char str[], long int a) {
    long int i, rem, count = 0, f;
    f = a;
    while (f != 0) {
        count++;
        f /= 10;
    }
    for (i = 0; i < count; i++) {
        rem = a % 10;
        a = a / 10;
        str[count - (i + 1)] = rem + '0';
    }
    str[count] = '\0';
}
int lineCount() {
    FILE *f = fopen("HIGH_SCORE_DR_IMMUNITY.txt", "r");
    char us[1000];
    int g;
    int count = 0;
    for (; !feof(f);) {
        fscanf(f, "%s %d", us, &g);
        count++;
        if (feof(f)) {
            break;
        }
    }
    return count;
}
void rankScore() {
    int k = lineCount();
    struct playerData *x;
    x = (struct playerData *)malloc((k)* sizeof(struct playerData));
    FILE *a = fopen("HIGH_SCORE_DR_IMMUNITY.txt", "r+");
    for (int i = 0; i<k; i++) {
        fscanf(a, "%s %d", x[i].pl, &x[i].scr);
    }
    fclose(a);
    char z[1000];
    for (int i = 0; i<k; i++) {
        for (int j = i + 1; j < k; j++) {
            if (x[i].scr < x[j].scr) {
                int temp = x[i].scr;
                x[i].scr = x[j].scr;
                x[j].scr = temp;
                strcpy(z, x[i].pl);
                strcpy(x[i].pl, x[j].pl);
                strcpy(x[j].pl, z);
            }
        }
    }
    FILE *n = fopen("HIGH_SCORE_DR_IMMUNITY.txt", "w+");
    for (int i = 0; i < k - 1; i++) {
        fprintf(n, "%s\t", x[i].pl);
        fprintf(n, "%ld\n", x[i].scr);
    }
    free(x);
    fclose(n);
}
void setHigh(char* player, long int scr) {
    int u;
    long int y;
    char c[1000];
    int i;
    FILE *a;
    FILE *g;
    struct playerData plr;
    strcpy(plr.pl, player);
    plr.scr = scr;
    bool newFile = false;
    a = fopen("HIGH_SCORE_DR_IMMUNITY.txt", "r");
    if (a == NULL) {
        a = fopen("HIGH_SCORE_DR_IMMUNITY.txt", "w");
        newFile = true;
        fclose(a);
    }
    else {
        a = fopen("HIGH_SCORE_DR_IMMUNITY.txt", "a");
        fclose(a);
    }
    if (newFile == false && takeScore == true) {
        g = fopen("HIGH_SCORE_DR_IMMUNITY.txt", "a+");
        fprintf(g, " %s %ld \n", plr.pl, plr.scr);
        fclose(g);
    }
    else if (newFile == true && takeScore == true) {
        struct playerData f[10];
        g = fopen("HIGH_SCORE_DR_IMMUNITY.txt", "w+");
        fprintf(g, " %s %ld \n", plr.pl, plr.scr);
        for (i = 0; i < 10; i++) {
            fprintf(g, " %s %ld \n", "Unknown", 0);
        }
        newFile = false;
        fclose(g);
    }
    rankScore();
}
void showHigh() {
    FILE *a;
    fopen_s(&a, "HIGH_SCORE_DR_IMMUNITY.txt", "r");
    if (a == NULL) {
        iSetColor(255, 0, 0);
        iText(350, 500, "SHAME FOR HUMANS", GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(255, 255, 255);
        iText(220, 330, "Still no one has the courage to fight CORONA VIRUS", GLUT_BITMAP_TIMES_ROMAN_24);
    }
    else {
        iText(300, 500, "Player", GLUT_BITMAP_TIMES_ROMAN_24);
        iText(600, 500, "Score", GLUT_BITMAP_TIMES_ROMAN_24);