int myAtoi(char * str){
    int i, i_bit, num;
	int pos_neg = 0;
    num = 0;

    // skip empty character
    for (i = 0; str[i] == ' ' && str[i] != '\0'; i++);

    // validity
    if ((str[i] != '+' && str[i] != '-' && (str[i] > '9' || str[i] < '0')) || str[i] == '\0')
        return 0;

    // a num(continuous numerical part) and tail
	if (str[i] == '+') {
		pos_neg = 1;
		i++;
	}
	else if (str[i] == '-') {
		pos_neg = -1;
		i++;
	}
	else pos_neg = 1;
	
	printf("%d\n", INT_MIN);
    for (; str[i] != '\0' && (str[i] >= '0' && str[i] <= '9') ; i++) {
        i_bit = str[i] - '0';
		// overflow
		// 10*num overflow
		// i_bit overflow
		if (pos_neg == 1) {
				if (num > INT_MAX / 10) {
						return INT_MAX;
				}
				else if (num == INT_MAX/10 && i_bit > INT_MAX % 10)
						return INT_MAX;
		}
		else {
				if (num > -1*(INT_MIN / 10)) {
						puts("here1");
						return INT_MIN;
				}
				//else if (num == -1*(INT_MIN/10) && i_bit > -1*(INT_MIN % 10))
                else if (num == -1*(INT_MIN/10) && i_bit >= -1*(INT_MIN % 10))
				{
						puts("here2");
						return INT_MIN;
				}
		}


        num = 10*num + i_bit;
    }
    return num*pos_neg;

}