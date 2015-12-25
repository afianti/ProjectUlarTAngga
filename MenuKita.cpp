#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <conio.h>

void setcolor (unsigned short color)
{
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon,color);
}

COORD coord={0,0};
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

int Cursor(int BanyakPilihan,int x,int y)
{
    int Pilih=1,ysel=(BanyakPilihan+y-1)-y;
	char cursor;
	gotoxy(x,y); printf("%c",62);

	do
	{
		cursor=getch();
		if(cursor == 80)
		{
			if(Pilih+1 > BanyakPilihan)
			{
				gotoxy(x,y); printf(" ");
				y=y-ysel;
				Pilih=1;
				gotoxy(x,y); printf("%c",62);
			}
			else
			{
				gotoxy(x,y); printf(" ");
				Pilih ++;
				y++;
				gotoxy(x,y); printf("%c",62);
			}
		}

		if(cursor == 72)
		{
			if(Pilih-1 == 0)
			{
				gotoxy(x,y); printf(" ");
				y=y+ysel;
				Pilih=BanyakPilihan;
				gotoxy(x,y); printf("%c",62);
			}
			else
			{
				gotoxy(x,y); printf(" ");
				Pilih --;
				y --;
				gotoxy(x,y); printf("%c",62);
			}
		}
	}while(cursor != 13);

	return Pilih;
}

void MenuUtama()
{
	printf("\n\n\n\n\n\n\n");
	printf("\t   __   __  ___      __   __  ______        _______  _______  __    _  _______  ________ _______\n");
	printf("\t  |  | |  ||   |    |   _   ||    _ |      |       ||   _   ||  |  | ||       ||       ||   _   |\n");
	printf("\t  |  | |  ||   |    |  |_|  ||   | ||      |_     _||  |_|  ||   |_| ||    ___||    ___||  |_|  |\n");
	printf("\t  |  |_|  ||   |    |       ||   |_||_       |   |  |       ||       ||   | __ |   | __ |       |\n");
	printf("\t  |       ||   |___ |       ||    __  |      |   |  |       ||  _    ||   ||  ||   ||  ||       |\n");
	printf("\t  |       ||       ||   _   ||   |  | |      |   |  |   _   || | |   ||   |_| ||   |_| ||   _   |\n");
	printf("\t  |_______||_______||__| |__||___|  |_|      |___|  |__| |__||_|  |__||_______||_______||__| |__|\n"); 
	int PilihanUser;
	gotoxy(52,21); printf("Selamat datang!");
	gotoxy(52,23); printf("Mulai Permainan");
	gotoxy(52,24); printf("Cara Bermain");
	gotoxy(52,25); printf("Keluar");

	PilihanUser=Cursor(3,51,23); //User memilih menu menggunakan tombol keyboard atas atau bawah

	switch(PilihanUser)
	{
		case 1:	system("cls"); exit(1); break;
		case 2:	system("cls"); exit(1); break;
		case 3: system("cls"); exit(1); break;
		case 4: system("cls"); exit(1); break;
		default: system("cls"); printf("Tidak ada dipilihan"); getch(); system("cls"); MenuUtama(); break;
	}
}


int main()
{
    system("MODE 115,50");
    MenuUtama(); //Menampilkan menu utama permainan
    getch();

    return 0;
}
