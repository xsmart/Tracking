// object.h, Contains class definition of object

#include <iostream>
#include <opencv2/core/core.hpp>
#include "Prediction\StateSpaceModel.h"

#ifndef OBJECT_H
#define OBJECT_H

class Object
{
public:
	Object() {x = 0, y = 0, dx = 0, dy = 0, xHat = 0, yHat = 0, width = 0, height = 0, id = 0;}
	Object(int x, int y, float dx, float dy, int xHat = 0, int yHat = 0, int width = 0, int height = 0, int id = 0);
	Object(cv::Rect boundingBox, float dx = 0, float dy = 0, int id = 0);

	int id, x, y, xHat, yHat, width, height;
	float dx, dy;

	Prediction::StateSpaceModel model;

	bool lost;

	
	cv::Rect boundingBox;
		
	friend std::ostream & operator<< (std::ostream & o, Object & obj);
	void info();
	bool operator==(const Object & other) { return id == other.id; }

	float containedAreaQuotient(Object & other);
	float intervalOverlap(float x1, float x2, float y1, float y2);
};
#endif