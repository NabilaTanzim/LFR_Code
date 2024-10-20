#define ENA  5
#define OUT1 6
#define OUT2 7
#define OUT3 8
#define OUT4 9
#define ENB  10

int s[5], sum, avg;
int base[5] = { 1, 2, 4, 8, 16};
int position[5] = { 1, 2, 3, 4, 5};
int threshold = 512; //adjustable
int sensor;

int lsp = 25, rsp = 25, tsp = 150;  // adjustable
int lbase = 200;
int rbase = 200;
int lmotor, rmotor;
float line_prop = 2; //adjustable
double kp = 50, kd = 1000, ki = 0.01; //adjustable
int PID;
int error, last_error;
int pos;
char turn = 's';

void setup() 
{
  pinMode(OUT1, OUTPUT);
  pinMode(OUT2, OUTPUT);
  pinMode(OUT3, OUTPUT);
  pinMode(OUT4, OUTPUT);
  //motor(10 * lsp, 10 * rsp);
  line_follow();
}

void loop() 
{
  //PID_follow();
  line_follow();
}












