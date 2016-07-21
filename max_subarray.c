double max_subArray(double A[])
{
  int len = len(A);
  double max = 0, sum = 0;
  int i = 0;
  for(i = 0; i< len; i++)
  {
    sum += A[i];
    if sum < 0:
	sum = 0;
    if sum > max:
	max = sum;
  }
  return max;
}
