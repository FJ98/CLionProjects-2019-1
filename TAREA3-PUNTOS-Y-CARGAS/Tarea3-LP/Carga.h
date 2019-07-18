
class Carga{
public:
	int PosX,PosY;
	const float k = 8.99;
	float q;
public:
	Carga(int x, int y, float _q);
	~Carga();
};