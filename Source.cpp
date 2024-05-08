    #include "bed.h"      // Đưa vào file header của lớp BED để sử dụng
    #include "Tuongnha.h" // Đưa vào file header của lớp SHAPE để sử dụng
    #include "Desk.h" 
    #include "VanityDesk .h"
    #include "Window.h" // Đưa vào file header của lớp Window để sử dụng
    #include "Aquarium.h"
    #include "Clock.h"


    SHAPE KHOI; // Khởi tạo một đối tượng SHAPE để vẽ không gian phòng
    BED bed;    // Khởi tạo một đối tượng BED để vẽ giường, gối và chăn
    DESK desk;
    VanityDesk vanityDesk;
    Window window; // Khởi tạo một đối tượng Window để vẽ cửa sổ
    Aquarium aquarium(7.0, 1.5, 1.5, 1.2, 1.0, 1.0); // Khởi tạo một đối tượng Aquarium với các tham số vị trí và kích thước
    Clock myClock;


    void init() {
        // Thiết lập màu nền của cửa sổ OpenGL
        glClearColor(137 / 255.0, 154 / 255.0, 208 / 255.0, 1.0);
    }



    void display() {
        // Xóa bộ đệm màu và bộ đệm chiều sâu
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity(); // Đặt ma trận hiện tại về ma trận đơn vị

        // Thiết lập cái nhìn và hướng của máy ảnh trong không gian
        gluLookAt(17.0, 5.0, 30.0, 0.0, 0.0, 0.0, 0.0, 5.0, 0.0);

        // Vẽ cửa sổ
        window.draw(2.3, 2.7, 1.0, 2.0, 2.0, 0.1); // Vị trí và kích thước của cửa sổ

        // Vẽ không gian của căn phòng
        KHOI.DrawFull();

        // Vẽ giường
        bed.drawBed(0.0, 0.0, 0.0, 3.0, 0.5, 5.0);    // Vị trí và kích thước mới của giường (nhỏ lại và được đặt ở góc phòng)

        // Vị trí mới của chăn để nó nằm trên giường và che kín bề mặt giường
        float blanketX = -2.0;
        float blanketY = 0.0;
        float blanketZ = -1.0;
        float blanketWidth = 3.0;
        float blanketHeight = 0.6;
        float blanketLength = 1.5;

        // Vẽ chăn với vị trí mới
        bed.drawBlanket(blanketX, blanketY, blanketZ, blanketWidth, blanketHeight, blanketLength);

        // Vị trí mới của chăn để nó nằm trên giường và che kín bề mặt giường
        float blanketX1 = 1.9;
        float blanketY1 = 0.0;
        float blanketZ1 = -1.0;
        float blanketWidth1 = 1.0;
        float blanketHeight1 = 0.6;
        float blanketLength1 = 1.5;

        // Vẽ chăn với vị trí mới
        bed.drawBlanket(blanketX1, blanketY1, blanketZ1, blanketWidth1, blanketHeight1, blanketLength1);


        // Vị trí mới của chăn để nó nằm trên giường và che kín bề mặt giường
        float blanketX2 = -1;
        float blanketY2 = 0.0;
        float blanketZ2 = 1.5;
        float blanketWidth2 = 3.9;
        float blanketHeight2 = 0.6;
        float blanketLength2 = 3.4;

        // Vẽ chăn với vị trí mới
        bed.drawBlanket(blanketX2, blanketY2, blanketZ2, blanketWidth2, blanketHeight2, blanketLength2);


        // Vẽ bàn học và chân bàn
        desk.drawDesk(8.15, 1.0, 1.0, 3.5, 0.2, 3.3); // Vị trí và kích thước của bàn học
        desk.drawLeg(6.2, 0.5, 0.5, 0.2, 1.0, 0.2);  // Vị trí và kích thước của chân bàn
        desk.drawLeg(6.55, 0.5, 2.5, 0.2, 1.0, 0.2);  // Vị trí và kích thước của chân bàn
        desk.drawLeg(9.8, 0.5, 0.5, 0.2, 1.0, 0.2);  // Vị trí và kích thước của chân bàn
        desk.drawLeg(9.87, 0.5, 2.5, 0.2, 1.0, 0.2);  // Vị trí và kích thước của chân bàn

        // Vẽ ghế
        // Vị trí và kích thước của ghế
        float chairX = 6.5;
        float chairY = 0.0;
        float chairZ = 4.0;
        float chairWidth = 1.0;
        float chairHeight = 1.0;
        float chairLength = 1.0;

        // Phần đệm ngồi của ghế gaming
        //desk.drawGamingChair(6.5, 0.0, 1.5, 1.0, 1.0, 1.0);

        // Vẽ desktop trên bàn
        desk.drawDesktop(8.5, 1.1, 0.0, 1.5, 1.5, 0.017);


        desk.drawComputerCase(0.0f, 0.0f, 0.0f, 1.0f, 0.5f, 0.5f); // Vẽ thùng máy tính4
        // Vẽ bàn trang điểm
        vanityDesk.draw(4.5, 0.0, 1.0, 1.9, 1.0, 1.5); // Vị trí và kích thước của bàn trang điểm
        // Vẽ ngăn kéo trên bàn trang điểm
        for (int i = 0; i < 3; ++i) {
            // Tính toán vị trí và kích thước của ngăn kéo
            float drawerX = 4.0 + 1.9 * (i * 0.3);
            float drawerY = 0.25;
            float drawerZ = 1.0 + 1.5 / 2;
            float drawerWidth = 1.9 * 0.25;
            float drawerHeight = 0.5 / 2;
            float drawerLength = 1.5 * 0.25;

            // Vẽ ngăn kéo
            vanityDesk.drawDrawer(drawerX, drawerY, drawerZ, drawerWidth, drawerHeight, drawerLength, i);
        }

        vanityDesk.drawVanityMirror(5.0, 1.4, 1.7, 1.9, 1.5, 0.1); // Vị trí và kích thước của gương trang điểm


        // Vẽ bể cá và các con cá với vị trí và kích thước tùy chỉnh
        aquarium.drawAquarium();


        // Vẽ cửa
        //door.draw(4, 0, 0, 6, 0, 0, 6, 6, 0, 4, 6, 0, 255, 0, 0, 0.1, "x");
        KHOI.draw(
            0.3, 0, 7,   // Góc trái dưới (x, y, z)
            0.3, 2.5, 7, // Góc phải dưới (x, y, z)
            0.1, 2.5, 9, // Góc phải trên (x, y, z)
            0.1, 0, 9,   // Góc trái trên (x, y, z)
            180, 180, 180, // Màu sắc của cửa (xám)
            0.1,          // Độ dày của cửa
            "x"           // Hướng lùi
        );


       myClock.drawClock(5.0, 3.5, 0.5, 0.5); // Vị trí và kích thước của đồng hồ
       // Vẽ ghế
       desk.drawGamingChair(8.0f, 0.0f, 3.0f, 2.0f, 5.0f, 1.0f, 90);

       KHOI.drawRug(4.5f, 0.0f, 3.7f, 5.0f, 0.1f, 6.0f);


        glFlush();         // Đẩy các lệnh vẽ đang đợi ra bộ đệm màn hình
        glutSwapBuffers(); // Hoán đổi bộ đệm màn hình hiện tại với bộ đệm khác (nếu có)
    }



    void reshape(int w, int h) {
        // Cập nhật kích thước của viewport
        glViewport(0, 0, w, h);
        glMatrixMode(GL_PROJECTION); // Chuyển sang chế độ ma trận chiếu
        glLoadIdentity();             // Đặt ma trận chiếu về ma trận đơn vị
        // Cấu hình ma trận chiếu theo phối cảnh
        gluPerspective(30.0, (GLfloat)w / (GLfloat)h, 1.0, 100.0);
        glMatrixMode(GL_MODELVIEW); // Chuyển lại sang chế độ ma trận mô hình
        glLoadIdentity();            // Đặt ma trận mô hình về ma trận đơn vị
    }

    void mouse(int button, int state, int x, int y) {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
            // Đảm bảo bạn chuyển đúng số lượng tham số cho phương thức toggleOpenStatus
            // Trong trường hợp này, bạn cần chuyển x, y và kích thước cửa sổ
            int windowWidth = 1200;
            int windowHeight = 950;
            window.toggleOpenStatus(x, y, 0.0f, 0.0f, 0.0f, windowWidth, windowHeight);
            glutPostRedisplay(); // Cập nhật lại cửa sổ hiển thị
        }
    }

    // Hàm cập nhật, được gọi định kỳ để cập nhật trạng thái của các con cá
    void update(int value) {
        // Cập nhật vị trí và góc quay của các con cá
        aquarium.updateFish();

        // Gọi lại hàm display để vẽ lại cảnh
        glutPostRedisplay();

        // Thiết lập thời gian giữa các lần cập nhật
        glutTimerFunc(25, update, 0);

        myClock.updateClock(value);
    }

    void keyboard(unsigned char key, int x, int y) {
        KHOI.keyPressed(key, x, y);
    }

    void updateClock(int value);

    int main(int argc, char** argv) {
        glutInit(&argc, argv); // Khởi tạo thư viện GLUT
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // Thiết lập chế độ hiển thị
        int windowWidth = 1200;
        int windowHeight = 950;
        glutInitWindowSize(windowWidth, windowHeight); // Khởi tạo cửa sổ với kích thước cụ thể
        glutCreateWindow("3D Room"); // Tạo cửa sổ với tiêu đề "3D Room"
        glEnable(GL_DEPTH_TEST); // Bật kiểm tra chiều sâu
        init(); // Gọi hàm khởi tạo để cài đặt các thiết lập ban đầu


        // Đăng ký hàm vẽ, hàm thay đổi kích thước cửa sổ và hàm xử lý sự kiện chuột
        glutDisplayFunc(display);
        glutReshapeFunc(reshape);
        glutMouseFunc(mouse);
        glutTimerFunc(25, update, 0); // Đăng ký hàm update để cập nhật trạng thái
        glutKeyboardFunc(keyboard);

        glutMainLoop(); // Bắt đầu vòng lặp chính của GLUT để xử lý sự kiện và vẽ

        return 0;
    }
