struct numbers{ 
	int a;
        int b;
};

program SUB_PROG{ version SUB_VERS{
	int sub(numbers)=1;
	}=1;
}=0x12345678;
