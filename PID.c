//#include<stdio.h>
//#include<stdlib.h>
//
//int target_x = 0,now_x = 0;
//int target_y = 0, now_y = 0;
//struct _pid {
//    float SetSpeed;            //定义设定值
//    float ActualSpeed;        //定义实际值
//    float err;                //定义偏差值
//    float err_next;            //定义上一个偏差值
//    float err_last;            //定义最上前的偏差值
//    float Kp, Ki, Kd;            //定义比例、积分、微分系数
//}pid_x, pid_y;
//
//void PID_init(struct _pid *pid) {
//    pid->SetSpeed = 0.0;
//    pid->ActualSpeed = 0.0;
//    pid->err = 0.0;
//    pid->err_last = 0.0;
//    pid->err_next = 0.0;
//    pid->Kp = 0.2;
//    pid->Ki = 0.015;
//    pid->Kd = 0.2;
//
//}
//
//float PID_realize(struct _pid* pid, float speed) {
//    pid->SetSpeed = speed;
//    pid->err = pid->SetSpeed - pid->ActualSpeed;
//    float incrementSpeed = pid->Kp * (pid->err - pid->err_next) + pid->Ki * pid->err + pid->Kd * (pid->err - 2 * pid->err_next + pid->err_last);
//    pid->ActualSpeed += incrementSpeed;
//    pid->err_last = pid->err_next;
//    pid->err_next = pid->err;
//    return pid->ActualSpeed;
//}

//int main() {
//    PID_init(&pid_x);
//    int count = 0;
//    target_x = 73;
//    now_x = 116;
//    while (count < 1000)
//    {
//        float speed = PID_realize(&pid_x,target_x - now_x);
//        printf("%f\n", speed);
//        count++;
//    }
//    return 0;
//}