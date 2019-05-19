#include "pch.h"
#include "algebra.h"
#include "polyhedra.h"
#include "chessboard.h"
#include <iostream>
#include <istream>
#include <iostream>
#include <istream>

void createScene()
{
	using namespace Imager;

	Scene scene(Color(0.0, 0.0, 0.0));

	// Dimensions of the chess board.

	const double innerSize = 50.00;
	const double xBorderSize = 1.00;
	const double yBorderSize = 1.00;
	const double thickness = 0.25;

	const Color lightSquareColor = Color(0.76, 0.60, 0.42);
	const Color darkSquareColor = Color(0.76, 0.60, 0.42);
	const Color borderColor = Color(0.76, 0.60, 0.42);

	// Create the chess board and add it to the scene.

	ChessBoard* board = new ChessBoard(
		innerSize,
		xBorderSize,
		yBorderSize,
		thickness,
		lightSquareColor,
		darkSquareColor,
		borderColor);

	board->Move(0.0, 0.0, -80.0);

	scene.AddSolidObject(board);

	//CUBOIDS

		scene.AddSolidObject(board);

		scene.AddLightSource(LightSource(Vector(-45.0, +25.0, +50.0), Color(0.4, 0.4, 0.1, 1.0)));
		scene.AddLightSource(LightSource(Vector(+5.0, +90.0, +40.0), Color(0.5, 0.5, 1.5, 1.0)));
		scene.AddLightSource(LightSource(Vector(-25.0, +30.0, +40.0), Color(0.3, 0.2, 0.1, 1.0)));
		*/


	//CONES

	Cone* conoIzquierdo = new Cone(1.0, 1.5);
	conoIzquierdo->SetFullMatte(Color(0.9, 0.9, 0.8));
	conoIzquierdo->Move(5.0, -3.0, -50.0);
	conoIzquierdo->RotateX(-90.0);

	scene.AddSolidObject(conoIzquierdo);

	//CUBOIDS
	/*
	Cuboid *cuboid = new Cuboid(0.6, 0.6, 0.6);
	cuboid->SetFullMatte(Color(0.9, 0.5, 0.8));
	cuboid->Move(1.0, -1.2, -50.0);
	cuboid->RotateX(-130.0);
	cuboid->RotateY(-3.0);

	scene.AddSolidObject(cuboid);

	Cuboid *cuboid2 = new Cuboid(0.4, 0.4, 0.6);
	cuboid2->SetFullMatte(Color(0.9, 0.9, 0.8));
	cuboid2->Move(1.9, 0.2, -50.0);
	cuboid2->RotateX(-160.0);
	cuboid2->RotateY(-3.0);

	scene.AddSolidObject(cuboid2);
	*/
	//SPHERES

	/*struct sphere_info
	{
		Vector center;
		double radius;
	};

	const sphere_info sinfo[] =
	{
		//Arriba
		{ Vector(-1.5, 0.1, -17.0), 0.32 },
		{ Vector(-1.0, 0.6, -17.0), 0.20 },
		{ Vector(-0.9, 0.2, -17.0), 0.18 },
		{ Vector(-1.9, 0.6, -17.0), 0.12 },

		//En medio
		{ Vector(-1.0,  0.0, -17.0), 0.09 },
		{ Vector(-1.2, -0.1, -17.0), 0.09 },
		{ Vector(-0.8, -0.2, -17.0), 0.10 },
		{ Vector(-1.2, -0.3, -17.0), 0.12 },
		{ Vector(-0.1, -0.5, -17.0), 0.19 },
		{ Vector(-1.7, -0.4, -17.0), 0.12 },
		{ Vector(-1.4, -0.5, -17.0), 0.19 },
		{ Vector(-1.8, -0.6, -17.0), 0.10 },

		//abajo
		{ Vector(-1.0, -0.6, -17.0), 0.08 },
		{ Vector(-0.7, -0.9, -17.0), 0.08 },
		{ Vector(-0.9, -0.7, -17.0), 0.07 },
		{ Vector(-1.2, -1.0, -17.0), 0.06 },
		{ Vector(-1.0, -1.2, -17.0), 0.11 },
		{ Vector(-1.5, -1.0, -17.0), 0.06 },
		{ Vector(-1.6, -1.2, -17.0), 0.11 }

	};


	const size_t numSpheres = sizeof(sinfo) / sizeof(sinfo[0]);
	for (size_t i = 0; i < numSpheres; ++i)
	{
		Sphere* sphere = new Sphere(sinfo[i].center, sinfo[i].radius);
		//sphere->Move(1.0, 0.0, 0.0);
		//sphere->SetOpacity(0.17);
		//sphere->SetMatteGlossBalance(0.95, Color(0.4, 0.5, 0.7), Color(0.8, 1.0, 0.7));
		scene.AddSolidObject(sphere);
	}
	
	scene.AddLightSource(LightSource(Vector(-25.0, +30.0, +40.0), Color(0.3, 0.2, 0.1, 1.0)));*/
	//CYLENDER

	/*Cylinder* cylinder = new Cylinder(1.5, 4.0);
	cylinder->SetFullMatte(Color(1.0, 0.5, 0.5));
	cylinder->Move(-4.0, 2.0, -50.0);
	cylinder->RotateX(-160.0);
	cylinder->RotateY(10.0);

	scene.AddSolidObject(cylinder);

	Cylinder* cylinder2 = new Cylinder(1.5, 4.0);
	cylinder2->SetFullMatte(Color(0.9, 0.2, 0.5));
	cylinder2->Move(1.0, 2.5, -50.0);
	cylinder2->RotateX(-120.0);
	cylinder2->RotateY(5.0);

	scene.AddSolidObject(cylinder2);
	*/

	Cylinder* cylinder3 = new Cylinder(1.5, 4.0);
	cylinder3->SetFullMatte(Color(0.1, 0.8, 0.6));
	cylinder3->Move(6.0, 2.5, -50.0);
	cylinder3->RotateX(-120.0);
	cylinder3->RotateY(-180.0);

	scene.AddSolidObject(cylinder3);
	
	Cylinder* cylinder4 = new Cylinder(0.5, 1.9);
	cylinder4->SetFullMatte(Color(0.3, 0.8, 0.5));
	cylinder4->Move(3.0, 4.0, -50.0);
	cylinder4->RotateX(-190.0);
	cylinder4->RotateY(-70.0);


	scene.AddSolidObject(cylinder4);
	scene.AddLightSource(LightSource(Vector(+35.0, +50.0, +20.0), Color(1.0, 1.0, 1.0)));

	*/
	//Polyhedra

	Optics optics;  // use default optics (white matte finish, opaque)

	Dodecahedron* dodecahedron = new Dodecahedron(Vector(+0.0, -0.3, -30.0), 0.3, optics);
	dodecahedron->RotateX(-12.0);
	dodecahedron->RotateY(-7.0);

	scene.AddSolidObject(dodecahedron);

	Icosahedron* icosahedron = new Icosahedron(Vector(-2.0, -1.2, -30.0), 0.3, optics);
	icosahedron->RotateY(-12.0);
	icosahedron->RotateX(-7.0);

	scene.AddSolidObject(icosahedron);
	
	// Add light sources.

	scene.AddLightSource(LightSource(Vector(-100.0, 50.0, 100.0), Color(1.0, 1.0, 1.0, 1.0))); //IZQ
	scene.AddLightSource(LightSource(Vector(0.0, -20.0, 200.0), Color(1.0, 1.0, 1.0, 1.0))); //CENTRO
	scene.AddLightSource(LightSource(Vector(100.0, 50.0, 100.0), Color(1.0, 1.0, 1.0, 1.0))); //DER

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

