//BookTs
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char name[30];
    char classroom[10];
    float mMath; // diem toan
    float mPhysical; // diem ly
    float mChemistry;// diem hoa

}*PSTUDENT, STUDENT;

void ImportInfo(PSTUDENT pStudent, int total);
void PrintInfo(STUDENT student);
void SearchInfo(PSTUDENT pStudent, int total);
void EditInfo(PSTUDENT pStudent, int total);

int main()
{
    PSTUDENT pStudent;
    int totalStudent;
    int sel;
    char c;
    printf("\nBan can quan ly bao nhieu sinh vien: ");
    scanf("%d", &totalStudent);
    // cap phat vung nho de luu thong tin cac sinh vien
    pStudent = (PSTUDENT)malloc(totalStudent*sizeof(STUDENT));
    if(pStudent == NULL)
    {
        printf("\nLoi cap phat bo nho");
        return 0;
    }
    memset(pStudent, NULL, totalStudent*sizeof(STUDENT));
    // Nhap thong tin sinh vien
    ImportInfo(pStudent, totalStudent);

    do
    {
        printf("\n1. Tim kiem thong tin sinh vien");
        printf("\n2. Chinh sua thong tin sinh vien");
        printf("\nBan lua chon: ");
        scanf("%d", &sel);
        switch(sel)
        {
        case 1:
            //Tim kiem sinh vien
            SearchInfo(pStudent, totalStudent);
            break;
        case 2:
            //Chinh sua thong tin sinh vien
            EditInfo(pStudent, totalStudent);
            break;
        }
        printf("\nBan co muon tiep tuc khong:(y/n)?");
        fflush(stdin);
        c = getchar();
    }
    while(c == 'y'|| c == 'Y');
    getch();
    return 0;
}

void ImportInfo(PSTUDENT pStudent, int total)
{
    int i;
    printf("\n==================Nhap thong tin sinh vien====================\n");
    for(i = 0; i < total; i++)
    {
        printf("\nSinh vien [%d]\n", i+1);
        printf("\nTen sinh vien : ");
        fflush(stdin);
        gets(pStudent[i].name);
        printf("\nLop hoc: ");
        //fflush(stdin);
        gets(pStudent[i].classroom);
        printf("\nDiem toan: ");
        scanf("%f", &pStudent[i].mMath);
        printf("\nDiem ly: ");
        scanf("%f", &pStudent[i].mPhysical);
        printf("\nDiem hoa: ");
        scanf("%f", &pStudent[i].mChemistry);
        printf("\n========================================================");
    }
}

// Ham tim kiem thong tin sv
void SearchInfo(PSTUDENT pStudent, int total)
{
    int sel;
    int i;
    float totalMark;
    char name[30];
    char classroom[10];
    printf("\n==================Tim kiem thong tin sinh vien===============");
    printf("\n1. Tim kiem thong tin theo ten sv");
    printf("\n2. Tim kiem thong tin theo lop\n");
    scanf("%d", &sel);
    switch(sel)
    {
    case 1:
        printf("\nNhap ten sinh vien: ");
        fflush(stdin);
        gets(name);
        for(i = 0; i < total; i++)
        {
            if(strcmp(name, pStudent[i].name) == 0)
            {
                //in ra thong tin sinh vien
                PrintInfo(pStudent[i]);
            }
        }
        break;
    case 2:
        printf("\nNhap ten lop: ");
        fflush(stdin);
        gets(classroom);
        for(i = 0; i < total; i++)
        {
            if(strcmp(classroom, pStudent[i].classroom) == 0)
            {
                //in ra thong tin sinh vien
                PrintInfo(pStudent[i]); 
            }
        }
        break;
    } 
}

// Ham sua thong tin sv
void EditInfo(PSTUDENT pStudent, int total)
{
    int i;
    char name[30];
    printf("\n===============Chinh sua thong tin sinh vien================");
    printf("\nNhap ten sinh vien: ");
    fflush(stdin);
    gets(name);

    for(i = 0; i < total; i++)
    {
        if(strcmp(name, pStudent[i].name) == 0)
        {
            printf("\nChinh sua thong tin cua sv: %s", pStudent[i].name);
            printf("\nLop hoc: ");
            fflush(stdin);
            gets(pStudent[i].classroom);
            printf("\nDiem toan: ");
            scanf("%f", &pStudent[i].mMath);
            printf("\nDiem ly: ");
            scanf("%f", &pStudent[i].mPhysical);
            printf("\nDiem hoa: ");
            scanf("%f", &pStudent[i].mChemistry);
        }
    }
}
// Ham hien thi thong tin sv
void PrintInfo(STUDENT student)
{
    printf("\nHo ten\t\t\t\t| Lop\t\t| Toan\t| Ly\t| Hoa\t|");
    printf("\n-------------------------------------------------------------------------------");
    printf("\n%-30s\t| %s\t| %0.1f\t| %0.1f\t| %0.1f\t|",
        student.name, student.classroom, student.mMath, student.mChemistry, student.mChemistry);
    printf("\n-------------------------------------------------------------------------------");
}
