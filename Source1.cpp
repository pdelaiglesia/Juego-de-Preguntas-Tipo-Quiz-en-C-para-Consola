#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<ctime>
#include <cstring>
#define ENTER 13
#define ESC 27

using namespace std;
void gotoxy(int x, int y) {
	HANDLE hCon;
	COORD dwPos;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);


	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hCon, dwPos);
}
void OcultarCursor() {
	HANDLE hCon;
	CONSOLE_CURSOR_INFO cci;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	cci.dwSize = 100;
	cci.bVisible = FALSE;

	SetConsoleCursorInfo(hCon, &cci);
}

class PLAY {
	int time, nplayers, player[6], score[6];
	bool playing, respondido, menu, instrucciones;
	string pregunta, respuesta, respuesta1, respuesta2;
public:
	bool PLAYING() { return playing; }
	bool MENU() { return menu; }
	bool INTRUCCIONES() { return instrucciones; }
	void selectplayers();
	void play();
	void preguntarand();
	void Pintar();
	void Borrar(int x);
	void Comprobarrespuesta();
	void Mostrarscore();
	void Instrucciones();
	void Time();
	void apreg();
};
void PLAY::Time() {
}
void PLAY::Instrucciones() {
	char sn;
	system("cls");
	cout << "HAS JUGADO YA A ESTE JUEGO?" << endl << "1.Si" << endl << "2.No" << endl;
	cin >> sn;
	if (sn == '2') {
		system("cls");
		cout << "INSTRUCCIONES" << endl << endl;
		Sleep(3000);
		instrucciones = true;
	}
	else {
		instrucciones = true;
	}
}

void PLAY::play() {
	int i = 0, j = 0;
	playing = true;
	for (i = 0; i < nplayers; i++) {
		system("cls");
		if (menu == false) {
			preguntarand();
			cout << pregunta << endl;
			cout << respuesta << endl;
			respondido = false;
			cout << "PLAYER" << player[i];
			Pintar();
			gotoxy(100, 2);
			cout << "SCORE: " << score[i];
			while (respondido == false) {
				for (j = 0; j < 30; j++) {
					gotoxy(120 - j, 0);
					printf(" ");
					if (kbhit()) {
						char tecla = getch();
						if (tecla == 'a') {
							Borrar(1);
							Sleep(1000);
							respuesta2 = 'A';
							if (respuesta2 == respuesta1) {
								cout << "BIEN" << endl;
								score[i]++;
								respondido = true;
								Sleep(3000);
							}
							if (respuesta2 != respuesta1) {
								cout << "MAL" << endl;
								cout << respuesta1 << endl;
								respondido = true;
								Sleep(3000);
							}
						}
						if (tecla == 'b') {
							Borrar(2);
							Sleep(1000);
							respuesta2 = 'B';
							if (respuesta2 == respuesta1) {
								cout << "BIEN" << endl;
								score[i]++;
								respondido = true;
								Sleep(3000);
							}
							if (respuesta2 != respuesta1) {
								cout << "MAL" << endl;
								cout << respuesta1 << endl;
								respondido = true;
								Sleep(3000);
							}
						}
						if (tecla == 'c') {
							Borrar(3);
							Sleep(1000);
							respuesta2 = 'C';
							if (respuesta2 == respuesta1) {
								cout << "BIEN" << endl;
								score[i]++;
								respondido = true;
								Sleep(3000);
							}
							if (respuesta2 != respuesta1) {
								cout << "MAL" << endl;
								cout << respuesta1 << endl;
								respondido = true;
								Sleep(3000);
							}
						}
						if (tecla == 'd') {
							Borrar(4);
							Sleep(1000);
							respuesta2 = 'D';
							if (respuesta2 == respuesta1) {
								cout << "BIEN" << endl;
								score[i]++;
								respondido = true;
								Sleep(3000);
							}
							if (respuesta2 != respuesta1) {
								cout << "MAL" << endl;
								cout << respuesta1 << endl;
								respondido = true;
								Sleep(3000);
							}
						}
						if (tecla == ESC) {
							menu = true;
							respondido = true;
							system("cls");
						}
					}
					if (respondido == false) {
						Sleep(1000);
					}
					if (j == 29 && respondido == false) {
						cout << "MAL" << endl;
						cout << respuesta1 << endl;
						respondido = true;
						Sleep(3000);
					}

				}
			}
		}
	}
}
void  PLAY::Comprobarrespuesta() {
	if (respuesta2 == respuesta1) {
		cout << "BIEN" << endl;
		respondido = true;
		Sleep(3000);
	}
	if (respuesta2 != respuesta1) {
		cout << "MAL" << endl;
		cout << respuesta1 << endl;
		respondido = true;
		Sleep(3000);
	}
}
void PLAY::selectplayers() {
	system("cls");
	int i = 0;
	cout << "INTRODUCE NUMERO DE JUGADORES DEL 2 al 6" << endl;
	cin >> nplayers;
	while ((nplayers < 2) || (nplayers > 6)) {
		cout << "INTRODUCE DE NUEVO DEL 2 al 6" << endl;
		cin >> nplayers;
	}
	for (i = 0; i < nplayers; i++) {
		player[i] = i + 1;
		score[i] = 0;
	}

}
void PLAY::preguntarand() {
	string linea;
	string linea1;
	int contador = 0;
	int lineamax = rand() % 21;
	ifstream fichero("PREGUNTAS");

	while (getline(fichero, linea)) {
		if (lineamax == contador) {
			pregunta = linea;
		}

		contador++;
	}
	fichero.close();
	ifstream fichero2("RESPUESTAS");
	contador = 0;
	while (getline(fichero2, linea)) {
		if (lineamax == contador) {
			respuesta = linea;
		}

		contador++;
	}
	fichero2.close();
	contador = 0;
	ifstream fichero3("RESPUESTAS1");;
	contador = 0;
	while (getline(fichero3, linea1)) {
		if (lineamax == contador) {
			respuesta1 = linea1;
		}

		contador++;
	}
	fichero3.close();
}
void PLAY::Mostrarscore() {
	int i = 0;
	for (i = 0; i < nplayers; i++) {
		gotoxy(54, 6 + i);
		cout << "PLAYER " << i + 1 << ": " << score[i];
		Sleep(1);
	}
}
void PLAY::Pintar() {
	gotoxy(26, 4);
	printf("  %c%c%c%c%c%c", 219, 219, 219, 219, 219, 219);
	gotoxy(26, 5);
	printf(" %c%c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219);
	gotoxy(26, 6);
	printf(" %c%c    %c%c", 219, 219, 219, 219);
	gotoxy(26, 7);
	printf(" %c%c    %c%c", 219, 219, 219, 219);
	gotoxy(26, 8);
	printf(" %c%c    %c%c", 219, 219, 219, 219);
	gotoxy(26, 9);
	printf(" %c%c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219);
	gotoxy(26, 10);
	printf(" %c%c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219);
	gotoxy(26, 11);
	printf(" %c%c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219);
	gotoxy(26, 12);
	printf(" %c%c    %c%c", 219, 219, 219, 219);
	gotoxy(26, 13);
	printf("%c%c%c%c  %c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219);

	gotoxy(86, 4);
	printf("%c%c%c%c%c", 219, 219, 219, 219, 219);
	gotoxy(86, 5);
	printf(" %c%c%c%c%c", 219, 219, 219, 219, 219);
	gotoxy(86, 6);
	printf(" %c%c  %c%c", 219, 219, 219, 219);
	gotoxy(86, 7);
	printf(" %c%c   %c%c", 219, 219, 219, 219);
	gotoxy(86, 8);
	printf(" %c%c  %c%c", 219, 219, 219, 219);
	gotoxy(86, 9);
	printf(" %c%c %c%c", 219, 219, 219, 219);
	gotoxy(86, 10);
	printf(" %c%c  %c%c", 219, 219, 219, 219);
	gotoxy(86, 11);
	printf(" %c%c   %c%c", 219, 219, 219, 219);
	gotoxy(86, 12);
	printf(" %c%c%c%c%c%c", 219, 219, 219, 219, 219, 219);
	gotoxy(86, 13);
	printf("%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219);

	gotoxy(26, 18);
	printf("    %c%c%c%c%c", 219, 219, 219, 219, 219);
	gotoxy(26, 19);
	printf("   %c%c%c%c%c%c", 219, 219, 219, 219, 219, 219);
	gotoxy(26, 20);
	printf("  %c%c", 219, 219);
	gotoxy(26, 21);
	printf(" %c%c", 219, 219);
	gotoxy(26, 22);
	printf("%c%c", 219, 219);
	gotoxy(26, 23);
	printf("%c%c", 219, 219);
	gotoxy(26, 24);
	printf(" %c%c", 219, 219);
	gotoxy(26, 25);
	printf("  %c%c", 219, 219);
	gotoxy(26, 26);
	printf("   %c%c%c%c%c%c", 219, 219, 219, 219, 219, 219);
	gotoxy(26, 27);
	printf("    %c%c%c%c%c", 219, 219, 219, 219, 219);

	gotoxy(86, 18);
	printf("%c%c%c%c%c", 219, 219, 219, 219, 219);
	gotoxy(86, 19);
	printf(" %c%c%c%c%c", 219, 219, 219, 219, 219);
	gotoxy(86, 20);
	printf(" %c%c  %c%c", 219, 219, 219, 219);
	gotoxy(86, 21);
	printf(" %c%c   %c%c", 219, 219, 219, 219);
	gotoxy(86, 22);
	printf(" %c%c    %c", 219, 219, 219);
	gotoxy(86, 23);
	printf(" %c%c    %c", 219, 219, 219);
	gotoxy(86, 24);
	printf(" %c%c   %c%c", 219, 219, 219, 219);
	gotoxy(86, 25);
	printf(" %c%c  %c%c", 219, 219, 219, 219);
	gotoxy(86, 26);
	printf(" %c%c%c%c%c", 219, 219, 219, 219, 219);
	gotoxy(86, 27);
	printf("%c%c%c%c%c", 219, 219, 219, 219, 219);

	gotoxy(91, 0);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
}

void PLAY::Borrar(int x) {
	if (x == 1) {
		gotoxy(25, 4);
		printf("            ");
		gotoxy(25, 5);
		printf("            ");
		gotoxy(25, 6);
		printf("            ");
		gotoxy(25, 7);
		printf("            ");
		gotoxy(25, 8);
		printf("            ");
		gotoxy(25, 9);
		printf("            ");
		gotoxy(25, 10);
		printf("            ");
		gotoxy(25, 11);
		printf("            ");
		gotoxy(25, 12);
		printf("            ");
		gotoxy(25, 13);
		printf("            ");
	}
	if (x == 2) {
		gotoxy(85, 4);
		printf("             ");
		gotoxy(85, 5);
		printf("             ");
		gotoxy(85, 6);
		printf("             ");
		gotoxy(85, 7);
		printf("             ");
		gotoxy(85, 8);
		printf("             ");
		gotoxy(85, 9);
		printf("             ");
		gotoxy(85, 10);
		printf("             ");
		gotoxy(85, 11);
		printf("             ");
		gotoxy(85, 12);
		printf("             ");
		gotoxy(85, 13);
		printf("             ");
	}
	if (x == 3) {
		gotoxy(25, 18);
		printf("           ");
		gotoxy(25, 19);
		printf("           ");
		gotoxy(25, 20);
		printf("           ");
		gotoxy(25, 21);
		printf("           ");
		gotoxy(25, 22);
		printf("           ");
		gotoxy(25, 23);
		printf("           ");
		gotoxy(25, 24);
		printf("           ");
		gotoxy(25, 25);
		printf("           ");
		gotoxy(25, 26);
		printf("           ");
		gotoxy(25, 27);
		printf("           ");
	}
	if (x == 4) {
		gotoxy(85, 18);
		printf("           ");
		gotoxy(85, 19);
		printf("           ");
		gotoxy(85, 20);
		printf("           ");
		gotoxy(85, 21);
		printf("           ");
		gotoxy(85, 22);
		printf("           ");
		gotoxy(85, 23);
		printf("           ");
		gotoxy(85, 24);
		printf("           ");
		gotoxy(85, 25);
		printf("           ");
		gotoxy(85, 26);
		printf("           ");
		gotoxy(85, 27);
		printf("           ");
	}
}
class MENU {
public:
	void Pintar(int x);
	void Borrar(int x);
	void Seleccionar(int x);
};

void MENU::Pintar(int x) {
	if (x == 1) {
		gotoxy(41, 3);
		printf(" %c%c%c   %c   %c  %c   %c%c%c  %c   %c  %c       %c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
		gotoxy(41, 4);
		printf("%c   %c  %c   %c  %c  %c     %c  %c    %c     %c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
		gotoxy(41, 5);
		printf("%c   %c  %c   %c  %c  %c     %c %c      %c   %c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
		gotoxy(41, 6);
		printf("%c   %c  %c   %c  %c  %c     %c%c        %c %c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
		gotoxy(41, 7);
		printf("%c   %c  %c   %c  %c  %c     %c          %c", 219, 219, 219, 219, 219, 219, 219, 219);
		gotoxy(41, 8);
		printf("%c   %c  %c   %c  %c  %c     %c%c         %c", 219, 219, 219, 219, 219, 219, 219, 219, 219);
		gotoxy(41, 9);
		printf("%c   %c  %c   %c  %c  %c     %c %c       %c", 219, 219, 219, 219, 219, 219, 219, 219, 219);
		gotoxy(41, 10);
		printf("%c  %c%c  %c   %c  %c  %c     %c  %c     %c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
		gotoxy(41, 11);
		printf(" %c%c%c%c   %c%c%c   %c   %c%c%c  %c   %c   %c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
		gotoxy(41, 12);
		printf("     %c", 219);
	}
	else if (x == 2) {
		gotoxy(14, 19);
		printf("%c%c%c %c   %c%c  %c %c", 219, 219, 219, 219, 219, 219, 219, 219);
		gotoxy(14, 20);
		printf("%c %c %c  %c  %c %c %c", 219, 219, 219, 219, 219, 219, 219);
		gotoxy(14, 21);
		printf("%c%c%c %c  %c  %c  %c", 219, 219, 219, 219, 219, 219, 219);
		gotoxy(14, 22);
		printf("%c   %c  %c%c%c%c  %c", 219, 219, 219, 219, 219, 219, 219);
		gotoxy(14, 23);
		printf("%c   %c%c %c  %c  %c", 219, 219, 219, 219, 219, 219);
		gotoxy(15, 25);
		printf("PRESS  ENTER");
	}
	else if (x == 3) {
		gotoxy(92, 19);
		printf(" %c%c  %c  %c %c %c%c%c", 219, 219, 219, 219, 219, 219, 219, 219);
		gotoxy(92, 20);
		printf("%c  %c %c  %c %c  %c", 219, 219, 219, 219, 219, 219);
		gotoxy(92, 21);
		printf("%c  %c %c  %c %c  %c", 219, 219, 219, 219, 219, 219);
		gotoxy(92, 22);
		printf("%c  %c %c  %c %c  %c", 219, 219, 219, 219, 219, 219);
		gotoxy(92, 23);
		printf(" %c%c   %c%c  %c  %c", 219, 219, 219, 219, 219, 219);
		gotoxy(92, 24);
		printf("   %c", 219);
		gotoxy(92, 25);
		printf("   PRESS ESC");
	}
}

void MENU::Borrar(int x) {
	if (x == 1) {
		gotoxy(40, 3);
		printf("                                        ");
		gotoxy(40, 4);
		printf("                                       ");
		gotoxy(40, 5);
		printf("                                      ");
		gotoxy(40, 6);
		printf("                                     ");
		gotoxy(40, 7);
		printf("                                    ");
		gotoxy(40, 8);
		printf("                                    ");
		gotoxy(40, 9);
		printf("                                   ");
		gotoxy(40, 10);
		printf("                                  ");
		gotoxy(40, 11);
		printf("                                 ");
		gotoxy(40, 12);
		printf("      ");
	}
	else if (x == 2) {
		gotoxy(13, 19);
		printf("                ");
		gotoxy(13, 20);
		printf("                ");
		gotoxy(13, 21);
		printf("                ");
		gotoxy(13, 22);
		printf("                ");
		gotoxy(13, 23);
		printf("                ");
		gotoxy(13, 24);
		printf("                ");
		gotoxy(13, 25);
		printf("                ");
	}
	else if (x == 3) {
		gotoxy(92, 19);
		printf("               ");
		gotoxy(92, 20);
		printf("               ");
		gotoxy(92, 21);
		printf("               ");
		gotoxy(92, 22);
		printf("               ");
		gotoxy(92, 23);
		printf("               ");
		gotoxy(92, 24);
		printf("               ");
		gotoxy(92, 25);
		printf("               ");
	}
}

void PLAY::apreg() {
	string usu, contr, pregunta2;
	playing == true;
	bool correcto, escrito;
	int i = 0;
	system("cls");
	gotoxy(54, 6);
	printf("USUARIO");
	gotoxy(54, 7);
	printf("-------");
	gotoxy(54, 10);
	printf("PASSWORD");
	gotoxy(54, 11);
	printf("---------");
	gotoxy(53, 8);
	printf(" ");
	cin >> usu;
	gotoxy(53, 12);
	printf(" ");
	cin >> contr;
	if (((usu == "ErDeLa") && (contr == "virivich")) || ((usu == "Vichcoin") && (contr == "virivich")) || ((usu == "Martines") && (contr == "virivich"))) {
		gotoxy(53, 14);
		printf("USUARIO Y CONTRASENA CORRECTA");
		Sleep(3000);
		correcto = true;
		system("cls");
		gotoxy(54, 15);
		cout << "NOMBRE: ";
		getline(cin, pregunta2);
		cout << pregunta2;
		ofstream fichero10("PREGUNTAS2");
		fichero10 << pregunta2;
		fichero10.close();
		cout << "DENTRO";
	}
	else {
		gotoxy(53, 14);
		printf("USUARIO O CONTRASENA INCORRECTA");
		Sleep(3000);
		correcto = false;
	}

}

int main() {
	bool game_over;
	OcultarCursor();
	srand(time(NULL));
	MENU M;
	PLAY P;
	M.Pintar(1);
	M.Pintar(2);
	M.Pintar(3);
	while (game_over == false && P.PLAYING() == false) {
		if (kbhit()) {
			char tecla = getch();
			if (tecla == ENTER) {
				M.Borrar(2);
				Sleep(1000);
				P.selectplayers();
				P.Instrucciones();
				while (P.MENU() == false) {
					P.play();
					system("cls");
					P.Mostrarscore();
					Sleep(3000);
				}
				main();
			}
			if (tecla == ESC) {
				M.Borrar(3);
				Sleep(2000);
				return 0;
			}
			if (tecla == 'a') {
				P.apreg();
			}
		}
	}
	system("pause");
	return 0;
}