//Program to to read and dispay the contents of that file

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<io.h>
#include<fcntl.h>

int main()
{
	int fd = 0, iRet = 0;
	char Fname[30];
	char Buffer[10];  //Mug
	
	printf("Enter file name\n");
	scanf("%s",Fname);
	
	fd = open(Fname,O_RDONLY);  //Only to read the file 
	
	if(fd == -1)
	{
		printf("Unable to open file\n");
		return -1;  //Return to OS
	}
	else
	{
		printf("File Sucessfully opend with FD : %d\n",fd);
	}
	
	printf("Data from file is : \n");
	
	while((iRet = read(fd,Buffer,sizeof(Buffer))) != 0)
	{
		write(1,Buffer,iRet);
	}
	
	close(fd);
	
	return 0;
}