#ifndef STATUS_H
#define STATUS_H
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;

#define PressEnter \
{\
		fflush(stdin);\
		printf("Press Enter ...");\
		getchar();\
		fflush(stdin);\
}


#endif
