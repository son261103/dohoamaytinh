#include "glut.h"
#include <vector>

struct Fish {
    float x, y, z; // Tọa độ của con cá
    float angle;   // Góc quay của con cá
};

class Aquarium {
private:
    Fish fish1, fish2; // Khai báo hai con cá
    float aquariumX, aquariumY, aquariumZ; // Vị trí của bể cá
    float aquariumWidth, aquariumHeight, aquariumDepth; // Kích thước của bể cá

public:
    // Constructor của lớp Aquarium
    Aquarium(float x, float y, float z, float width, float height, float depth)
        : aquariumX(x), aquariumY(y), aquariumZ(z), aquariumWidth(width), aquariumHeight(height), aquariumDepth(depth) {
        // Khởi tạo vị trí ban đầu và góc quay của các con cá
        fish1.x = x - width / 4; fish1.y = y + height / 2; fish1.z = z - depth / 4; fish1.angle = 0.0;
        fish2.x = x + width / 4; fish2.y = y + height / 2; fish2.z = z + depth / 4; fish2.angle = 0.0;
    }

    // Vẽ bể cá và các con cá
    void drawAquarium() {
        // Vẽ khung bao quanh bể cá (màu xám)
        glColor3f(0.5f, 0.5f, 0.5f);
        glPushMatrix();
        glTranslatef(aquariumX, aquariumY, aquariumZ);
        glScalef(aquariumWidth, aquariumHeight, aquariumDepth);
        glutWireCube(1.0f);
        glPopMatrix();
        // Vẽ bể cá
        glColor3f(0.0f, 0.4f, 0.8f); // Màu xanh da trời
        glPushMatrix();
        glTranslatef(aquariumX, aquariumY, aquariumZ);
        glScalef(aquariumWidth, aquariumHeight, aquariumDepth);
        glutSolidCube(1.0);
        glPopMatrix();

        // Vẽ các con cá
        drawFish(fish1.x, fish1.y, fish1.z, fish1.angle);
        drawFish(fish2.x, fish2.y, fish2.z, fish2.angle);
    }

    // Cập nhật vị trí và góc quay của các con cá
    void updateFish() {
        // Cập nhật vị trí và góc quay của các con cá
        fish1.x += 0.01; fish1.angle += 1.0;
        fish2.z -= 0.02; fish2.angle -= 1.5;

        // Kiểm tra xem các con cá có nên được "quay lại" không gian bể cá không
        if (fish1.x > aquariumX + aquariumWidth / 2) fish1.x = aquariumX - aquariumWidth / 2;
        if (fish2.z < aquariumZ - aquariumDepth / 2) fish2.z = aquariumZ + aquariumDepth / 2;
    }

    // Vẽ cá
    void drawFish(float x, float y, float z, float angle) {
        glPushMatrix(); // Lưu trạng thái hiện tại của ma trận mô hình
        glTranslatef(x, y, z); // Di chuyển đến vị trí của con cá
        glRotatef(angle, 0, 1, 0); // Quay con cá theo góc angle

        // Vẽ thân cá (hình trụ)
        glColor3f(1.0, 0.0, 0.0); // Màu đỏ
        drawCylinder(0.05, 0.2, 20); // Bán kính 0.05 và chiều cao 0.2

        // Vẽ đuôi cá (tam giác)
        glBegin(GL_TRIANGLES);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(-0.1, 0.0, 0.1);
        glVertex3f(-0.1, 0.0, -0.1);
        glEnd();

        glPopMatrix(); // Khôi phục trạng thái trước đó của ma trận mô hình
    }


    // Vẽ hình trụ (hàm này được sử dụng để vẽ thân của con cá)
    void drawCylinder(float radius, float height, int slices) {
        GLUquadric* quad = gluNewQuadric();
        gluCylinder(quad, radius, radius, height, slices, 1);
        gluDeleteQuadric(quad);
    }
};
