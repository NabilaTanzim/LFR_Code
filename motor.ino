void motor(int a, int b)
{
  if (a > 0)
  {
    digitalWrite(OUT1, 1);
    digitalWrite(OUT2, 0);
  }
  else
  {
    a = -(a);
    digitalWrite(OUT1, 0);
    digitalWrite(OUT2, 1);
  }

  if (b > 0)
  {
    digitalWrite(OUT3, 1);
    digitalWrite(OUT4, 0);
  }
  else
  {
    b = -(b);
    digitalWrite(OUT3, 0);
    digitalWrite(OUT4, 1);
  }

  if(a > 250) a = 250;
  if(b > 250) b = 250;

  analogWrite(ENA, a);
  analogWrite(ENB, b);
}