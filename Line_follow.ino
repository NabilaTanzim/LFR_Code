void line_follow()
{
while (1) 
  {
  reading();
  if(sum == 0) //sharp turn execution
  {
      if (turn != 's') 
      {
        delay(200);                                    //adjust it to your needs!
        (turn == 'r') ? motor(tsp, -tsp) : motor(-tsp, tsp);  //tsp means turn speed. adjust it to your needs!
        while (!s[2]) reading();                              //keep turning untill the middle sensors find any line
        turn = 's';                                           //reset the flag so that robot won't do any fake turn
      }
  }
  else if(sum == 1)
  {
    if(sensor == 0b00100)
    {  
      if(pos != 0)
      {
        (pos > 0)? motor(-10 * lsp, 10 * rsp) : motor(10 * lsp, -10 * rsp);
        delay(abs(pos) * 5); //adjustable
      }
      motor(10 * lsp, 10 * rsp);
    }

    //right side turn correction
    if(sensor == 0b00110)
    {
      if(pos < 1) pos = 1;
       motor(10 * lsp, 7 * rsp); //adjustable proportion ration
    }
    else if(sensor == 0b00010)
    {
      if(pos < 2) pos = 2;
      motor(10 * lsp, (7 - line_prop) * rsp);
    }
    else if(sensor == 0b00011)
    {
      if(pos < 3) pos = 3;
      motor(10 * lsp, (7 - 2*line_prop) * rsp);
    }
    else if(sensor == 0b00001)
    {
      if(pos < 4) pos = 4;
      motor(10 * lsp, 0 * rsp);
    }

    //left side turn correction
    if(sensor == 0b01100)
    {
      if(pos > -1) pos = -1;
      motor(7 * lsp, 10 * rsp);
    }
    else if(sensor == 0b01000)
    {
      if(pos > -2) pos = -2;
      motor((7 - line_prop) * lsp, 10 * rsp);
    }
    else if(sensor == 0b11000)
    {
      if(pos > -3) pos = -3;
      motor((7 - 2*line_prop) * lsp, 10 * rsp);
    }
    else if(sensor == 0b10000)
    {
      if(pos > -4) pos = -4;
      motor(0 * lsp, 10 * rsp);
    }
  }
  else if(sum >= 2 && sum <= 4) //sharp turn
  {
    if ((s[2]) && s[0] && !s[4]) turn = 'r';
    if ((s[2]) && s[4] && !s[0]) turn = 'l';
  }
  else if(sum == 5)
  {
    delay(200);  //adjust the delay to your need
      reading();
      if (sum == 5) //detection of stop point
      {
        motor(0, 0);
        while (sum == 5) reading();
      } 
      else if (sum == 0) turn = 'r';  //detection of T-section
    }
  }
}









