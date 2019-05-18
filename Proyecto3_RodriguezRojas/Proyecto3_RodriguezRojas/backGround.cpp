#include "pch.h"
#include "imager.h"

namespace Imager
{
	void backGround::ObjectSpace_AppendAllIntersections(
		const Vector& vantage,
		const Vector& direction,
		IntersectionList& intersectionList) const
	{
		for (int i = 0; i < 1008; i++) {
			for (int j = 0; j < 567; j++) {
				Intersection intersection;

				intersection.surfaceNormal = Vector(i, j, 15.0).UnitVector();
				intersection.solid = this;

				intersectionList.push_back(intersection);
			}
		}
			
	}
}