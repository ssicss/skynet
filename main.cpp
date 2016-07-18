#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <time.h>

#include "device.h"








void init_std(void)
{
}



struct g_input_inf_t *obj_add;
struct g_input_inf_t *tmp_opt = NULL;





struct g_process_info{
	int id;
	char buf[256];
};

struct g_out_info{
	int id;
	char buf[256];
};



g_process_info gprocess;
g_out_info     goutinfo;



void wait_iput(void)
{
	char tmp_info[256] = {0}; 
	int i = 0;
	
	scanf("%s",&tmp_info);

	for(i=0; i<256; i++)
		gprocess.buf[i] = tmp_info[i];

}


enum mood_pra{
	HAPPY = 1,
	ANGRY = 2,
	SAD   = 3,
	DEFAULT = 0,
};

enum mood_pra g_mood = DEFAULT;


struct match_tab{
	char *mm0;
	char *mm1;
	char *mm2;
	char *mm3;
	char *mm4;
};

struct match_tab tab = {
"高兴",
"快乐",
"兴奋",
"激动",
"笑"
};


struct out_tab_1{
	char *mm0;
	char *mm1;
	char *mm2;
	char *mm3;
	char *mm4;
};

struct out_tab_1 tab2 = {
"你高兴就好啊",
"我也替你高兴",
"这么好的事能叫上我吗",
"你太有才了",
"与君同乐"
};






void process(void)
{

		if(strstr(gprocess.buf,tab.mm0))
		{
			g_mood = HAPPY;
		}
		else if(strstr(gprocess.buf,tab.mm1))
		{
			g_mood = HAPPY;
		}
		else if(strstr(gprocess.buf,tab.mm2))
		{
			g_mood = HAPPY;
		}
		else if(strstr(gprocess.buf,tab.mm3))
		{
			g_mood = HAPPY;
		}
		else if(strstr(gprocess.buf,tab.mm4))
		{
			g_mood = HAPPY;
		}
		else
		{
			g_mood = DEFAULT;
		}




		if(g_mood == HAPPY)
		{
			srand(time(NULL));
			switch(rand()%5)
			{
				case 0:  strcpy(goutinfo.buf,tab2.mm0); break;
				case 1:  strcpy(goutinfo.buf,tab2.mm1); break;
				case 2:  strcpy(goutinfo.buf,tab2.mm2); break;
				case 3:  strcpy(goutinfo.buf,tab2.mm3); break;
				case 4:  strcpy(goutinfo.buf,tab2.mm4); break;

			}

		}else
		{
			strcpy(goutinfo.buf,"不太明白你在说什么");

		}



		
}


void wait_output(void)
{
	
	printf("小马:%s\n",goutinfo.buf);
	
}









void main(void)
{
	int funcation  = 0;
	char *tmp_name  =NULL;
	int  tmp_id    = 0;

	int i = 0;


//初使化链表
	if(init_obj())
	{
		printf("init obj failed,halt!\n");
		for(;;);
	}


//添加输入输出设备
	obj_add = (struct g_input_inf_t *)malloc(sizeof(struct g_input_inf_t));
	obj_add->name = "standard input";
	obj_add->id = 1;
	obj_add->init = init_std;
	
	intstall_obj(obj_add);


//初使化设备

	obj_init();
	

	printf("list obj\n");
	list_obj();

	printf("----------sys load---------------\n");
//loop
	for(;;)
	{
		wait_iput();
		process();
		wait_output();
	}

}













