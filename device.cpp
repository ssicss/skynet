#include<stdio.h>
#include<stdlib.h>
#include "device.h"


struct g_output_inf_t *g_output_inf = NULL;
struct g_input_inf_t  *g_input_inf  = NULL;




enum _opt_flag init_obj( void )
{

	g_input_inf = (struct g_input_inf_t  *)malloc(sizeof(struct g_input_inf_t));
	if(g_input_inf == NULL) {return FAIL;}
	else
	{
		g_input_inf->id = 0;
		g_input_inf->name = NULL;
		g_input_inf->next = NULL;
		
		return SUCCESS;
	}

}


enum _opt_flag intstall_obj(struct g_input_inf_t  *t)
{
	struct g_input_inf_t  *p = g_input_inf->next;
	struct g_input_inf_t  *q = g_input_inf;
	

	if(t == NULL)  return FAIL;
	
	while(p!= NULL)
	{
		q = p;
		p = p->next;
	}

	q->next = t;
	t->next = NULL;

	return SUCCESS;
}

void uninstall_obj(int id)
{
	struct g_input_inf_t  *p = g_input_inf->next;
	struct g_input_inf_t  *q = g_input_inf;

	while(p!= NULL)
	{
		if(id == p->id)
		{
			q->next = p->next;
			goto end;
		}
		q = p;
		p = p->next;
	}

end: ;

}

void list_obj(void)
{
	struct g_input_inf_t  *p = g_input_inf->next;
	struct g_input_inf_t  *q = g_input_inf;

	while(p != NULL)
	{

		printf("----------start-----------\n");
		printf("name:%s\n",p->name);
		printf("id:%d\n",p->id);
		printf("----------end-------------\n");

		q = p;
		p = p->next;
	}

	
}

enum _opt_flag obj_init(void)
{
	struct g_input_inf_t  *p = g_input_inf->next;
	struct g_input_inf_t  *q = g_input_inf;

	while(p!= NULL)
	{
		p->init();
		return SUCCESS;
		q = p;
		p = p->next;
	}
	return FAIL;
}


