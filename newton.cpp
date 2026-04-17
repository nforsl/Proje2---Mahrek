#include <iostream>
#include <cmath>
#include <windows.h>
#include <cstdlib>
#include <ctime>
int W;
int H;
int k1,k2;
class dots{
    public:
        float Cx;
        float Cy;
        float Vx = 0;
        float Vy = 0;
        float mass;
        float Fx;
        float Fy;
        char c;
        dots(float n,float m,float k,char ch,float b,float a) : Cx(n) , Cy(m) , mass(k) , c(ch) , Vx(b) , Vy(a) {};
};

void calculate(dots& p1,dots& p2,float time,float G);
float dist(dots& p1,dots& p2);
void sim(dots& p1,dots& p2,float time,float G);
void move(dots& p,float time);
void print(dots& p,char ch);
void updateConsoleDimensions(int& width, int& height);

int main(){
    srand(time(NULL));
    float x1,y1,m1,vx1,vy1;
    char c1;
    float x2,y2,m2,vx2,vy2;
    char c2;
    float time,G;
    std::cout << "izler olsun mu? (1/0)\n";
    std::cin >> k1;
    while(k1!=0&&k1!=1){
        system("cls");
        std::cout << "Hatali giris! Tekrar girin (1/0):\n";
        std::cin >> k1;
    }
    system("cls");
    std::cout << "Rastgele mod olsun mu? (1/0):\n";
    std::cin >> k2;
    while(k2!=0&&k2!=1){
        system("cls");
        std::cout << "Hatali giris! Tekrar girin (1/0):\n";
        std::cin >> k2;
    }
    system("cls");
    if(k2==1){
        updateConsoleDimensions(W,H);
        dots nokta1(rand()%(W-3)+2,rand()%(H-3)+2,rand()%99001+1000,rand()%94+33,rand()%31-15,rand()%31-15);
        dots nokta2(rand()%(W-3)+2,rand()%(H-3)+2,rand()%99001+1000,rand()%94+33,rand()%31-15,rand()%31-15);
        sim(nokta1,nokta2,(rand()%5+1)/100.0f,(rand()%20+1)/10.0f);
    }
    else if(k2==0)
    {
    std::cout << "Sira Sira nokta1 bilgilerini girin: siralama = kord.x kord.y kutle karakter vx vy\n";
    std::cin >> x1 >> y1 >> m1 >> c1 >> vx1 >> vy1;
    dots nokta1(x1,y1,m1,c1,vx1,vy1);
    system("cls");
    std::cout << "Sira sira nokta2 bilgilerini girin: siralama = kord.x kord.y kutle karakter vx vy\n";
    std::cin >> x2 >> y2 >> m2 >> c2 >> vx2 >> vy2;
    dots nokta2(x2,y2,m2,c2,vx2,vy2);
    system("cls");
    std::cout << "Sira sira zaman ve G sabiti bilgilerini girin: siralama = zaman G\n";
    std::cin >> time;
    std::cin >> G;
    system("cls");
    sim(nokta1,nokta2,time,G);
    }
}

float dist(dots& p1,dots& p2){
        float d = sqrt(pow((p1.Cx-p2.Cx),2)+pow((p1.Cy-p2.Cy),2));
            if(d < 1.0f)
                return 1.0f;
        else
            return d;
}

void sim(dots& p1,dots& p2,float time,float G){
    const float DifTime = time;
    float time_step = 0;
    while(1){
        if(k1==0)
            system("cls");
        updateConsoleDimensions(W,H);
        calculate(p1,p2,time,G);
        move(p1,time);
        move(p2,time);
        print(p1,p1.c);
        print(p2,p2.c);
        time_step+=DifTime;
        Sleep(50);
    }
}

void move(dots& p,float time){
    p.Cx += p.Vx * time;
    p.Cy += p.Vy * time;
    if(p.Cx >= W - 1) { 
        p.Cx = W - 2; 
        p.Vx *= -1;   
    } 
    else if (p.Cx <= 0) {
        p.Cx = 1;     
        p.Vx *= -1;
    }
    if(p.Cy >= H - 1) { 
        p.Cy = H - 2; 
        p.Vy *= -1; 
    } 
    else if (p.Cy <= 0) {
        p.Cy = 1;     
        p.Vy *= -1; 
    }
}

void calculate(dots& p1,dots& p2,float time,float G){
    p1.Fx = 0;
    p1.Fy = 0;
    p2.Fx = 0;
    p2.Fy = 0;
    float F = (G*p1.mass*p2.mass)/(dist(p1,p2)*dist(p1,p2));
    p1.Fx=(abs(p1.Cx-p2.Cx)/dist(p1,p2))*F;
    p2.Fx=(abs(p1.Cx-p2.Cx)/dist(p1,p2))*F;
    p1.Fy=(abs(p1.Cy-p2.Cy)/dist(p1,p2))*F;
    p2.Fy=(abs(p1.Cy-p2.Cy)/dist(p1,p2))*F;
    if(p1.Cx<p2.Cx)
        p2.Fx*=-1;
    else    
        p1.Fx*=-1;
    if(p1.Cy<p2.Cy)
        p2.Fy*=-1;
    else
        p1.Fy*=-1;
    p1.Vx = (p1.Fx*time + p1.mass*p1.Vx)/p1.mass;
    p1.Vy = (p1.Fy*time + p1.mass*p1.Vy)/p1.mass;
    p2.Vx = (p2.Fx*time + p2.mass*p2.Vx)/p2.mass;
    p2.Vy = (p2.Fy*time + p2.mass*p2.Vy)/p2.mass;
}

void print(dots& p,char ch){
    COORD coord;
    coord.X = (int)p.Cx;
    coord.Y = (int)p.Cy;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    std::cout << ch;
}

void updateConsoleDimensions(int& width, int& height){
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if(GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
        width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    } else {
        width = 80;
        height = 24;
    }
}