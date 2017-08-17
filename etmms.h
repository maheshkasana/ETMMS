#include<iostream>
#include<map>

using namespace std;

//new
typedef struct user_real_time_data
{
	int status_user,auto_mann_dec_stat_user,color_code_user,user_limit_value;
	char kno[40];
	double avg_use;
	double real_time_data;
	struct user_real_time_data *next_user;
}user_real_time_data;


//new
typedef struct step_trans_list
{
	int status_sdt, auto_mann_dec_stat_sdt, color_code_sdt, total_user,sdt_diff_value_limit;
	char sdt_id[30];
	double *user_data;
	double volt, sdt_out, user_totl, diff_pow,avg_volt,avg_sdt_out,avg_user_totl,avg_diff_pow;
	struct step_trans_list *next_sdt;
	struct user_real_time_data *user_list;
}step_trans_list;

//new
typedef struct sub_station_list
{
	char sub_id[20];
	int total_sdt, color_code;
	double pow_out, pow_con, volt;
	struct sub_station_list *next_sub;
	struct step_trans_list *sdt_list;
}sub_station_list;

//gloable variable to access real time data only decelaration
extern sub_station_list *real_time_data_linklist;


//new
typedef struct map_store_strct
{
	int power_status_change_count, volt_status_change_count,conn_setup_time,family_status,connection_type;
	double rate_power,rate_volt, last_power, last_volt, last_avg_power, last_avg_volt, rate_avg_power, rate_avg_volt;

}map_store_strct;

//extern variable for storage and management of just previous data
extern map<char*,map_store_strct*> map_store;

//new
bool validate_login_user(char *);
//new
bool validate_login_admin(char *);
//new
int registration_user(char *);


//new
void async_function_graph_data();

int color_status(double, double);

//new
int register_new_sdt_fun(char *);
//new
void print_central_datastructure();
