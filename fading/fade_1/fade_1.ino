const int LED = 10;

void setup()
{
}

void loop()
{
  float in, out;
  
  for (in = 0; in < 6.283; in = in + 0.001)
  //for (in = 0; in < 6.283; in = in + 0.01)
  //for (in = 0; in < 6.283; in = in + 0.0001)
  {
    out = sin(in) * 127.5 + 127.5;
    analogWrite(LED,out);
  }
}
