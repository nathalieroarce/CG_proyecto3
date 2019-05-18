#include "pch.h"
#include "algebra.h"
#include "imager.h"

namespace Imager
{
	void Cone::ObjectSpace_AppendAllIntersections(
		const Vector& vantage,
		const Vector& direction,
		IntersectionList& intersectionList) const
	{
		// Look for intersections with the disks on the top and/or bottom of the cylinder.
		if (fabs(direction.z) > EPSILON)
		{
			//Bloqueo una cara del cilindro porque un cono s�lo posee una cara y el resto es  lateral (puede ser la otra cara la que se deba bloquear)
			//AppendDiskIntersection(vantage, direction, +b, intersectionList);
			AppendDiskIntersection(vantage, direction, -b, intersectionList);
		}

		// Look for intersections with the curved lateral surface of the cylinder.
		double u[2]; //Creo la lista de las soluciones a la ecuaci�n cuadr�tica
		double x, z;
		//Resuelvo la ecuaci�n cuadr�tica y guardo los resultados
		/*const int numRoots = Algebra::SolveQuadraticEquation(
			direction.x*direction.x + direction.y*direction.y,
			2.0*(vantage.x*direction.x + vantage.y*direction.y),
			vantage.x*vantage.x + vantage.y*vantage.y - a*a,
			u
		);*/
		const int numRoots = Algebra::SolveQuadraticEquation(
			direction.x*direction.x + direction.y*direction.y - ((direction.z)*(direction.z) / ((b*b * 4) / (a*a))),
			2.0*(vantage.x*direction.x + vantage.y*direction.y - ((vantage.z - b)*direction.z) / ((b*b * 4) / (a*a))),
			vantage.x*vantage.x + vantage.y*vantage.y - ((vantage.z - b)*(vantage.z - b) / ((b*b * 4) / (a*a))),
			u
		);

		//Recorro las soluciones y calculo la intersecciones con el cilindro
		for (int i = 0; i < numRoots; ++i)
		{
			if (u[i] > EPSILON)
			{
				Intersection intersection;
				Vector displacement = u[i] * direction;
				intersection.point = vantage + displacement;

				// We found an intersection with the infinitely-extended lateral surface,
				// but the z-component must be within + or - b.

				if (fabs(intersection.point.z) <= b)
				{
					x = intersection.point.x;
					z = intersection.point.z + b;
					intersection.distanceSquared = displacement.MagnitudeSquared();
					intersection.surfaceNormal = Vector(intersection.point.x, intersection.point.y,
						(1 / (sqrt(x*x + z * z)))).UnitVector();
					intersection.solid = this;

					intersectionList.push_back(intersection);
				}
			}
		}
	}

	//Recibe vector de posicion de la camara, direcci�n de la camara distancia a la cara del disco correspondiente (distancia desde el vector 0,0,0)
	//y lista de intersecciones
	void Cone::AppendDiskIntersection(const Vector& vantage, const Vector& direction, double zDisk, IntersectionList& intersectionList) const
	{
		//Calcula distancia desde la posicion de la c�mara hasta la "ubicacion" de la cara del cilindro
		const double u = (zDisk - vantage.z) / direction.z;
		//Si la distancia es mayor a epsilon puede ser dibujada en el famebuffer, pues esta lo suficientemente lejos de la vision
		if (u > EPSILON)
		{
			Intersection intersection; //Crea interseccion (contiene todo lo requerido por el raytracer)
			Vector displacement = u * direction; //Crea vector de desplazamiento que contiene los valores no normalizados
			intersection.point = vantage + displacement; //la localizacion del punto de interseccion
			const double x = intersection.point.x;
			const double y = intersection.point.y;
			if (x*x + y * y <= a * a) //Verifico si el rayo (la magnitud en terminos de xy se encuentra dentro del circulo)
			{
				//Si se cumple la condicion guardo la interseccion con los datos pertinentes en la lista
				intersection.distanceSquared = displacement.MagnitudeSquared();
				intersection.surfaceNormal = Vector(0.0, 0.0, (zDisk > 0.0) ? +1.0 : -1.0);
				intersection.solid = this;

				intersectionList.push_back(intersection);
			}
		}
	}
}