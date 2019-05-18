#include "pch.h"
#include "algebra.h"
#include "polyhedra.h"
#include "chessboard.h"
#include <iostream>
#include <istream>
#include <iostream>
#include <istream>


unsigned char* readBMP(const char* filename)
{
	int i;
	FILE* f;
	fopen_s(&f, filename, "rb");
	unsigned char info[54];
	fread(info, sizeof(unsigned char), 54, f); // read the 54-byte header

	// extract image height and width from header
	int width = *(int*)&info[18];
	int height = *(int*)&info[22];
	int size = 3 * width * height;

	unsigned char* data = new unsigned char[size]; // allocate 3 bytes per pixel
	fread(data, sizeof(unsigned char), size, f); // read the rest of the data at once
	fclose(f);

	for (i = 0; i < size; i += 3)
	{
		unsigned char tmp = data[i] / 255;
		data[i] = data[i + 2] / 255;
		data[i + 2] = tmp;
	}

	return data;
}

void createScene()
{
	using namespace Imager;

	Scene scene(Color(0.0, 0.0, 0.0));

	printf("read image \n");
	unsigned char* bg = readBMP("backGround.bmp");

	const double innerSize = 10.00;
	const double xBorderSize = 1.00;
	const double yBorderSize = 1.00;
	const double thickness = 0.20;

	const Color lightSquareColor = Color(0.40, 0.30, 0.5);
	const Color darkSquareColor = Color(0.40, 0.30, 0.5);
	const Color borderColor = Color(0.40, 0.30, 0.5);

	// Create the chess board and add it to the scene.

	ChessBoard* board = new ChessBoard(
		innerSize,
		xBorderSize,
		yBorderSize,
		thickness,
		lightSquareColor,
		darkSquareColor,
		borderColor);

	board->Move(0.0, 0.0, -20.0);

	//board->RotateZ(+11.0);
	//board->RotateX(-62.0);

	scene.AddSolidObject(board);

	Cone* conoIzquierdo2 = new Cone(2.0, 4.0);
	conoIzquierdo2->SetFullMatte(Color(0.6, 0.2, 0.2));
	conoIzquierdo2->Move(-5.0, 4.0, -10.0);
	conoIzquierdo2->RotateX(-90.0);
	scene.AddSolidObject(conoIzquierdo2);


	/*printf("create background \n");
	backGround* backGroundImage = new backGround(bg);
	scene.AddSolidObject(backGroundImage);

	printf("create sphere \n");
	const Vector sphereCenter(0.0, 0.0, -40.0);
	const Vector lightDisplacement(-30.0, +120.0, +50.0);

	Sphere* sphere = new Sphere(sphereCenter, 5.5);
	sphere->SetFullMatte(Color(0.6, 0.2, 0.2));
	scene.AddSolidObject(sphere);
	*/
	//Add a light source to illuminate the objects in the scene; otherwise we won't see anything!
	scene.AddLightSource(LightSource(Vector(-45.0, +25.0, +50.0), Color(0.4, 0.4, 0.1, 1.0)));

	scene.AddLightSource(LightSource(Vector(-100.0, 50.0, 100.0), Color(1.0, 1.0, 1.0, 1.0)));
	scene.AddLightSource(LightSource(Vector(0.0, -20.0, 200.0), Color(1.0, 1.0, 1.0, 1.0)));//Vector(0.0, -20.0, 200.0)
	scene.AddLightSource(LightSource(Vector(100.0, 50.0, 100.0), Color(1.0, 1.0, 1.0, 1.0)));//100.0, 50.0, 100.0)

	printf("saving image \n");
	const char *filename = "image.png";
	scene.SaveImage(filename, 1008, 567, 3.0, 1);
	std::cout << "Wrote " << filename << std::endl;
}

int main()
{
	createScene();
	return 0;
}

