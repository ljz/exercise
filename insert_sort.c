void Insert_sort(double A[])
	{
		int len = strlen(A)/strlen(A[0]);
		for(int i = 0; i< len; i++)
			{
				int key = A[i];
				int j = i-1;
				int k = i;
				while(A[j]>key&&j>0&&k>j)
				{
					A[k] = A[k-1];
					k--;
				}
				A[j] = key;
			}
	



	}
