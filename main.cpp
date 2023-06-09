#include <math.h>
#include "dxlib/DxLib.h"
#include "main.hpp"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){

	// DxLib の初期化, 設定

	SetOutApplicationLogValidFlag(false);	// ログを出力しない
	ChangeWindowMode(true);					// ウィンドウモード

	SetGraphMode(Window::WIDTH, Window::HEIGHT, Window::COLOR_BIT);
	SetMainWindowText("HELLO, HELLO, HELLO");

	if(DxLib_Init()==-1) return -1;

	SetMouseDispFlag(true);					// マウスを常に表示
	SetDrawScreen(DX_SCREEN_BACK);			// 裏画面に描画する

	// 変数の初期化, 画像のロードなど。

	Player pl;

	while(1){
		if(ProcessMessage()!=0)		break;

		sy.getKeys();
		sy.getMouse();

		if(ClearDrawScreen()!=0)	break;
		clsDx();

		printfDx("%f\n", GetFPS());
		pl.player(sy.key, sy.mx, sy.my);

		if(ScreenFlip()!=0)			break;
	}

	DxLib_End();
	return 0;
}

int System::getKeys(){
    char tmp[256];
    GetHitKeyStateAll(tmp);
    for(int i=0; i<256; i++){
        if(tmp[i]!=0) key[i]++;
        else key[i]=0;
    }
    return 0;
}

int System::getMouse(){
	GetMousePoint(&mx, &my);
	return 0;
}

Player::Player(){
	x = 320;
	y = 240;
}

int Player::player(int key[], int mx, int my){
	if( key[KEY_INPUT_W] || key[KEY_INPUT_UP] ){
		if(y>=20) y-=s;
	}
	if( key[KEY_INPUT_A] || key[KEY_INPUT_LEFT] ){
		if(x>=20) x-=s;
	}
	if( key[KEY_INPUT_S] || key[KEY_INPUT_DOWN] ){
		if(y<=460) y+=s;
	}
	if( key[KEY_INPUT_D] || key[KEY_INPUT_RIGHT] ){
		if(x<=620) x+=s;
	}

	float angle = atan2f((float)(my-y),(float)(mx-x));

	printfDx("%f", angle);

	DrawCircle(x+20*cos(angle), y+20*sin(angle), 2, GetColor(255, 255, 255), true);

	DrawCircle(x, y, 10, GetColor(255, 255, 255), true);

	return 0;
}
