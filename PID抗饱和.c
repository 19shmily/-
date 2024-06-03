#include<stdio.h>
#include<stdlib.h>
int target_x = 0, now_x = 0;
int target_y = 0, now_y = 0;
struct _pid {
    float SetSpeed;            //�����趨ֵ
    float ActualSpeed;        //����ʵ��ֵ
    float err;                //����ƫ��ֵ
    float err_last;            //������һ��ƫ��ֵ
    float Kp, Ki, Kd;            //������������֡�΢��ϵ��
    float voltage;            //�����ѹֵ������ִ�����ı�����
    float integral;            //�������ֵ
    float umax;
    float umin;
}pid_x,pid_y;

void PID_init(struct _pid* pid) {
    pid->SetSpeed = 0.0;
    pid->ActualSpeed = 0.0;
    pid->err = 0.0;
    pid->err_last = 0.0;
    pid->voltage = 0.0;
    pid->integral = 0.0;
    pid->Kp = 0.2;
    pid->Ki = 0.1;       //ע�⣬���ϼ�����ȣ�����Ӵ��˻��ֻ��ڵ�ֵ
    pid->Kd = 0.2;
    pid->umax = 400;
    pid->umin = -200;
}
float PID_realize(struct _pid* pid,float speed) {
    int index;
    pid->SetSpeed = speed;
    pid->err = pid->SetSpeed - pid->ActualSpeed;

    if (pid->ActualSpeed > pid->umax)  //��ɫ��ɫ��ʾ�����ֱ��͵�ʵ��
    {

        if (abs(pid->err) > 200)      //��ɫ��עΪ���ַ������
        {
            index = 0;
        }
        else {
            index = 1;
            if (pid->err < 0)
            {
                pid->integral += pid->err;
            }
        }
    }
    else if (pid->ActualSpeed < pid->umin) {
        if (abs(pid->err) > 200)      //���ַ������
        {
            index = 0;
        }
        else {
            index = 1;
            if (pid->err > 0)
            {
                pid->integral += pid->err;
            }
        }
    }
    else {
        if (abs(pid->err) > 200)                    //���ַ������
        {
            index = 0;
        }
        else {
            index = 1;
            pid->integral += pid->err;
        }
    }

    pid->voltage = pid->Kp * pid->err + index * pid->Ki * pid->integral / 2 + pid->Kd * (pid->err - pid->err_last);  //���λ���
    pid->err_last = pid->err;
    pid->ActualSpeed = pid->voltage * 1.0;
    return pid->ActualSpeed;
}

//int main() {
//    PID_init(&pid_x);
//    int count = 0;
//    target_x = 73;
//    now_x = 116;
//    while (count < 1000)
//    {
//        float speed = PID_realize(&pid_x, target_x - now_x);
//        printf("%f\n", speed);
//        count++;
//    }
//    return 0;
//}