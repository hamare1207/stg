// 構造体, クラス宣言, プロトタイプ宣言 をここに

struct Window{
	const static int WIDTH		= 640;
	const static int HEIGHT		= 480;
	const static int COLOR_BIT	= 16;
};

class System{
public:
	int mx;
	int my;
	int key[256];
	
	int getKeys();
	int getMouse();
} sy;

class Player{
private:
	int x;
	int y;

	const int s = 4;
	
public:
	Player();
	int player(int key[], int mx, int my);
};
