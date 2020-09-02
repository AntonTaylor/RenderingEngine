#include "tgaimage.h"

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red   = TGAColor(255, 0,   0,   255);

void line(int x1, int y1, int x2, int y2, TGAImage &image, TGAColor color);
void triangle(int p1x, int p1y, int p2x, int p2y, int p3x, int p3y, TGAImage &image);
int points [3][2] = {{0,0}, {250, 500}, {0, 500}};
int main(int argc, char** argv) {
	TGAImage image(500, 500, TGAImage::RGB);
	//line(0,0, 500, 355, image, white);
//	line(300, 400, 75, 80, image, red);
	triangle(points[0][0], points[0][1], points[1][0], points[1][1], points[2][0], points[2][1], image);
	image.flip_vertically(); // i want to have the origin at the left bottom corner of the image
	image.write_tga_file("output.tga");
	return 0;
}

void line(int x1, int y1, int x2, int y2, TGAImage &image, TGAColor color){
	if(x1>x2){
		std::swap(x1, x2);
		std::swap(y1, y2);
	}
	int x  = x1;
	int y = y1;
	int dx = x2 - x1, dy = y2-y1; //defining delta x and delta y
	int decision = 2*dx - dy; //defining initial decision variable


	while(x <= x2){
		image.set(x,y, color);
		x++;
		if(decision<0){ //if decision variable is less than 0 update accordingly and don't increment y
			decision += 2*dy;
		}
		else{  //else if decision variable is greater than or equal to 0, update accordingly and increment y
			decision += 2*dy - 2*dx;
			y++;
		}

	}

}

void triangle(int p1x, int p1y, int p2x, int p2y, int p3x, int p3y, TGAImage &image){
	line(p1x, p1y, p2x, p2y, image, red);
	line(p2x, p2y, p3x, p3y, image, red);
	line(p3x, p3y, p1x, p1y, image, red);

}
