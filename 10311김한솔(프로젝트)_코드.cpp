#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<windows.h>
#include<algorithm>
//http://designerhanee.creatorlink.net/
#include<conio.h>
#define eh 1046.502 // 1 도
#define fp 1158.931 // 2 레
#define al 1318.510 // 3 미
#define vk 1396.913 // 4 파
#define thf 1567.982 // 5 솔
#define fk 1760.000 // 6 라
#define tl 1975.533 // 7 시
#define shvdmseh 2122.222 // 8 높은도
//0 무음, 딜레이용
int color; //콘솔창 글씨의 색깔을 지정하는 변수
char NodeNote[4096]; //악보
char LED[7][145]={ // 프로그램시작할떄 움직이는 전관팡, 2차원배열
		"::::::::: :::::::::::     :::     ::::    :::  ::::::::             :::::::: ::::::::::: :::::::::   ::::::::  :::        :::::::::: :::::::::  ",
		":+:    :+:    :+:       :+: :+:   :+:+:   :+: :+:    :+:           :+:    :+:    :+:     :+:    :+: :+:    :+: :+:        :+:        :+:    :+: ",
		"+:+    +:+    +:+      +:+   +:+  :+:+:+  +:+ +:+    +:+           +:+           +:+     +:+    +:+ +:+        +:+        +:+        +:+    +:+ ",
		"+#++:++#+     +#+     +#++:++#++: +#+ +:+ +#+ +#+    +:+           +#+           +#+     +#++:++#:  +#+        +#+        +#++:++#   +#++:++#:  ",
		"+#+           +#+     +#+     +#+ +#+  +#+#+# +#+    +#+           +#+           +#+     +#+    +#+ +#+        +#+        +#+        +#+    +#+ ",
		"#+#           #+#     #+#     #+# #+#   #+#+# #+#    #+#           #+#    #+#    #+#     #+#    #+# #+#    #+# #+#        #+#        #+#    #+# ",
		"###       ########### ###     ### ###    ####  ########  ########## ######## ########### ###    ###  ########  ########## ########## ###    ### ",
	};
void gotoxy(int x,int y) { /// 커서이동함수
    COORD pos= {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
void Play() { // 음악재생
	color=1+rand()%14; // 글씨의 색깔을 랜덤으로 지정
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), color); // 글씨의 색깔 변경
    int i=0,b=0; // i=>악보의 순서, b=>반복문탈출을 검사하는 변수
    puts("Playing");
    while (1) {
        if(NodeNote[i]=='A') { //처음 main함수 시작할때 memset함수로 배열의 처음부터 3000번째 개체까지 A로 초기화를 했기때문에 음을 입력하지않으면 재생하지 않는다.
            break;
        }
        if(i>=4096) { // i가 배열의 총 인덱스보다 크다면 반복문 탈출
            break;
        }
        switch (NodeNote[i]) {
        case '0' :
			Sleep(100);
			break;
		case '1' :
			if(NodeNote[i+1]=='1' && NodeNote[i+2]=='1'){ // 같은 개체가 연속 3번이면 음을 길게 출력
				Beep(eh,600);
				i++;
				i++;
				break;
			}
            Beep(eh, 300);
            break;
        case '2' :
			if(NodeNote[i+1]=='2' && NodeNote[i+2]=='2'){
				Beep(fp,600);
				i++;
				i++;
				break;
			}
			Beep(fp, 300);
            break;
        case '3' :
			if(NodeNote[i+1]=='3' && NodeNote[i+2]=='3'){
				Beep(al,600);
				i++;
				i++;
				break;
			}
			Beep(al, 300);
            break;
        case '4' :
			if(NodeNote[i+1]=='4' && NodeNote[i+2]=='4'){
				Beep(vk,600);
				i++;
				i++;
				break;
			}
			Beep(vk, 300);
            break;
        case '5' :
            if(NodeNote[i+1]=='5' && NodeNote[i+2]=='5'){
				Beep(thf,600);
				i++;
				i++;
				break;
			}
			Beep(thf, 300);
            break;
        case '6' :
            if(NodeNote[i+1]=='6' && NodeNote[i+2]=='6'){
				Beep(fk,600);
				i++;
				i++;
				break;
			}
			Beep(fk, 300);
            break;
        case '7' :
            if(NodeNote[i+1]=='7' && NodeNote[i+2]=='7'){
				Beep(tl,600);
				i++;
				i++;
				break;
			}
			Beep(tl, 300);
            break;
		case '8' :
			if(NodeNote[i+1]=='8' && NodeNote[i+2]=='8'){
				Beep(shvdmseh,600);
				i++;
				i++;
				break;
			}
			Beep(shvdmseh,300);
			break;
        default :
            Beep(1234, 500);
        }
        i++;
		if(kbhit()) {
            system("cls");
            break;
        }
    }
}
void InsertNode() {
	memset (NodeNote,'A',3000); // 전역배열 초기화
	color=1+rand()%14;  // 글씨의 색깔을 초기화
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), color); // 글씨의 색깔을 변경
    int i=0;
    char Node;
    puts("InsertNode");
    puts("######  ###  ##  #######  #######  ####### ########");
    puts("  ##    #### ##  ##       ##       ##   ##    ##   ");
    puts("  ##    ## ####  #######  #######  #######    ##   ");
    puts("  ##    ##  ###       ##  ##       ##  ##     ##   ");
    puts("######  ##   ##  #######  #######  ##   ##    ##   ");
    while (1) {
        Node=getch();
        int b=0;
        switch (Node) {
        case '0' :
			NodeNote[i]=Node;
			break;
		case '1' :
            NodeNote[i]=Node;
            Beep(eh, 300);
            break;
        case '2' :
            NodeNote[i]=Node;
            Beep(fp, 300);
            break;
        case '3' :
            NodeNote[i]=Node;
            Beep(al, 300);
            break;
        case '4' :
            NodeNote[i]=Node;
            Beep(vk, 300);
            break;
        case '5' :
            NodeNote[i]=Node;
            Beep(thf, 300);
            break;
        case '6' :
            NodeNote[i]=Node;
            Beep(fk, 300);
            break;
        case '7' :
            NodeNote[i]=Node;
            Beep(tl, 300);
            break;
		case '8' :
            NodeNote[i]=Node;
            Beep(shvdmseh, 300);
            break;
        case '`' :
            b=1;
            break;
        default :
            Beep(1234, 500);
        }
        i++;
        if(b==1) {
            break;
        }
    }
}

void TestMode() {
    char TestNode;
    color=1+rand()%14;  // 글씨의 색깔을 초기화
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), color);  // 글씨의 색깔을 변경
	puts("TestMode");
    puts(" :::::::::::      ::::::::::      ::::::::    :::::::::::");
    puts("     :+:          :+:            :+:    :+:       :+: ");
    puts("    +:+          +:+            +:+              :+: ");
    puts("   +#+          +#++:++#       +#++:++#++       +:+ ");
    puts("  +#+          +#+                   +#+       +:+ ");
    puts(" #+#          #+#            #+#    #+#       #:# ");
    puts("###          ##########      #########       ### ");
    while (1) {
        TestNode=getch();
        int b=0;
        switch (TestNode) {
        case '0' :
			Sleep(300);
			break;
		case '1' :
            Beep(eh, 300);
            break;
        case '2' :
            Beep(fp, 300);
            break;
        case '3' :
            Beep(al, 300);
            break;
        case '4' :
            Beep(vk, 300);
            break;
        case '5' :
            Beep(thf, 300);
            break;
        case '6' :
            Beep(fk, 300);
            break;
        case '7' :
            Beep(tl, 300);
            break;
		case '8' :
			Beep(shvdmseh,300);
			break;
        case '`' :
            b=1;
            break;
        default :
            Beep(1234, 500);
        }
        if(b==1) {
            break;
        }
    }
}
int main() {
	system("mode con:cols=400 lines=35");
	system("title Piano");
    char select;
	int i=0,k=0,B=0;
	memset (NodeNote,'A',3000);
	srand(time(NULL));
    for(;; i++) {
		color=1+rand()%14;
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), color);
		for(;k<145;k++){
			puts(&LED[0][k]);
			puts(&LED[1][k]);
			puts(&LED[2][k]);
			puts(&LED[3][k]);
			puts(&LED[4][k]);
			puts(&LED[5][k]);
			puts(&LED[6][k]);
			Sleep(20);
			system("cls");
			if(kbhit()) {
				B=1;
				break;
			}
		}
		if(B==1){
			break;
		}
		if(k==145){
                k=-1;
			}
		if(i==7) {
            i=-1;
        }
        system("cls");
    }
    while (1) {
        system("cls");
        color=1+rand()%14;
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), color);
		puts("");
        puts("******  **  *****  ***    **  ******");
        puts("**   ** ** **   ** ****   ** **    **");
        puts("******  ** ******* ** **  ** **    **");
        puts("**      ** **   ** **  ** ** **    **");
        puts("**      ** **   ** **   ****  ******");
        printf("\n\n\n");
        color=1+rand()%14;
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), color);
        puts("This is Piano");
        puts("Mode");
        puts(" 1 : Play");
        puts(" 2 : Insert Node");
        puts(" 3 : Test Mode");
        puts(" 4 : Exit");
        select=getch();
        switch(select) {
        case '1':
            system("cls");
            Play();
            break;
        case '2':
            system("cls");
            InsertNode();
            break;
        case '3':
            system("cls");
            TestMode();
            break;
        case '4':
		puts("");
		SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 1357);
        return 0;
        default :
            printf("\n\n Another Color~");
			Sleep(30);
        }
    }
    system("pause");
    return 0;
}
