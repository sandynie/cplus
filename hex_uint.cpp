#include <iostream>
using namespace std;
static void
id_to_hex(char * str, unsigned int id) {
	int i;
	static char hex[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
	str[0] = ':';
	for (i=0;i<8;i++) {
		str[i+1] = hex[(id >> ((7-i) * 4))&0xf];
	}
	str[9] = '\0';
}


static void hex_to_id(char*str,unsigned int& id){
	int i;
	id=0;
	for (i=0;i<8;i++){
			if (str[i]>='0' && str[i]<='9')
			{
				id |=((str[i]-'0')<<(7-i)*4);
			}else if (str[i]>='A' && str[i]<='F') 
			{
				id |=((str[i]-'A'+10)<<(7-i)*4);
			}else if (str[i]>='a' && str[i]<='f')
			{
				id |=((str[i]-'a'+10)<<(7-i)*4);
			}		
	}
}
int main()
{
	char str[10];
	id_to_hex(str,30);
	cout<<str<<endl;
	unsigned id = 0;
	hex_to_id("0000001E",id);
	cout<<id<<endl;
	system("pause");
	return 0;
}
