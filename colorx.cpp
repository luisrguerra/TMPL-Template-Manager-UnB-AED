#include <locale.h>// para o idioma em portguês
#include <iostream>// textos no terminal
//#include <conio.h>
#include <windows.h> //para mudar as cores
using namespace std;


enum cmd_cores {
    /*0*/cor_preto,           /*1*/cor_azul,           /*2*/cor_verde,        /*3*/cor_ciano,
	/*4*/cor_vermelho,        /*5*/cor_magenta,        /*6*/cor_marrom,       /*7*/cor_cinza_claro, 
	/*8*/cor_cinza,           /*9*/cor_azul_claro,     /*10*/cor_verde_claro, /*11*/cor_ciano_claro, 
	/*12*/cor_vermelho_claro, /*13*/cor_magenta_claro, /*14*/cor_amarelo,     /*15*/cor_branco,
	corteste};
	
void cor_texto (cmd_cores iColor){
    HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
    bufferInfo.wAttributes &= 0x00F0;
    SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= iColor);
}

void cor_fundo (cmd_cores iColor){
    HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
    bufferInfo.wAttributes &= 0x000F;
    SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= (iColor << 4));
}

void trocar_cor_padrao_cmd_rgb(int cor,int red,int green,int blue){
    CONSOLE_SCREEN_BUFFER_INFOEX info;
    info.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfoEx(hConsole, &info);
    
    info.ColorTable[cor] = RGB (red,green,blue);
    
	SetConsoleScreenBufferInfoEx(hConsole, &info);
}
void desabilitar_cursor(bool habilitado){
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = habilitado -1; 
    SetConsoleCursorInfo(out, &cursorInfo);
}

void imprimir_texto_colorido(cmd_cores cor,std::string texto){
	cor_texto (cor);
	cor_fundo (cor_preto);
	std::cout << texto;
	cor_texto (cor_cinza_claro);
}
void imprimir_texto_colorido(cmd_cores cor,cmd_cores fundo,std::string texto){
	cor_texto (cor);
	cor_fundo (fundo);
	std::cout << texto;
	cor_texto (cor_cinza_claro);
	cor_fundo (cor_preto);
}

void tamanho_fonte(int tamanho){
	CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
	cfi.dwFontSize.X = 0;  
	cfi.dwFontSize.Y = tamanho;
	std::wcscpy(cfi.FaceName, L"Consolas"); 
	cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

void apagartela(){
	
	///substituto do system cls mais rápido para não dar glitch limpando a tela o tela muito rápido
	HANDLE hOut;
    COORD Position;

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    Position.X = 0;
    Position.Y = 0;
    SetConsoleCursorPosition(hOut, Position);
}



