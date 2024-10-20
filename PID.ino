void PID_follow()
{
  reading();
  if (sum == 0) 
  {
    if (turn != 's') 
    {
      delay(10);
      (turn == 'r') ? motor(tsp, -tsp) : motor(-tsp, tsp);
      while (!s[2]) reading();
      turn = 's';
    }
  }

PID_reading();
  error = 3 - avg;
  PID = error * kp + (error - last_error) * kd;
  last_error = error;

  rmotor = rbase - PID;
  lmotor = lbase + PID;

  motor(lmotor, rmotor);

  if (s[0] && !s[4]) turn = 'r';
  if (s[4] && !s[0]) turn = 'l';

  else if (sum == 5) 
  {
    delay(200);
    reading();
    if (sum == 5) 
    {
      motor(0, 0);
      while (sum == 5) reading();
    }
    else if (sum == 0) turn = 'r';
  }
}