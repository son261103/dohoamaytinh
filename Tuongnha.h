#include <string>
#include <math.h>
#include <stdlib.h>
#include "glut.h"
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
class SHAPE {
public:
	
	// Hàm vẽ khối 
	void drawCube(
		float x1, float y1, float z1, // góc trái dưới
		float x2, float y2, float z2, // góc phải dưới
		float x3, float y3, float z3, // góc phải trên
		float x4, float y4, float z4, // góc trái trên
		float r = 255, float g = 255, float b = 255, // màu sắc
		float thickness = 0.1, // độ dày của tường
		std::string direction = "y" // hướng lùi
	) {


		glColor3f(r / 255.0, g / 255.0, b / 255.0); // Set color

		// Thiết lập màu sắc cho vật liệu


		float dx = 0, dy = 0, dz = 0;
		if (direction == "x") dx = thickness;
		else if (direction == "y") dy = thickness;
		else if (direction == "z") dz = thickness;

		// Mặt trước
		glBegin(GL_QUADS);
		glVertex3f(x1, y1, z1);
		glVertex3f(x2, y2, z2);
		glVertex3f(x3, y3, z3);
		glVertex3f(x4, y4, z4);
		glEnd();

		// Viền trc
		glColor3f(128 / 255.0, 128 / 255.0, 128 / 255.0); // Set color
		glBegin(GL_LINE_LOOP);
		glVertex3f(x1, y1, z1);
		glVertex3f(x2, y2, z2);
		glVertex3f(x3, y3, z3);
		glVertex3f(x4, y4, z4);
		glEnd();


		// Mặt sau
		glColor3f(r / 255.0, g / 255.0, b / 255.0); // Set color
		glBegin(GL_QUADS);
		glVertex3f(x1 - dx, y1 - dy, z1 - dz);
		glVertex3f(x2 - dx, y2 - dy, z2 - dz);
		glVertex3f(x3 - dx, y3 - dy, z3 - dz);
		glVertex3f(x4 - dx, y4 - dy, z4 - dz);
		glEnd();


		// Mặt trên
		glColor3f(128 / 255.0, 128 / 255.0, 128 / 255.0); // Set color
		glBegin(GL_QUADS);
		glVertex3f(x4, y4, z4);
		glVertex3f(x3, y3, z3);
		glVertex3f(x3 - dx, y3 - dy, z3 - dz);
		glVertex3f(x4 - dx, y4 - dy, z4 - dz);
		glEnd();

		//Viền Mặt trên
		glColor3f(128 / 255.0, 128 / 255.0, 128 / 255.0); // Set color
		glBegin(GL_LINE_LOOP);
		glVertex3f(x4, y4, z4);
		glVertex3f(x3, y3, z3);
		glVertex3f(x3 - dx, y3 - dy, z3 - dz);
		glVertex3f(x4 - dx, y4 - dy, z4 - dz);
		glEnd();


		// Mặt dưới
		glColor3f(128 / 255.0, 128 / 255.0, 128 / 255.0); // Set color
		glBegin(GL_QUADS);
		glVertex3f(x1, y1, z1);
		glVertex3f(x2, y2, z2);
		glVertex3f(x2 - dx, y2 - dy, z2 - dz);
		glVertex3f(x1 - dx, y1 - dy, z1 - dz);
		glEnd();


		// Viền Mặt dưới
		glColor3f(128 / 255.0, 128 / 255.0, 128 / 255.0); // Set color
		glBegin(GL_LINE_LOOP);
		glVertex3f(x1, y1, z1);
		glVertex3f(x2, y2, z2);
		glVertex3f(x2 - dx, y2 - dy, z2 - dz);
		glVertex3f(x1 - dx, y1 - dy, z1 - dz);
		glEnd();


		// Mặt phải
		glColor3f(128 / 255.0, 128 / 255.0, 128 / 255.0); // Set color
		glBegin(GL_QUADS);
		glVertex3f(x2, y2, z2);
		glVertex3f(x3, y3, z3);
		glVertex3f(x3 - dx, y3 - dy, z3 - dz);
		glVertex3f(x2 - dx, y2 - dy, z2 - dz);
		glEnd();

		//Viền Mặt phải
		glColor3f(128 / 255.0, 128 / 255.0, 128 / 255.0); // Set color
		glBegin(GL_QUADS);
		glVertex3f(x2, y2, z2);
		glVertex3f(x3, y3, z3);
		glVertex3f(x3 - dx, y3 - dy, z3 - dz);
		glVertex3f(x2 - dx, y2 - dy, z2 - dz);
		glEnd();


		// Mặt trái
		glColor3f(128 / 255.0, 128 / 255.0, 128 / 255.0); // Set color
		glBegin(GL_QUADS);
		glVertex3f(x1, y1, z1);
		glVertex3f(x4, y4, z4);
		glVertex3f(x4 - dx, y4 - dy, z4 - dz);
		glVertex3f(x1 - dx, y1 - dy, z1 - dz);
		glEnd();


		// Viền Mặt trái
		glBegin(GL_QUADS);
		glColor3f(128 / 255.0, 128 / 255.0, 128 / 255.0); // Set color
		glVertex3f(x1, y1, z1);
		glVertex3f(x4, y4, z4);
		glVertex3f(x4 - dx, y4 - dy, z4 - dz);
		glVertex3f(x1 - dx, y1 - dy, z1 - dz);
		glEnd();
	}


	//Tường và sàn nhà
	void drawWalls() {


		glPushMatrix();
		GLfloat wall_ambient[] = { 237 / 255.0, 230 / 255.0, 214 / 255.0, 1.0 }; // Màu tường  
		GLfloat wall_diffuse[] = { 237 / 255.0, 230 / 255.0, 214 / 255.0, 1.0 }; // Màu tường
		GLfloat wall_specular[] = { 0.0, 0.0, 0.0, 1.0 }; // Màu tường

		// Thiết lập màu sắc phản chiếu cho mặt trước của tường
		glMaterialfv(GL_FRONT, GL_AMBIENT, wall_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, wall_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, wall_specular);

		// Thiết lập màu sắc phản chiếu cho mặt sau của tường
		glMaterialfv(GL_BACK, GL_AMBIENT, wall_ambient);
		glMaterialfv(GL_BACK, GL_DIFFUSE, wall_diffuse);
		glMaterialfv(GL_BACK, GL_SPECULAR, wall_specular);


		// Tường trái
		drawCube(
			0, 0, 0, // góc trái dưới
			0, 5, 0, // góc phải dưới
			0, 5, 10, // góc phải trên
			0, 0, 10, // góc trái trên
			60, 80, 45, // màu sắc
			0.3, // độ dày của tường
			"x" // hướng lùi
		);

		// Tường phải
		drawCube(
			-0.3, 0, 0, // góc trái dưới
			10, 0, 0, // góc phải dưới
			10, 5, 0, // góc phải trên
			-0.3, 5, 0, // góc trái trên
			65, 85, 50, // màu sắc
			0.3, // độ dày của tường
			"z" // hướng lùi
		);

		// Nền nhà
		drawCube(
			-0.3, 0, -0.3, // góc trái dưới
			10, 0, -0.3, // góc phải dưới
			10, 0, 10, // góc phải trên
			-0.3, 0, 10, // góc trái trên
			214, 233, 229, // màu sắc
			0.3, // độ dày của tường
			"y" // hướng lùi
		);
		// Trần nhà
		drawCube(
			-0.3, 4.99f, -0.299, // góc trái dưới
			7.99, 4.99f, -0.299, // góc phải dưới
			4.99, 4.99f, 4.99, // góc phải trên
			-0.299, 4.99f, 7.99, // góc trái trên
			255, 255, 255, // màu sắc
			0.3, // độ dày của tường
			"y" // hướng lùi
		);
		/*
		// Vẽ cửa trái
		drawCube(
			0.3, 0, 7,   // Góc trái dưới (x, y, z)
			0.3, 2.5, 7, // Góc phải dưới (x, y, z)
			0.1, 2.5, 9, // Góc phải trên (x, y, z)
			0.1, 0, 9,   // Góc trái trên (x, y, z)
			180, 180, 180, // Màu sắc của cửa (xám)
			0.1,          // Độ dày của cửa
			"x"           // Hướng lùi
		);

		
		drawCube(
			0.3, 0.25, 7,  // Góc trái dưới (x, y, z)
			0.3, 0.5, 7,  // Góc phải dưới (x, y, z)
			0.3, 0.5, 9,  // Góc phải trên (x, y, z)
			0.3, 0.25, 9,  // Góc trái trên (x, y, z)
			240, 240, 240,
			0.05,              // Độ dày của tay nắm cửa
			"x"               // Hướng lùi
		);

		// Vẽ cửa trên
		drawCube(
			0.3, 2, 7,  // Góc trái dưới (x, y, z)
			0.3, 2.3, 7,   // Góc phải dưới (x, y, z)
			0.3, 2.3, 9,   // Góc phải trên (x, y, z)
			0.3, 2, 9,  // Góc trái trên (x, y, z)
			240, 240, 240, // Màu sắc của cửa (xám nhạt)
			0.05,          // Độ dày của cửa
			"x"            // Hướng lùi
		);

		// Vẽ cửa trên
		drawCube(
			1.45, 1.45, 8.5,  // Góc trái dưới (x, y, z)
			1.45, 1.55, 8.5,  // Góc phải dưới (x, y, z)
			1.45, 1.55, 9,  // Góc phải trên (x, y, z)
			1.45, 1.45, 9,  // Góc trái trên (x, y, z)
			240, 240, 240, // Màu sắc của cửa (xám nhạt)
			0.05,          // Độ dày của cửa
			"x"            // Hướng lùi
		);
		*/



	}



	void setMaterialColor(
		float r1, float g1, float b1,
		float r2, float g2, float b2,
		float r3, float g3, float b3,
		float alpha1, float alpha2, float alpha3
	)
	{
		GLfloat ambientColor[] = { r1, g1, b1, alpha1 }; // Màu phản chiếu môi trường
		GLfloat diffuseColor[] = { r2, g2, b2, alpha2 }; // Màu phản chiếu khuyếch tán
		GLfloat specularColor[] = { r3, g3, b3, alpha3 }; // Màu phản chiếu gương

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambientColor);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseColor);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specularColor);
	}

	

	void DrawFull() {
		
		drawWalls();
		
	}


	void draw(float x1, float y1, float z1, // góc trái dưới
		float x2, float y2, float z2, // góc phải dưới
		float x3, float y3, float z3, // góc phải trên
		float x4, float y4, float z4, // góc trái trên
		float r = 255, float g = 255, float b = 255, // màu sắc
		float thickness = 0.1, // độ dày của cửa
		std::string direction = "x" // hướng lùi
	) {
		if (isDoorOpen) {
			// Chỉ vẽ phần cửa mở
			glColor3f(r / 255.0, g / 255.0, b / 255.0); // Màu sắc chuyển sang màu trắng

			float dx = 0, dy = 0, dz = 0;
			if (direction == "x") dx = thickness;
			else if (direction == "y") dy = thickness;
			else if (direction == "z") dz = thickness;

			// Tăng kích thước của cánh cửa mở lên 20% so với cánh cửa đóng
			x1 += dx * 9.1;
			x2 += dx * 9.1;
			x3 += dx * 0.1;
			x4 += dx * 0.1;
			y1 += dy * 6.8;
			y2 += dy * 6.8;
			y3 += dy * 6.8;
			y4 += dy * 6.8;
			z1 += dz * 8.5;
			z2 += dz * 8.5;
			z3 += dz * 8.5;
			z4 += dz * 8.5;

			// Vẽ cánh cửa mở
			glBegin(GL_QUADS);
			glVertex3f(x1 - dx, y1 - dy, z1 - dz);
			glVertex3f(x2 - dx, y2 - dy, z2 - dz);
			glVertex3f(x3 - dx, y3 - dy, z3 - dz);
			glVertex3f(x4 - dx, y4 - dy, z4 - dz);
			glEnd();

			// Vẽ viền cánh cửa
			glBegin(GL_LINE_LOOP);
			glVertex3f(x1, y1, z1);
			glVertex3f(x2, y2, z2);
			glVertex3f(x3, y3, z3);
			glVertex3f(x4, y4, z4);
			glEnd();
		}

		glColor3f(r / 255.0, g / 255.0, b / 255.0); // Set color

		float dx = 0, dy = 0, dz = 0;
		if (direction == "x") dx = thickness;
		else if (direction == "y") dy = thickness;
		else if (direction == "z") dz = thickness;

		// Mặt trước
		glBegin(GL_QUADS);
		glVertex3f(x1, y1, z1);
		glVertex3f(x2, y2, z2);
		glVertex3f(x3, y3, z3);
		glVertex3f(x4, y4, z4);
		glEnd();

		// Viền mặt trước
		glBegin(GL_LINE_LOOP);
		glVertex3f(x1, y1, z1);
		glVertex3f(x2, y2, z2);
		glVertex3f(x3, y3, z3);
		glVertex3f(x4, y4, z4);
		glEnd();

		// Mặt sau
		glBegin(GL_QUADS);
		glVertex3f(x1 - dx, y1 - dy, z1 - dz);
		glVertex3f(x2 - dx, y2 - dy, z2 - dz);
		glVertex3f(x3 - dx, y3 - dy, z3 - dz);
		glVertex3f(x4 - dx, y4 - dy, z4 - dz);
		glEnd();

		// Mặt trên
		glBegin(GL_QUADS);
		glVertex3f(x4, y4, z4);
		glVertex3f(x3, y3, z3);
		glVertex3f(x3 - dx, y3 - dy, z3 - dz);
		glVertex3f(x4 - dx, y4 - dy, z4 - dz);
		glEnd();

		// Viền mặt trên
		glBegin(GL_LINE_LOOP);
		glVertex3f(x4, y4, z4);
		glVertex3f(x3, y3, z3);
		glVertex3f(x3 - dx, y3 - dy, z3 - dz);
		glVertex3f(x4 - dx, y4 - dy, z4 - dz);
		glEnd();

		// Mặt dưới
		glBegin(GL_QUADS);
		glVertex3f(x1, y1, z1);
		glVertex3f(x2, y2, z2);
		glVertex3f(x2 - dx, y2 - dy, z2 - dz);
		glVertex3f(x1 - dx, y1 - dy, z1 - dz);
		glEnd();

		// Viền mặt dưới
		glBegin(GL_LINE_LOOP);
		glVertex3f(x1, y1, z1);
		glVertex3f(x2, y2, z2);
		glVertex3f(x2 - dx, y2 - dy, z2 - dz);
		glVertex3f(x1 - dx, y1 - dy, z1 - dz);
		glEnd();

		// Mặt phải
		glBegin(GL_QUADS);
		glVertex3f(x2, y2, z2);
		glVertex3f(x3, y3, z3);
		glVertex3f(x3 - dx, y3 - dy, z3 - dz);
		glVertex3f(x2 - dx, y2 - dy, z2 - dz);
		glEnd();

		// Viền mặt phải
		glBegin(GL_QUADS);
		glVertex3f(x2, y2, z2);
		glVertex3f(x3, y3, z3);
		glVertex3f(x3 - dx, y3 - dy, z3 - dz);
		glVertex3f(x2 - dx, y2 - dy, z2 - dz);
		glEnd();

		// Mặt trái
		glBegin(GL_QUADS);
		glVertex3f(x1 - 0.3, y1, z1); // Điều chỉnh tọa độ x1
		glVertex3f(x4 - 0.3, y4, z4); // Điều chỉnh tọa độ x4
		glVertex3f(x4 - 0.3 - dx, y4 - dy, z4 - dz); // Điều chỉnh tọa độ x4
		glVertex3f(x1 - 0.3 - dx, y1 - dy, z1 - dz); // Điều chỉnh tọa độ x1
		glEnd();

		// Viền mặt trái
		glBegin(GL_QUADS);
		glVertex3f(x1 - 0.3, y1, z1); // Điều chỉnh tọa độ x1
		glVertex3f(x4 - 0.3, y4, z4); // Điều chỉnh tọa độ x4
		glVertex3f(x4 - 0.3 - dx, y4 - dy, z4 - dz); // Điều chỉnh tọa độ x4
		glVertex3f(x1 - 0.3 - dx, y1 - dy, z1 - dz); // Điều chỉnh tọa độ x1
		glEnd();

		// Vẽ nút cửa
		glColor3f(0.5, 0.5, 0.5); // Màu xám cho nút cửa
		float knobSize = 0.3; // Kích thước của nút cửa
		glBegin(GL_QUADS);
		glVertex3f((x3 + x4) / 2 - knobSize / 2, (y3 + y4) / 2 - knobSize / 2, (z3 + z4) / 2);
		glVertex3f((x3 + x4) / 2 + knobSize / 2, (y3 + y4) / 2 - knobSize / 2, (z3 + z4) / 2);
		glVertex3f((x3 + x4) / 2 + knobSize / 2, (y3 + y4) / 2 + knobSize / 2, (z3 + z4) / 2);
		glVertex3f((x3 + x4) / 2 - knobSize / 2, (y3 + y4) / 2 + knobSize / 2, (z3 + z4) / 2);
		glEnd();

		// Vẽ các viền của cửa
		glColor3f(0, 0, 0); // Màu đen cho viền
		glLineWidth(1.0); // Độ dày của viền
		glBegin(GL_LINE_LOOP);
		glVertex3f(x1, y1, z1);
		glVertex3f(x2, y2, z2);
		glVertex3f(x3, y3, z3);
		glVertex3f(x4, y4, z4);
		glEnd();

		// Vẽ mặt trước của cửa
		glColor3f(r / 255.0, g / 255.0, b / 255.0);
		glBegin(GL_QUADS);
		glVertex3f(x1, y1, z1);
		glVertex3f(x2, y2, z2);
		glVertex3f(x3, y3, z3);
		glVertex3f(x4, y4, z4);
		glEnd();

	}


	void drawWindow(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3, float x4, float y4, float z4, float r, float g, float b, float thickness, const char* direction, float openWidth, float openHeight) {
		glBegin(GL_QUADS);

		glColor3f(r, g, b); // Đặt màu cho cửa sổ

		// Mặt phía trước của cửa sổ
		glVertex3f(x1, y1, z1);
		glVertex3f(x2, y2, z2);
		glVertex3f(x3, y3, z3);
		glVertex3f(x4, y4, z4);

		// Mặt phía sau của cửa sổ
		if (strcmp(direction, "xy") == 0) {
			glVertex3f(x1, y1, z1 - thickness);
			glVertex3f(x2, y2, z2 - thickness);
			glVertex3f(x3, y3, z3 - thickness);
			glVertex3f(x4, y4, z4 - thickness);
		}
		else if (strcmp(direction, "x") == 0) {
			glVertex3f(x1 - thickness, y1, z1);
			glVertex3f(x2 - thickness, y2, z2);
			glVertex3f(x3 - thickness, y3, z3);
			glVertex3f(x4 - thickness, y4, z4);
		}
		else if (strcmp(direction, "y") == 0) {
			glVertex3f(x1, y1 - thickness, z1);
			glVertex3f(x2, y2 - thickness, z2);
			glVertex3f(x3, y3 - thickness, z3);
			glVertex3f(x4, y4 - thickness, z4);
		}

		// Hai cánh của cửa sổ (nếu có)
		if (openWidth > 0 && openHeight > 0) {
			if (strcmp(direction, "xy") == 0) {
				// Cánh bên trái
				glVertex3f(x1 - openWidth, y1, z1);
				glVertex3f(x1, y1, z1);
				glVertex3f(x1, y1 + openHeight, z1);
				glVertex3f(x1 - openWidth, y1 + openHeight, z1);

				// Cánh bên phải
				glVertex3f(x2, y2, z2);
				glVertex3f(x2 + openWidth, y2, z2);
				glVertex3f(x2 + openWidth, y2 + openHeight, z2);
				glVertex3f(x2, y2 + openHeight, z2);
			}
			else if (strcmp(direction, "x") == 0) {
				// Cánh bên trái
				glVertex3f(x1, y1 - openWidth, z1);
				glVertex3f(x1, y1, z1);
				glVertex3f(x1 + openHeight, y1, z1);
				glVertex3f(x1 + openHeight, y1 - openWidth, z1);

				// Cánh bên phải
				glVertex3f(x4, y4, z4);
				glVertex3f(x4, y4 + openWidth, z4);
				glVertex3f(x4 + openHeight, y4 + openWidth, z4);
				glVertex3f(x4 + openHeight, y4, z4);
			}
			else if (strcmp(direction, "y") == 0) {
				// Cánh bên trái
				glVertex3f(x1 - openWidth, y1, z1);
				glVertex3f(x1, y1, z1);
				glVertex3f(x1, y1 + openHeight, z1);
				glVertex3f(x1 - openWidth, y1 + openHeight, z1);

				// Cánh bên phải
				glVertex3f(x2, y2, z2);
				glVertex3f(x2 + openWidth, y2, z2);
				glVertex3f(x2 + openWidth, y2 + openHeight, z2);
				glVertex3f(x2, y2 + openHeight, z2);
			}
		}

		glEnd();
	}

	// Hàm vẽ hình tròn tại tọa độ (x, y, z) với bán kính radius
	void drawCircle(float x, float y, float z, float radius) {
		int i;
		int triangleAmount = 100; //# of triangles used to draw circle

		GLfloat twicePi = 2.0f * M_PI;

		glBegin(GL_TRIANGLE_FAN);
		glVertex3f(x, y, z); // Center of circle
		for (i = 0; i <= triangleAmount; i++) {
			glVertex3f(
				x + (radius * cos(i * twicePi / triangleAmount)),
				y + (radius * sin(i * twicePi / triangleAmount)),
				z
			);
		}
		glEnd();
	}

	// Hàm vẽ thảm
	void drawRug(float x, float y, float z, float width, float height, float length) {
		// Màu sắc cho hoa văn
		GLfloat patternColors[6][3] = {
			{0.8, 0.6, 0.4}, // Nâu
			{0.2, 0.6, 0.8}, // Xanh dương
			{0.6, 0.2, 0.8}, // Tím
			{0.8, 0.2, 0.6}, // Hồng
			{0.4, 0.8, 0.2}, // Xanh lá
			{0.6, 0.8, 0.2}  // Vàng
		};

		// Vẽ hình hộp chứa thảm
		glBegin(GL_QUADS);
		// Mặt dưới của thảm
		glVertex3f(x, y, z);
		glVertex3f(x + width, y, z);
		glVertex3f(x + width, y, z + length);
		glVertex3f(x, y, z + length);
		// Mặt trên của thảm
		glVertex3f(x, y + height, z);
		glVertex3f(x + width, y + height, z);
		glVertex3f(x + width, y + height, z + length);
		glVertex3f(x, y + height, z + length);
		// Mặt bên của thảm
		glVertex3f(x, y, z);
		glVertex3f(x, y, z + length);
		glVertex3f(x, y + height, z + length);
		glVertex3f(x, y + height, z);
		// Mặt bên của thảm
		glVertex3f(x + width, y, z);
		glVertex3f(x + width, y, z + length);
		glVertex3f(x + width, y + height, z + length);
		glVertex3f(x + width, y + height, z);
		// Mặt trước của thảm
		glVertex3f(x, y, z);
		glVertex3f(x + width, y, z);
		glVertex3f(x + width, y + height, z);
		glVertex3f(x, y + height, z);
		// Mặt sau của thảm
		glVertex3f(x, y, z + length);
		glVertex3f(x + width, y, z + length);
		glVertex3f(x + width, y + height, z + length);
		glVertex3f(x, y + height, z + length);
		glEnd();

		// Thêm hoa văn hình tròn
		float circleRadius = 0.15; // Bán kính của hình tròn
		float step = 1.0; // Bước giữa các hoa văn
		for (float i = x + step; i < x + width; i += step) {
			for (float j = z + step; j < z + length; j += step) {
				// Chọn màu sắc ngẫu nhiên từ mảng patternColors
				int colorIndex = rand() % 6;
				glColor3fv(patternColors[colorIndex]);
				drawCircle(i, y + 0.01, j, circleRadius);
			}
		}
	}



	// Biến để theo dõi trạng thái mở hoặc đóng của cửa
	bool isDoorOpen = false;

	// Hàm xử lý sự kiện nhấn phím
	void keyPressed(unsigned char key, int x, int y) {
		// Nếu nhấn phím 'o', thực hiện chức năng mở và đóng cửa
		if (key == 'o' || key == 'O') {
			isDoorOpen = !isDoorOpen; // Đảo ngược trạng thái của cửa
			glutPostRedisplay(); // Yêu cầu cửa sổ được vẽ lại để cập nhật trạng thái của cửa
		}
	}


};


