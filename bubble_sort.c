void bubble_sort(double A[])
{
	int len = strlen(A)/strlen(A[0]);
	int i = 0;
	int j = 0;
	int temp;
	for(;i<len; i++)
		{
			for(j = i; j>=0; j--)
			{
				if(A[j]>A[j-1])
				{
					temp = A[j];
					A[j] = A[j-1];
					A[j-1] = temp;	
				} 

			}
		}


}
