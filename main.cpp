#include <math.h>
#include "dxlib/DxLib.h"

#define PI 3.14159

struct Window{
	const static int WIDTH		= 640;
	const static int HEIGHT		= 480;
	const static int COLOR_BIT	= 32;
};

// 構造体, クラス宣言, プロトタイプ宣言 をここに。

class systems{
public:
	int mx;
	int my;
	int key[256];
	
	int getKeys(int key[]);
};

class player{
private:
	int x;
	int y;

	const int s = 4;
	
public:
	player();
	int Player(int key[]);
};

// ここまで

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){

	systems sy;
	
	SetOutApplicationLogValidFlag(false);
	ChangeWindowMode(true);
	SetWindowText("DxLib");
	SetGraphMode(Window::WIDTH, Window::HEIGHT, Window::COLOR_BIT);

	if(DxLib_Init()==-1) return -1;
	SetMouseDispFlag(true);

	// 変数の初期化, 画像のロードなど。

	SetDrawScreen(DX_SCREEN_BACK);

	player pl;

	while(1){
		if(ProcessMessage()!=0)		break;
		sy.getKeys(sy.key);

		if(ClearDrawScreen()!=0)	break;

		pl.Player(sy.key);

		
		if(ScreenFlip()!=0)			break;
		clsDx();
	}

	DxLib_End();
	return 0;
}

int systems::getKeys(int key[]){
    char tmp[256];
    GetHitKeyStateAll(tmp);
    for(int i=0; i<256; i++){
        if(tmp[i]!=0) key[i]++;
        else key[i]=0;
    }
    return 0;
}

player::player(){
	x = 320;
	y = 240;
}

int player::Player(int key[]){
	systems sy;
	
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

	GetMousePoint(&sy.mx, &sy.my);
	
	float angle = atan2f((float)(sy.my-y),(float)(sy.mx-x));

	printfDx("らじあん：%f", angle);

	DrawCircle(x+20*cos(angle), y+20*sin(angle), 2, GetColor(255, 255, 255), true);

	DrawCircle(x, y, 10, GetColor(255, 255, 255), true);

	return 0;
}
