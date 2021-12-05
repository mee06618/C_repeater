#include <stdio.h>
#include <stdlib.h>  

typedef struct {
	int arrName;
	int isActive;

}textArray;
int main(void)
{
	FILE* fp = NULL;
	int n = 0;	// number of test cases
	int row = 0;	// number of rows
	int col = 0;	// number of cols
	int result = 0;	// number of error
	if((fp = fopen("sample_input.txt","r"))==NULL)
	{
		fprintf(stderr,"No file exist!\n");
		return -1;
	}
	fscanf_s(fp,"%d",&n);
	while(n-->0)
	{
		result = 0;
		fscanf_s(fp,"%d",&row);
		fscanf_s(fp, "%d", &col);
		printf(" %d행 %d열\n", row, col);
		
		char** arr;
		arr = (char**)malloc(sizeof(char*) * row);
		arr[0] = (char*)malloc(sizeof(char) * col * row);
		for (int i = 1; i < row; i++) {
			arr[i] = arr[i - 1] + col;
		}
		
	
		fscanf_s(fp, "\n");
		for (int i = 0; i < row; i++) {
			for (int j = 0; j< col; j++) {
				fscanf_s(fp,"%c",&arr[i][j]);
			}
			fscanf_s(fp, "\n");
		}
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				printf("%c", arr[i][j]);
			}

			printf("\n");
		}
		printf("변환\n");
		
		for (int i = 0; i < row; i++) {
			
			for (int j = 0; j < col; j++) {
				int count = 0;
				switch (arr[i][j]) {
					case 'A':
						count = 3;
						break;
					case 'B':
						count = 2;
						break;
					case 'C':
						count = 1;
						break;
				}
				
				for (int k = count; k > 0; k--) {
					if(i-k>=0 && arr[i-k][j]=='H')
						arr[i - k][j] = 'o';
					if(i+k<row && arr[i + k][j] == 'H')
						arr[i + k][j] = 'o';
					if (j - k >= 0 && arr[i][j - k] == 'H')
						arr[i][j - k] = 'o';
					if (j + k < col && arr[i][j + k] == 'H')
						arr[i][j + k] = 'o';
						
				}
				
				
			}
			
		}

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				printf("%c", arr[i][j]);
				if(arr[i][j]=='H')
					result++;
				}

			printf("\n");
		}
		free(arr[0]);
		free(arr);
		printf("%d\n", result);
	}
		


	
	
	fclose(fp);
	return 0;	
}
