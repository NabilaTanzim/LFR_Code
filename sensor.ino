void reading()
{
  sensor = 0;
  for(byte i = 0; i < 5; i++)
  {
    s[i] = analogRead[i];
    (s[i] > threshold)? s[i] = 1 : s[i] = 0;
    sensor += s[i] * base[i];
  }
}

void PID_reading()
{
  sensor = 0;
  sum = 0;
  for(byte i = 0; i < 5; i++)
  {
    s[i] = analogRead[i];
    (s[i] > threshold)? s[i] = 1 : s[i] = 0;
    sensor += s[i] * position[i];
    sum +=s[i];
  }
  if(sum) avg = sensor / sum; line_follow();
}
