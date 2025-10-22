#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int hang;
int cot;
char map[10][20];
int eat;
char move;

void trongMap(){
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 20; j++) {
            map[i][j] = ' ';
        }
    }
    map[hang][cot] = '0';

    int dauX = 0;
    while(dauX < 5) {
        int rx = rand() % 10;
        int ry = rand() % 20;
        if( (rx == 0 && ry == 0) || map[rx][ry] != ' '){
			continue;
		}
        map[rx][ry] = 'x';
        dauX++;
    }
}

void inMap(){
    for (int j = 0; j < 22; j++) {
        printf("_");
    }
    printf("\n");

    for (int i = 0; i < 10; i++) {
        printf("|");
        for (int j = 0; j < 20; j++) {
            printf("%c", map[i][j]);
        }
        printf("|");
        printf("\n");
    }

    for (int j = 0; j < 22; j++) {
        printf("_");
    }
    printf("\n");

    printf("An duoc: %d/5\n", eat);
}

void door(){
	map[9][19] = 'D';
}

void dichuyen(){
    map[hang][cot] = ' ';
	if(move == 'w' && hang > 0){
		hang--; 
	}
	else if(move == 's' && hang < 9){
		hang++; 
	}
	else if(move == 'a' && cot > 0){
 		cot--;
	}
	else if(move == 'd' && cot < 19){
	    cot++;
	}
	
	if(map[hang][cot] == 'x'){
        eat++;
    }
    
	if(eat == 5){
		door();
	}
	
	map[hang][cot] = '0';
}
int main() {
    srand(time(NULL));
    trongMap();
    inMap();
    printf("Nhap phim (w/a/s/d) de di chuyen: ");

    for(int buoc = 0; buoc < 10000; buoc++){
    	scanf("%c", &move);
    	system("cls");
    	dichuyen();
    	inMap();

    	if(hang == 9 && cot == 19 && eat == 5){
        	
        	break;
    	}
	}

    return 0;
}
