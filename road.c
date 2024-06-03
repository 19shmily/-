#include<stdio.h>
#define N 3
float X = 0, Y = 0;//坐标系原点

void servo_control(float x_dif, float y_dif)
{
    //***********在下方基于坐标（X，Y）和差值dif进行舵机移动控制**********

    return;
}

void make_move(float x1, float y1, float x2, float y2)
{
    X = x1;
    Y = y1;
    float tmp1 = (x2 - X) / N;
    float tmp2 = (y2 - Y) / N;
    for (int n = 1; n < N; n++)
    {
        servo_control(n * tmp1, n * tmp2);
        printf("%f %f\n", X+n * tmp1,Y+n * tmp2);
    }
//使舵机最后可以定位到终点坐标即（x2，y2）
    servo_control(x2 - X, y2 - Y);
    printf("%f %f\n", X + x2 - X, Y + y2 - Y);
    //if (x1 == x2)//是一条平行于y轴的直线
    //{
    //    float tmp = (y2 - Y) / N;
    //    for (int n = 1; n < N; n++)
    //    {
    //        servo_control(0, n * tmp);
    //        //printf("%d %d\n", 0, n*tmp);
    //    }
    //}
//    else if (y1 == y2)//是一条平行于x轴的直线
//    {
//        float tmp = (x2 - X) / N;
//        for (int n = 1; n < N; n++)
//        {
//            servo_control(n * tmp, 0);
//            //printf("%d %d\n", n*tmp, 0);
//        }
//    }
//    else
//    {
//        float k = (y2 - Y) / (x2 - X);
//        // 使用其中一个点计算截距
//        float b = Y - k * X;
//      //  printf("%f %f\n", k, b);
//        float tmp1 = (x2 - X) / N;
//        for (int n = 1; n < N; n++)
//        {
//            y1 = k * x1 + b;
//            X = x1; Y = y1;
//            servo_control();
//          //  printf("%lf %lf\n", X, Y);
//        }
//    }
//    X = x2; Y = y2;
////使舵机最后可以定位到终点坐标即（x2，y2）
//    servo_control();
//    //printf("%d %d\n", X, Y);
    return;
}

void circle_move(int l_up_x, int l_up_y,
	int r_up_x, int r_up_y,
	int r_down_x, int r_doon_y,
	int l_down_x, int l_down_y,
    int red_x, int red_y)
{
    make_move(red_x, red_y, l_up_x, l_up_y);
    make_move(l_up_x, l_up_y, r_up_x, r_up_y);
    make_move(r_up_x, r_up_y, r_down_x, r_doon_y);
    make_move(r_down_x, r_doon_y, l_down_x, l_down_y);
    make_move(l_down_x, l_down_y, l_up_x, l_up_y);
}

//int main() {
//    circle_move(0, 15, 20, 0, 35, 20, 15, 35,11,22);
//    return 0;
//}

