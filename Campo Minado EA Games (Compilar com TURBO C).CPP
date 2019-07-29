/*Alunos: Brayan B, Brayan D.
Ciência da Computação - Primeira fase.
03-07-2009.*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>
char jogo[10][10];
int posx,posy,jogo_val;
void borda(){
	for(int l=0;l<=19;l++){
		gotoxy(27,l+20); printf("%c",186);//esquerda
		gotoxy(48,l+20); printf("%c",186);//direita
	}
	for(int c=0;c<=19;c++){
		gotoxy(c+28,19); printf("%c",205);//cima
		gotoxy(c+28,40); printf("%c",205);//baixo
	}
	gotoxy(27,19); printf("%c",201);//Superior esquerda
	gotoxy(27,40); printf("%c",200);//Inferior esquerda
	gotoxy(48,19); printf("%c",187);//Superior direita
	gotoxy(48,40); printf("%c",188);//Inferior esquerda
}
void borda2(){
	for(int l=0;l<=2;l++){
		gotoxy(30,l+10); printf("%c",186);//esquerda
		gotoxy(47,l+10); printf("%c",186);//direita
	}
	for(int c=0;c<=15;c++){
		gotoxy(c+31,9); printf("%c",205);//cima
		gotoxy(c+31,13); printf("%c",205);//baixo
	}
	gotoxy(30,9); printf("%c",201);//Superior esquerda
	gotoxy(30,13); printf("%c",200);//Inferior esquerda
	gotoxy(47,9); printf("%c",187);//Superior direita
	gotoxy(47,13); printf("%c",188);//Inferior esquerda
}
void apresent_inc(){
	for(int cima=0;cima<=13;cima++){
		gotoxy(cima+25,3);
		delay(50);
		printf("*");
	}
	for(int baixo=0;baixo<=13;baixo++){
		gotoxy(baixo+25,5);
		delay(50);
		printf("*");
	}
	for(int msg=0;msg<=23;msg++){
		gotoxy(msg+1,4);
		delay(50);
		printf(" *Campo Minado*");
	}
	for(int op=0;op<=50;op++){
		gotoxy(op+2,7);
		delay(30);
		printf("_");
	}
	for(op=0;op<=50;op++){
		gotoxy(op+2,18);
		delay(30);
		printf("_");
	}
}
void apresent(){
	for(int cima=0;cima<=13;cima++){
		gotoxy(cima+25,3);
		printf("*");
	}
	for(int baixo=0;baixo<=13;baixo++){
		gotoxy(baixo+25,5);
		printf("*");
	}
	for(int msg=0;msg<=23;msg++){
		gotoxy(msg+1,4);
		printf(" *Campo Minado*");
	}
	for(int op=0;op<=50;op++){
		gotoxy(op+2,7);
		printf("_");
	}
	for(op=0;op<=50;op++){
		gotoxy(op+2,18);
		printf("_");
	}
}
void limpa_matriz(){
	for(int l=0;l<10;l++){
		for(int c=0;c<10;c++){
			jogo[l][c]=' ';
		}
	}
}
void mostra_matriz(){
	for(int l=0;l<10;l++){
		for(int c=0;c<10;c++){
			for(int nl=0;nl<2;nl++){
				for(int nc=0;nc<2;nc++){
						gotoxy(28+nl+l*2,20+nc+c*2);
						if (jogo[l][c] != 'b')
							printf("%c",jogo[l][c]);
				}
			}
		}
	}
}
void randsaida(){
	int saida;
	saida=random(10);
		saida=random(10);
	jogo[9][saida]='X';
}
void randchar(){
	posy=random(10);
	posx=0;
	posy=random(10);
	jogo[posx][posy]='@';
}
char opcao(){
	char dif;
	do{
		clrscr();
		apresent();
		dif=' ';
		gotoxy(2,7);
		printf("\n\n Digite o numero equivalente ao nivel de dificuldade");
		printf("\n\n 1 - Facil\n\n 2 - Medio\n\n 3 - Dificil");
		gotoxy(2,17);
		printf("( )");
		gotoxy(3,17);
		dif = getch();
		if(dif!='1'&&dif!='2'&&dif!='3'){
			clrscr();
			borda2();
			gotoxy(32,11);
			printf("Opçao Invalida");
			getch();
			clrscr();
		}
	}while(dif!='1'&&dif!='2'&&dif!='3');
	clrscr();
	return dif;
}
int contbombas(){
	int qt_bombas=0;
		for(int l=posy-1;l<=posy+1;l++){
			for(int c=posx-1;c<=posx+1;c++){
				if(l>=0&&l<=9&&c>=0&&c<=9){
				 if(jogo[c][l]=='b')
					 qt_bombas++;
				}
			}
		}
	return qt_bombas;
}
void randbombas(){
	int val_rand,rand_l,rand_c;
	switch(opcao()){
			case '1':val_rand=10;break;
			case '2':val_rand=15;break;
			case '3':val_rand=20;break;
	}
	for(int cont_rand=0;cont_rand<val_rand;cont_rand++){
		rand_l=random(10);
		rand_c=random(10);
		if(jogo[rand_l][rand_c]=='b'||jogo[rand_l][rand_c]=='@'||jogo[rand_l][rand_c]=='X')
			cont_rand--;
		else
			jogo[rand_l][rand_c]='b';
	}
}
char tecla(){
	char mov;
	mostra_matriz();
	gotoxy(25,13);
	printf("%d Bomba(as) ao seu redor",contbombas());
	gotoxy(1,1);
	mov = getch();
	jogo[posx][posy]=' ';
	return mov;
}
void movimento(){
	jogo_val=0;
	while(jogo_val==0){
		switch(tecla()){
				case 'w':
				case 'W':if(posy-1>=0&&posy-1<10){
									posy--;
								 }break;
				case 's':
				case 'S':if(posy+1>=0&&posy+1<10){
									 posy++;
									}break;
				case 'd':
				case 'D':if(posx+1>=0&&posx+1<10){
									posx++;
								 }break;
				case 'a':
				case 'A':if(posx-1>=0&&posx-1<10){
									posx--;
								 }break;
		}
		if(jogo[posx][posy]=='b')
			jogo_val=1;
		else if(jogo[posx][posy]=='X')
			jogo_val=2;
		jogo[posx][posy]='@';
	}
	clrscr();
}

main(){
	randomize();
	clrscr();
	char bomba,msg2;
	int val_rand;
	apresent_inc();
	do{
		limpa_matriz();
		randsaida();
		randchar();
		randbombas();
		borda();
		movimento();

		if(jogo_val==1){
			printf("\a");
			gotoxy(34,7);
			printf("Voce perdeu! :(");
		}
		else if(jogo_val==2){
			gotoxy(34,7);
			printf("Voce ganhou!! :D");
		}
		gotoxy(25,9);
		printf("Deseja jogar novamente?(s/n):( )");
		gotoxy(55,9);
		msg2 = getch();
	}while(msg2=='S'||msg2=='s');
	return 0;
}