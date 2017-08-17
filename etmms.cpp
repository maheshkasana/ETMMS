
#include "etmms.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<fstream>
#include<iostream>
#include <sstream>
#include <cstring>
#include <time.h>
#include<windows.h>
#include<map>

using namespace std;


//define
sub_station_list *real_time_data_linklist;

//map<char[], double> storage_map;
map<char*, map_store_strct*> map_store;


//new
int register_new_sdt_fun(char *url_data)
{

	char data[8][100];

	int i=0, j=0,k=0,l=0;
	l = (int)strlen(url_data);
	while (url_data[i] != '\0' && i <= l)
	{
		if (url_data[i] == '&')
		{
			data[j][k] = '\0';
			j++;
			k = 0;
			i++;
		}
		else
		{
			data[j][k] = url_data[i];
			k++;
			i++;
		}
	}

	char sdt_id[40];
	strcpy_s(sdt_id, data[0]);
	strcat_s(sdt_id, "_");
	strcat_s(sdt_id, data[1]);
	strcat_s(sdt_id, "\0\n");


	char file_path[500];
	strcpy_s(file_path, "C:\\xampp\\htdocs\\etmms\\realdata\\");
	strcat_s(file_path, data[0]);
	strcat_s(file_path, ".txt");

	char temp_sdt_id[100];
	//check already present
	ifstream reg_check_file_sdt;
	reg_check_file_sdt.open(file_path);
	if (!reg_check_file_sdt.fail())
	{
		while (!reg_check_file_sdt.eof())
		{
			reg_check_file_sdt >> temp_sdt_id;
			//printf("\n%s\t%s", temp_sdt_id, sdt_id);
			if (!strcmp(sdt_id, temp_sdt_id))
			{
				reg_check_file_sdt.close();
				return 2;
			}
		}
	}
	else
	{
		reg_check_file_sdt.close();
		return 0; //failed to register sdt
	}




	//open that substation file and add sdt under that
	ofstream reg_add_sdt_write;	
	reg_add_sdt_write.open(file_path, ios::app);
	if (!reg_add_sdt_write.fail())
	{
		reg_add_sdt_write << sdt_id << endl;
		reg_add_sdt_write.close();
	}	
	else
	{
		reg_add_sdt_write.close();
		return 0; //failed to register sdt
	}

	
	//add sdt data in the file
	ofstream reg_add_sdt_all_sdt;

	reg_add_sdt_all_sdt.open("C:\\xampp\\htdocs\\etmms\\realdata\\all_sdt_data.txt", ios::app);
	if (!reg_add_sdt_all_sdt.fail())
	{
		reg_add_sdt_all_sdt << "----------" << endl;
		reg_add_sdt_all_sdt << sdt_id << endl;
		for (i = 2; i < j; i++)
			reg_add_sdt_all_sdt << data[i] << endl;
		reg_add_sdt_all_sdt.close();
	}
	else
	{
		reg_add_sdt_all_sdt.close();
		return 0; //failed to register sdt
	}

	return 1;
}



//new
int registration_user(char *url_data)
{
	char data[25][100];

	int i = 0, j = 0, k = 0, l = 0;
	l = (int)strlen(url_data);
	while (url_data[i] != '\0' && i <= l)
	{
		if (url_data[i] == '&')
		{
			data[j][k] = '\0';
			j++;
			k = 0;
			i++;
			//printf("\n%s", data[j - 1]);
		}
		else
		{
			data[j][k] = url_data[i];
			k++;
			i++;
		}
	}

	char temp_data[50];
	strcpy_s(temp_data, data[0]);
	char *ptr = strrchr(temp_data, '_');
	*ptr = '\0';

	/*
	printf("\n%s", temp_data);
	for (i = 0; i<j; i++)
	printf("\n%s", data[i]);
	return 0;
	*/

	char file_path[500];
	strcpy_s(file_path, "C:\\xampp\\htdocs\\etmms\\realdata\\");
	strcat_s(file_path, temp_data);
	strcat_s(file_path, ".txt");

	//printf("\n%s",file_path);

	char temp_sdt_id[100];
	//check already present
	ifstream reg_check_file_sdt;
	reg_check_file_sdt.open(file_path);
	if (!reg_check_file_sdt.fail())
	{
		while (!reg_check_file_sdt.eof())
		{
			reg_check_file_sdt >> temp_sdt_id;
			//printf("\n%s\t%s", temp_sdt_id, data[0]);
			if (!strcmp(data[0], temp_sdt_id))
			{
				reg_check_file_sdt.close();
				return 2;
			}
		}
	}
	else
	{
		reg_check_file_sdt.close();
		return 0; //failed to register sdt
	}


	//open that substation file and add sdt under that
	ofstream reg_add_sdt_write;
	reg_add_sdt_write.open(file_path, ios::app);
	if (!reg_add_sdt_write.fail())
	{
		reg_add_sdt_write << data[0] << endl;
		reg_add_sdt_write.close();
	}
	else
	{
		reg_add_sdt_write.close();
		return 0; //failed to register sdt
	}


	//add sdt data in the file
	ofstream reg_add_sdt_all_sdt;

	reg_add_sdt_all_sdt.open("C:\\xampp\\htdocs\\etmms\\registration_file.txt", ios::app);
	if (!reg_add_sdt_all_sdt.fail())
	{
		reg_add_sdt_all_sdt << "----------" << endl;
		for (i = 0; i < j; i++)
			reg_add_sdt_all_sdt << data[i] << endl;
		reg_add_sdt_all_sdt.close();
	}
	else
	{
		reg_add_sdt_all_sdt.close();
		return 0; //failed to register sdt
	}

	return 1;
}



//new
bool validate_login_user(char *url_data)
{
	char data[5][100];
	char *ptr = strchr(url_data, '&');
	*ptr = '\0';
	strcpy_s(data[0],url_data);
	ptr++;
	strcpy_s(data[1], ptr);
	ptr = strchr(data[1], '&');
	*ptr = '\0';

	char temp_id[100],temp_psw[100];
	ifstream reg_check_file_sdt;
	reg_check_file_sdt.open("C:\\xampp\\htdocs\\etmms\\registration_file.txt");
	if (!reg_check_file_sdt.fail())
	{
		while (!reg_check_file_sdt.eof())
		{
			reg_check_file_sdt >> temp_id;
			if (strstr(temp_id,"--------" ))
			{
				reg_check_file_sdt >> temp_id;
				reg_check_file_sdt >> temp_psw;
				//printf("\ntt %s\t%s", temp_id, temp_psw);
				if (!strcmp(temp_id, data[0]) && !strcmp(temp_psw, data[1]))
				{
					reg_check_file_sdt.close();
					return true;

				}
			}
		}
	}
	else
	{
		reg_check_file_sdt.close();
		return false; //failed to register sdt
	}
	return false;
}



//new
bool validate_login_admin(char *url_data)
{
	
	char data[5][100];
	char *ptr = strchr(url_data, '&');
	*ptr = '\0';
	strcpy_s(data[0], url_data);
	ptr++;
	strcpy_s(data[1], ptr);
	ptr = strchr(data[1], '&');
	*ptr = '\0';

	char temp_id[100];
	ifstream reg_check_file_sdt;
	reg_check_file_sdt.open("C:\\xampp\\htdocs\\etmms\\realdata\\sub_station_list.txt");
	if (!reg_check_file_sdt.fail())
	{
		while (!reg_check_file_sdt.eof())
		{
			reg_check_file_sdt >> temp_id;
			if (!strcmp(temp_id,data[0]) && !strcmp(data[1],"12345"))
			{
					reg_check_file_sdt.close();
					return true;
			}
		}
	}
	else
	{
		reg_check_file_sdt.close();
		return false; //failed to register sdt
	}
	return false;
}









/*


int color_status(double output_gi_real, double output_total_avg)
{
	double temp1, i, j, k;
	temp1 = output_gi_real - output_total_avg;

	i = temp1 / output_total_avg;

	i = i * 100;

	if (i <= 20)
		return 2;

	if (i > 20 && i <= 35)
		return 3;

	if (i > 35)
		return 1;

	return 1;
}

*/


map_store_strct * find_in_map(char *kno_id)
{
	map<char*, map_store_strct*> ::iterator it;

	for (it = map_store.begin();it != map_store.end();it++)
	{
		if (!strcmp(kno_id, it->first))
			return it->second;
	}
	return nullptr;
}



void map_storage_decision_user(step_trans_list *temp1_sdt,user_real_time_data *temp1_user)
{
	map_store_strct *temp1_map_strct;
	temp1_map_strct = find_in_map(temp1_user->kno);
	if (temp1_map_strct == nullptr)
	{
		temp1_map_strct = new map_store_strct;
		temp1_map_strct->last_avg_volt = temp1_sdt->avg_volt;
		temp1_map_strct->last_volt = temp1_sdt->volt;
		temp1_map_strct->last_avg_power = temp1_user->avg_use;
		temp1_map_strct->last_power = temp1_user->real_time_data;
		temp1_map_strct->rate_power = 0;
		temp1_map_strct->rate_volt = 0;
		temp1_map_strct->rate_avg_volt = 0;
		temp1_map_strct->rate_avg_power = 0;
		temp1_map_strct->volt_status_change_count = 0;
		temp1_map_strct->power_status_change_count = 0;
		temp1_map_strct->conn_setup_time = 5;

		char temp_arr[100];
		ifstream read_file;
		read_file.open("C:\\xampp\\htdocs\\etmms\\registration_file.txt");
		
		while (!read_file.eof())
		{
			read_file >> temp_arr;
			if (strstr(temp_arr, "-----"))
			{
				read_file >> temp_arr;
				if (!strcmp(temp1_user->kno, temp_arr))
				{
					int i = 15;
					while (i--)
						read_file >> temp_arr;
					read_file >> i;
					temp1_map_strct->family_status = i;
					read_file >> temp_arr;
					read_file >> temp_arr;
					if (!strcmp(temp_arr, "Domestic"))
						temp1_map_strct->connection_type = 1;
					else
						temp1_map_strct->connection_type = 2;

				}
			}
		}
		read_file.close();
		map_store.insert(pair<char*,map_store_strct*>(temp1_user->kno,temp1_map_strct));
		return;
	}
	
	double  x, y;
	temp1_map_strct->conn_setup_time--;

	x = ((temp1_user->real_time_data - temp1_map_strct->last_power) / temp1_map_strct->last_avg_power)*100;
	y = ((temp1_sdt->volt - temp1_map_strct->last_volt) / 235.00) * 100;

	temp1_map_strct->rate_power= x;
	temp1_map_strct->rate_volt = y;


	temp1_map_strct->last_avg_volt = temp1_sdt->avg_volt;
	temp1_map_strct->last_avg_power = temp1_user->avg_use;
	temp1_map_strct->last_power = temp1_user->real_time_data;
	temp1_map_strct->last_volt = temp1_sdt->volt;

	//printf("\n\n\n%s\navg_v : %f\tavg_use : %f\treal : %f\tvolt : %f\n",temp1_user->kno,temp1_map_strct->last_avg_v, temp1_map_strct->last_gi_avg,temp1_map_strct->last_power_out,temp1_map_strct->last_volt);
	if (temp1_user->status_user != 1)
	{
		if (temp1_user->status_user >= 4)
		{
			//printf("\n1");
			if (temp1_map_strct->power_status_change_count >= 5)
			{
				//printf("\nOn");
				temp1_user->status_user ^= 4;
				temp1_user->color_code_user = 1;
				temp1_map_strct->power_status_change_count = 0;
			}
			else
			{
				temp1_map_strct->power_status_change_count += 1;
				return;
			}
		}
		temp1_map_strct->power_status_change_count = 5;
		temp1_user->color_code_user = 0;
	
	}
	
	if (temp1_sdt->status_sdt == 0)
	{
		temp1_user->color_code_user = 0;
		return;
	}


	if (temp1_map_strct->rate_power < 20)
	{
		temp1_map_strct->power_status_change_count = 0;
		temp1_map_strct->volt_status_change_count = 0;
		temp1_user->color_code_user = 1;
	}
	else if ((temp1_map_strct->rate_power >= 20 && temp1_map_strct->rate_power <= 35))
	{
		temp1_map_strct->power_status_change_count = 0;
		temp1_map_strct->volt_status_change_count = 0;
		temp1_user->color_code_user = 2;
	}
	else
		temp1_user->color_code_user = 3;

	if (temp1_map_strct->family_status <= 2 && temp1_map_strct->last_power > temp1_user->user_limit_value)
		temp1_user->color_code_user = 4;
	
	//now is the time to go ahead if automatic decision is enable
	if (temp1_user->auto_mann_dec_stat_user == 0 && temp1_sdt->auto_mann_dec_stat_sdt==0)
		return;

	//printf("\nYes : %s\trate_avg_power : %f, rate_avg_volt : %f",temp1_user->kno,temp1_map_strct->rate_avg_power,temp1_map_strct->rate_avg_volt);
	//printf("\nYes");
	if (temp1_user->color_code_user == 3)
	{
		//printf("\noff");
		//if (temp1_map_strct->family_status == 3 && temp1_map_strct->connection_type == 2 && temp1_map_strct->conn_setup_time > 0)
		if (temp1_map_strct->family_status == 3)
			return;

		temp1_user->status_user ^= 4;
		temp1_user->color_code_user = 0;
		temp1_map_strct->power_status_change_count = 1;
	}
	
	if (temp1_map_strct->family_status <= 2 && temp1_map_strct->last_power > temp1_user->user_limit_value && temp1_map_strct->rate_power > 0)
	{
		temp1_user->status_user ^= 4;
		temp1_user->color_code_user = 0;
		temp1_map_strct->power_status_change_count = 1;
	}
	return;
}




void map_storage_decision_sdt(sub_station_list *temp1_sub,step_trans_list *temp1_sdt)
{
	map_store_strct *temp1_map_strct;
	//printf("\n%s\t%f",temp1_sdt->sdt_id,temp1_sdt->diff_pow);
	temp1_map_strct = find_in_map(temp1_sdt->sdt_id);
	if (temp1_map_strct == nullptr)
	{
		temp1_map_strct = new map_store_strct;
		temp1_map_strct->power_status_change_count = 0;
		map_store.insert(pair<char*, map_store_strct*>(temp1_sdt->sdt_id, temp1_map_strct));
		return;
	}

	if (temp1_sdt->status_sdt == 0)
	{
		temp1_map_strct->power_status_change_count = 0;
		temp1_sdt->color_code_sdt = 0;
		return;
	}

	if ( temp1_sdt->diff_pow < temp1_sdt->sdt_diff_value_limit)
		temp1_sdt->color_code_sdt = 1;
	if (temp1_sdt->diff_pow > temp1_sdt->sdt_diff_value_limit && temp1_sdt->diff_pow <= 2 * (temp1_sdt->sdt_diff_value_limit))
		temp1_sdt->color_code_sdt = 2;
	if (temp1_sdt->diff_pow > 2 * (temp1_sdt->sdt_diff_value_limit))
		temp1_sdt->color_code_sdt = 3;

	if (temp1_sdt->auto_mann_dec_stat_sdt == 0)
		return;

	if (temp1_sdt->status_sdt == 0)
	{
		if (temp1_map_strct->power_status_change_count >= 5)
		{
			temp1_sdt->status_sdt = 1;
			temp1_map_strct->power_status_change_count = 0;
		}
		else
		{
			temp1_map_strct->power_status_change_count++;
			temp1_sdt->color_code_sdt = 0;
		}
		return;		
	}

	if (temp1_sdt->color_code_sdt == 3)
	{
		temp1_sdt->status_sdt = 0;
		temp1_map_strct->power_status_change_count = 0;
		temp1_sdt->color_code_sdt = 0;
	}
	return;
}



//new

void map_storage_decision_sub(sub_station_list *temp1_sub)
{
	map_store_strct *temp1_map_strct;
	//printf("\n%s\t%f",temp1_sdt->sdt_id,temp1_sdt->diff_pow);
	temp1_map_strct = find_in_map(temp1_sub->sub_id);
	if (temp1_map_strct == nullptr)
	{
		temp1_map_strct = new map_store_strct;
		temp1_map_strct->last_volt = temp1_sub->volt;
		temp1_map_strct->last_power = temp1_sub->pow_out;
		temp1_map_strct->last_avg_power = temp1_sub->pow_con;
		map_store.insert(pair<char*, map_store_strct*>(temp1_sub->sub_id, temp1_map_strct));
		return;
	}

		if (temp1_sub->volt == 0 || temp1_sub->pow_out == 0 && temp1_sub->pow_con == 0)
		{
			temp1_sub->volt = temp1_map_strct->last_volt;
			temp1_sub->pow_out = temp1_map_strct->last_power;
			temp1_sub->pow_con = temp1_map_strct->last_avg_power;
		}
		else
		{
			temp1_map_strct->last_volt = temp1_sub->volt;
			temp1_map_strct->last_power = temp1_sub->pow_out;
			temp1_map_strct->last_avg_power = temp1_sub->pow_con;
		}
	return;
}


//new
void print_central_datastructure()
{
	sub_station_list *temp_sub;
	step_trans_list *temp_sdt;
	user_real_time_data *temp_user;
	temp_sub = real_time_data_linklist;
	while (temp_sub!= nullptr)
	{
		printf("\n\t|");
		printf("\n\t|");
		printf("\n\t|-->%s",temp_sub->sub_id);
		temp_sdt = temp_sub->sdt_list;
		while (temp_sdt != nullptr)
		{
			printf("\n\t|\t|");
			printf("\n\t|\t|");
			printf("\n\t|\t|-->%s",temp_sdt->sdt_id);
			temp_user = temp_sdt->user_list;
			while (temp_user != nullptr)
			{
				printf("\n\t|\t|\t|");
				printf("\n\t|\t|\t|-->%s",temp_user->kno);
				temp_user = temp_user->next_user;
			}
			temp_sdt = temp_sdt->next_sdt;
		}
		temp_sub = temp_sub->next_sub;
	}

	return;
}



//main creation of the centralised datastructure
//new
void async_function_graph_data()
{

	Sleep(100);

	char temp_data[50];

	//to get the number of sub station administrators
	sub_station_list *temp1_sub, *temp2_sub;

	ifstream read_file;
	read_file.open("C:\\xampp\\htdocs\\etmms\\realdata\\sub_station_list.txt");

	while (!read_file.eof())
	{
		read_file >> temp_data;
		if (strlen(temp_data) <= 1)
			break;

		temp1_sub = new sub_station_list;
		temp1_sub->total_sdt = 0;
		temp1_sub->color_code = -1;
		strcpy_s(temp1_sub->sub_id, temp_data);
		temp1_sub->next_sub = nullptr;
		temp1_sub->sdt_list = nullptr;

		if (real_time_data_linklist == nullptr)
		{
			real_time_data_linklist = temp1_sub;
			temp2_sub = temp1_sub;
		}
		else
		{
			temp2_sub->next_sub = temp1_sub;
			temp2_sub = temp1_sub;
		}

	}
	read_file.close();




	// to get the total number of step down transformers under the each administrator
	temp1_sub = real_time_data_linklist;
	step_trans_list *temp1_sdt, *temp2_sdt;

	while (temp1_sub != nullptr)
	{
		char file_name[100];
		strcpy_s(file_name, "C:\\xampp\\htdocs\\etmms\\realdata\\");
		strcat_s(file_name, temp1_sub->sub_id);
		strcat_s(file_name, ".txt");

		read_file.open(file_name);

		int tt_sdt=0;

		while (!read_file.eof())
		{
			read_file >> temp_data;
			if (strlen(temp_data) <= 2)
				break;

			temp1_sdt = new step_trans_list;
			strcpy_s(temp1_sdt->sdt_id, temp_data);

			temp1_sdt->next_sdt = nullptr;
			temp1_sdt->user_list = nullptr;
			temp1_sdt->volt = temp1_sdt->sdt_out = temp1_sdt->user_totl =temp1_sdt->diff_pow= 0;
			temp1_sdt->status_sdt = 1;
			temp1_sdt->auto_mann_dec_stat_sdt = 0;
			temp1_sdt->color_code_sdt = 1;
			temp1_sdt->total_user = 0;
			temp1_sdt->avg_sdt_out = 0;
			temp1_sdt->avg_user_totl = 0;
			temp1_sdt->avg_volt = 0;
			temp1_sdt->avg_diff_pow = 0;
			temp1_sdt->sdt_diff_value_limit = 20; //dec making

			if (temp1_sub->sdt_list == nullptr)
			{
				temp1_sub->sdt_list = temp1_sdt;
				temp2_sdt = temp1_sdt;
			}
			else
			{
				temp2_sdt->next_sdt = temp1_sdt;
				temp2_sdt = temp1_sdt;
			}

			tt_sdt++;
		}
		read_file.close();

		temp1_sub->total_sdt = tt_sdt;

		temp1_sub = temp1_sub->next_sub;
	}


	//get the each user under each step down transformer

	user_real_time_data *temp1_user, *temp2_user;

	temp1_sub = real_time_data_linklist;
	while (temp1_sub != nullptr)
	{
		temp1_sdt = temp1_sub->sdt_list;
		while (temp1_sdt != nullptr)
		{
			char file_name[100];
			strcpy_s(file_name, "C:\\xampp\\htdocs\\etmms\\realdata\\");
			strcat_s(file_name, temp1_sdt->sdt_id);
			strcat_s(file_name, ".txt");

			read_file.open(file_name);

			int tt_u = 0;
			while (!read_file.eof())
			{
				read_file >> temp_data;
				if (strlen(temp_data) <= 2)
					break;

				tt_u++;
				temp1_user = new user_real_time_data;
				strcpy_s(temp1_user->kno , temp_data);

				temp1_user->next_user = nullptr;
				temp1_user->real_time_data = 0;
				temp1_user->avg_use = 0;
				temp1_user->status_user = 1;
				temp1_user->auto_mann_dec_stat_user = 0;
				temp1_user->color_code_user = 1;
				temp1_user->user_limit_value = -1; //dec macking

				if (temp1_sdt->user_list == nullptr)
				{
					temp1_sdt->user_list = temp1_user;
					temp2_user = temp1_user;
				}
				else
				{
					temp2_user->next_user = temp1_user;
					temp2_user = temp1_user;
				}

			}
			read_file.close();

			temp1_sdt->total_user = tt_u;
			temp1_sdt->user_data = new double[tt_u];

			temp1_sdt = temp1_sdt->next_sdt;
		}

		temp1_sub = temp1_sub->next_sub;
	}


//print the exact structure of the central datastructure
	//print_central_datastructure();
	//return;
// running function to update the linklist data after each 2 sec

	double volt, sdt_out, user_totl, diff_pow;

	int total_read = 0;

	while (true)
	{
		//for read next data
		if (total_read  >= 2000)
			total_read = 1;


		temp1_sub = real_time_data_linklist;
		while (temp1_sub != nullptr)
		{
			temp1_sub->pow_out = 0, temp1_sub->pow_con = 0, temp1_sub->volt = 0;
			temp1_sdt = temp1_sub->sdt_list;
			while (temp1_sdt != nullptr)
			{
				
				char file_name[100];
				strcpy_s(file_name, "C:\\xampp\\htdocs\\etmms\\database\\");
				strcat_s(file_name, temp1_sdt->sdt_id);
				strcat_s(file_name, ".txt");
				//printf("\n%d : %s",total_read,file_name);
				read_file.open(file_name);
				//go to next data
				volt=sdt_out=user_totl=diff_pow=0;
				int k = 0;
				while(k<=total_read)
				{
					read_file >> volt;
					read_file >> sdt_out;
					read_file >> user_totl;
					read_file >> diff_pow;

					for (int i = 0;i<temp1_sdt->total_user;i++)
						read_file >> temp1_sdt->user_data[i];

					//printf("\n%s\t%d\t%.2f\t%.2f\t%.2f\t%.2f", temp1_sdt->sdt_id, temp1_sdt->total_user, volt, sdt_out, user_totl,diff_pow);
					k++;
			   }

				//printf("\n**\t%s\t%d\t%.2f\t%.2f\t%.2f\t%.2f", temp1_sdt->sdt_id, temp1_sdt->total_user, volt, sdt_out, user_totl, diff_pow);
				read_file.close();

					temp1_sdt->avg_volt = float((temp1_sdt->avg_volt*total_read + volt) / (total_read + 1));
					temp1_sdt->volt = volt;
					temp1_sdt->avg_diff_pow = float((temp1_sdt->avg_diff_pow*total_read + diff_pow) / (total_read + 1));
					temp1_sdt->diff_pow = diff_pow; 
	
					//printf("\n%s\t%d\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f", temp1_sdt->sdt_id, temp1_sdt->total_user, volt,temp1_sdt->avg_volt, sdt_out, temp1_sdt->avg_sdt_out, user_totl, temp1_sdt->avg_user_totl, diff_pow,temp1_sdt->avg_diff_pow);
				
						temp1_user = temp1_sdt->user_list;
						int j = 0;
						while (temp1_user != nullptr)
						{

							temp1_user->real_time_data = temp1_sdt->user_data[j];
							temp1_user->avg_use = float((temp1_user->avg_use*total_read + temp1_user->real_time_data) / (total_read + 1));
	
							// if this home power is off then - it part in sdt calculations
							//this is done for sub data generation
							if (temp1_sdt->status_sdt == 1 && temp1_user->status_user != 1)
							{

								//- from sdt calculation jin ki power off h
								sdt_out -= temp1_user->real_time_data;
								user_totl -= temp1_user->real_time_data;
								//ab humare pss only we bache h jo working h
							}

							map_storage_decision_user(temp1_sdt,temp1_user);

							temp1_user = temp1_user->next_user;
							j++;
						}

						temp1_sdt->avg_sdt_out = float((temp1_sdt->avg_sdt_out*total_read + sdt_out) / (total_read + 1));
						temp1_sdt->sdt_out = sdt_out;
						temp1_sdt->avg_user_totl = float((temp1_sdt->avg_user_totl*total_read + user_totl) / (total_read + 1));
						temp1_sdt->user_totl = user_totl;


						//status 0 means power is turned off for this SDT by Admin
						//this is doing for sub data generation
						if (temp1_sdt->status_sdt == 1)
						{
							temp1_sub->pow_out += temp1_sdt->sdt_out;
							temp1_sub->pow_con += temp1_sdt->user_totl;
							temp1_sub->volt = temp1_sdt->volt;
						}

				//if the automatic decision taking is on then call machine learning function for sdt before going to next sdt
				       //machine_learning_decision(temp1_sdt->sdt_id,temp1_sdt->gi,temp1_sdt->total_user_con,temp1_sdt->v,1);
						map_storage_decision_sdt(temp1_sub,temp1_sdt);

					temp1_sdt = temp1_sdt->next_sdt;
				}

			map_storage_decision_sub(temp1_sub);
			temp1_sub = temp1_sub->next_sub;
		}


		Sleep(3000);
		total_read++;
	}

}


