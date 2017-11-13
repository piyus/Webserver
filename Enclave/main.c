int  myprintf(const char*, ...);
int main(){
	char  name[100];
	char fmt[] = "%s";
	scanf(fmt, name);
	int ret = printf(0x900000100, 123, 456, 789, 1010, name);
	printf(0x900000100, ret, 456, 789, 1010, name);

	return 0;
}


int main1(){

	//myprintf("Hello world\n");
	return 0;
}
