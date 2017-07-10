#include<stdio.h>

int main()
{
		int c;
		int nb=0,nl=0,nec=0,nd=0,ncc=0;
		while((c=getchar())!=EOF)
		{
				if(c==' '||c=='\t')
				{
						nb++;
				}
				else if(c=='\n')
				{
						nl++;
				}
				else if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
				{
						nec++;
				}
				else if(c>='0'&&c<='9')
				{
						nd++;
				}
				else if(c>=0x81&&c<=0xfe)
				{
						if((c=getchar())!=EOF)
						{
								if((c>=0x40&&c<=0x7e)||(c>=0xa1&&c<=0xfe))
								{
										ncc++;
								}
						}
				}
		}
		printf("%d of blanks\n",nb);
		printf("%d of lines\n",nl);
		printf("%d of English charactors\n",nec);
		printf("%d of digits\n",nd);
		printf("%d of Chinese charactors\n",ncc);
}
