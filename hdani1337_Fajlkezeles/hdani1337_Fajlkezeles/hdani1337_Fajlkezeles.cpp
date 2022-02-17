#include "stdio.h"
#include <iostream>
#pragma warning (disable : 4996)

void szoveg_iras() {
    FILE* file;
    char c;
    int i;
    file = fopen("szoveg.txt", "wt");
    if (file != NULL)
    {
        for (i = 0; i < 10; i++)
        {
            c = 65 + i;
            fputc(c, file);
        }
        fclose(file);
    }
    else printf("Nem sikerült beolvasni a fájlt! :c");
}

void szoveg_olvasas() {
    FILE* file;
    char c;
    int i;
    file = fopen("szoveg.txt", "r");
    if (file != NULL)
    {
        c = getc(file);
        printf("\x1B[36mElsõ betû az állományból: %c\033[0m\n\n", c);
        

        while ((c = getc(file)) != EOF)//vagy !feof(file)
        {         
            printf("\x1B[35mCiklussal olvasott: % c\n\033[0m", c);
        }

        printf("\n");

        fseek(file, -3, SEEK_END);
        c = getc(file);
        printf("\x1B[32mFájl vége elõtti 3. betû az állományból: %c\033[0m\n\n", c);

        fseek(file, -2, SEEK_CUR);
        c = getc(file);
        printf("\x1B[33mElõzõ betû elõtti 2. betû az állományból: %c\033[0m\n\n", c);

        fseek(file, 3, SEEK_SET);
        c = getc(file);
        printf("\x1B[96mElsõ betû utáni 3. betû az állományból: %c\033[0m\n\n", c);

        fclose(file);
    }
    else printf("Nem sikerült beolvasni a fájlt! :c");
}

void szoveg_formazott() {
    FILE* file;
    char c;
    int i = 0;
    file = fopen("szoveg.txt", "a");
    if (file != NULL)
    {
        fseek(file, 12, SEEK_SET);
        for (int j = 0; j < 10; j++)
        {
            c = 65 + i;
            /*fprintf(file, "\n%d. %c", i + 1, c);*/
            fscanf(file, "%d. %c", &i, &c);
            printf("\nfscanf: %d %c", i+1, c);
            i++;
        }

        fclose(file);
    }
    else printf("Nem sikerült beolvasni a fájlt! :c");
}

void binaris() {
    FILE* f_szoveg, *f_binaris;
    int a = 12345;
    
    f_szoveg = fopen("f_szoveg.txt","w");
    fputc('1', f_szoveg);
    fputc('2', f_szoveg);
    fputc('3', f_szoveg);
    fputc('4', f_szoveg);
    fputc('5', f_szoveg);
    fclose(f_szoveg);

    f_binaris = fopen("f_binaris.bin", "wb");
    fwrite(&a,sizeof(int),1,f_binaris);
    fclose(f_binaris);

    a = -1;

    f_binaris = fopen("f_binaris.bin", "rb");
    fread(&a, sizeof(int), 1, f_binaris);
    fclose(f_binaris);
    printf("Olvasott a: %d\n", a);

    int v[4] = {9, 8, 7, 6};
    f_binaris = fopen("f_binaris.bin", "wb");
    fwrite(&v, sizeof(int), 4, f_binaris);
    fclose(f_binaris);

    int w[4];
    f_binaris = fopen("f_binaris.bin", "rb");
    fread(&w, sizeof(int), 4, f_binaris);
    fclose(f_binaris);
    for (int i = 0; i < 4; i++)
    {
        printf("w[%d]: %d\n", i, w[i]);
    }

    struct person {
        char c;
        int d;
        double e[3];
    };

    person workers[1024];
    f_binaris = fopen("f_binaris.bin", "wb");
    fwrite(&workers, sizeof(person), 1024, f_binaris);
    fclose(f_binaris);

}

void feladat() {
    //billentyûzetrõl adatok, fájlba beírni, bekérés vége legyen a q
    FILE* file;
    file = fopen("karakterek.txt", "w");
    if (file != NULL)
    {
        char answer = ' ';
        while (answer != 'q') { 
            printf("Adjon meg egy karaktert (kilépés q-val): ");
            scanf(" %c", &answer);
            if(answer != 'q') fputc(answer, file);
        }   
        fclose(file);
    }
    else printf("Nem sikerült beolvasni a fájlt! :c");
}

int main()
{
    setlocale(LC_ALL, "");
    //szoveg_iras();
    //szoveg_olvasas();
    //szoveg_formazott();
    //binaris();
    feladat();
}