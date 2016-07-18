
#ifndef _DEVICE_H
#define _DEVICE_H




struct g_output_inf_t {
	char * name;
	int    id;
	struct opt_function{
		void (*init)(void);
		int  (*opt)(int parameter);
		int  (*destory)(int parameter);
	};
	struct g_output_inf_t * next;	
};



struct g_input_inf_t {
	char * name;
	int    id;

	void (*init)(void);
	int  (*opt)(int parameter);
	int  (*destory)(int parameter);
	
	struct g_input_inf_t * next;	
};



enum _opt_flag {
	SUCCESS = 0,
	FAIL    = 1,
};


enum _opt_flag init_obj( void );
enum _opt_flag intstall_obj(struct g_input_inf_t  *t);
void uninstall_obj(int id);
void list_obj(void);
enum _opt_flag obj_init(void);





#endif


