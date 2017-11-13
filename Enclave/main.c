int  myprintf(const char*, ...);
int main(){

	int ret = printf(0x900000100, 123, 456, 789, 1010);
	printf(0x900000100, ret, 456, 789, 1010);

	return 0;
}


int main1(){

	//myprintf("Hello world\n");
	return 0;
}
