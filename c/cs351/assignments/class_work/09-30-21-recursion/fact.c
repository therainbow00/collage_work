unsigned long fact(int num)
{
  if (num < 2) return 1;
  return num * fact(num - 1);
}
