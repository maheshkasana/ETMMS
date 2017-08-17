/* Copyright (c) 2013-2017 the Civetweb developers
 * Copyright (c) 2013 No Face Press, LLC
 * License http://opensource.org/licenses/mit-license.php MIT License
 */

// Simple example program on how to use Embedded C++ interface.
#include "etmms.h"
#include "CivetServer.h"
#include <cstring>
#include <time.h>

#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<fstream>
#include<iostream>
#include <sstream>
#include <string>
#include<future>

using namespace std;



#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#define DOCUMENT_ROOT "."
#define PORT "5454"
#define EXAMPLE_URI "/example"
#define EXIT_URI "/exit"
bool exitNow = false;



//new
class user_login_check : public CivetHandler
{
public:
	bool
		handleGet(CivetServer *server, struct mg_connection *conn)
	{
		const struct mg_request_info *req_info = mg_get_request_info(conn);

		mg_printf(conn,
			"HTTP/1.1 200 OK\r\nAccess-Control-Allow-Origin: *\r\nContent-Type: "
			"text/plain\r\nConnection: close\r\n\r\n");

		char url_data[500];

		strcpy_s(url_data, req_info->query_string);

		//call a validate function
		bool retu = validate_login_user(url_data);
		if (retu == true)
		{
			mg_printf(conn, "%d", 1);
			printf("\nLogin Successful");
		}
		else
		{

			mg_printf(conn, "%d", 0);
			printf("\nLogin Failed");
		}
		return true;
	}
};


//new
class admin_login_check : public CivetHandler
{
public:
	bool
		handleGet(CivetServer *server, struct mg_connection *conn)
	{
		/* Handler may access the request info using mg_get_request_info */
		const struct mg_request_info *req_info = mg_get_request_info(conn);
	
		mg_printf(conn,
			"HTTP/1.1 200 OK\r\nAccess-Control-Allow-Origin: *\r\nContent-Type: "
			"text/plain\r\nConnection: close\r\n\r\n");
	
		char url_data[500];

		strcpy_s(url_data, req_info->query_string);

		//call a validate function
		bool retu = validate_login_admin(url_data);
		if (retu == true)
		{
			mg_printf(conn, "%d", 1);
			printf("\nLogin Successful");
		}
		else
		{
			mg_printf(conn, "%d", 0);
			printf("\nLogin Failed");
		}
		return true;
	}
};


//new
class get_profile_data : public CivetHandler
{
public:
	bool
		handleGet(CivetServer *server, struct mg_connection *conn)
	{
		const struct mg_request_info *req_info = mg_get_request_info(conn);
		mg_printf(conn,
			"HTTP/1.1 200 OK\r\nAccess-Control-Allow-Origin: *\r\nContent-Type: text/html\r\nConnection: "
			"close\r\n\r\n");

		char url_data[50];
		strcpy_s(url_data, req_info->query_string);

		int i = 0,flag=0;
		char data[25][100] = {NULL};
		char temp_id[100];
		ifstream reg_check_file_sdt;
		reg_check_file_sdt.open("C:\\xampp\\htdocs\\etmms\\registration_file.txt");
		if (!reg_check_file_sdt.fail())
		{
			while (!reg_check_file_sdt.eof())
			{
				reg_check_file_sdt >> temp_id;
				//printf("\n%s",temp_id);
				if (strstr(temp_id, "--------"))
				{
					reg_check_file_sdt >> temp_id;
					//printf("\n%s", temp_id);
					if (!strcmp(temp_id, url_data))
					{	
						i = 0;
						do
						{
							reg_check_file_sdt >> temp_id;
							strcpy_s(data[i],temp_id);
							i++;
						} while (!strstr(temp_id,"-----") && !reg_check_file_sdt.eof());
						
						flag = 1;
					}
				}
				if (flag == 1)
					break;
			}
		}
		
		reg_check_file_sdt.close();
		mg_printf(conn, "<div id='return_data_profile'><table><tr><td id='pro_kno'>%s</td><td id='pro_gmail'>%s</td><td id='pro_hint'>%s</td><td id='pro_alt_gmail'>%s</td><td id='pro_nu'>%s</td>", url_data, data[1],data[2], data[3], data[4]);
		mg_printf(conn, "<td id='pro_fname'>%s</td><td id='pro_lname'>%s</td><td id='pro_add'>%s</td><td id='pro_dist'>%s</td><td id='pro_state'>%s</td><td id='pro_pin'>%s</td><td id='pro_aadhar'>%s</td><td id='pro_bhamashah'>%s</td>", data[5], data[6], data[7], data[8], data[9], data[10], data[11], data[12]);
		mg_printf(conn, "<td id='pro_phase'>%s</td><td id='pro_load'>%s</td><td id='pro_tariff'>%s</td><td id='pro_service'>%s</td><td id='pro_type'>%s</td><td id='pro_mnu'>%s</td><td id='pro_st_code'>%s</td><td id='pro_st_name'>%s</td></tr></table></div>", data[13], data[14], data[15], data[16], data[17], data[18], data[19], data[20]);
		return true;
	}
};



//new
class register_new_sdt : public CivetHandler
{
public:
	bool
		handleGet(CivetServer *server, struct mg_connection *conn)
	{
		const struct mg_request_info *req_info = mg_get_request_info(conn);
		mg_printf(conn,
			"HTTP/1.1 200 OK\r\nAccess-Control-Allow-Origin: *\r\nContent-Type: text/html\r\nConnection: "
			"close\r\n\r\n");
		char url_data[1000];
		strcpy_s(url_data, req_info->query_string);

		int ret = register_new_sdt_fun(url_data);

		if (ret == 1)
			mg_printf(conn, "%d", 1);
		else if (ret == 2)
			mg_printf(conn, "%d", 2);
		else
			mg_printf(conn, "%d", 0);

		return true;
	}
};


//new
class register_user : public CivetHandler
{
public:
	bool
		handleGet(CivetServer *server, struct mg_connection *conn)
	{
		const struct mg_request_info *req_info = mg_get_request_info(conn);
		mg_printf(conn,
			"HTTP/1.1 200 OK\r\nAccess-Control-Allow-Origin: *\r\nContent-Type: text/html\r\nConnection: "
			"close\r\n\r\n");
		char url_data[1000];
		strcpy_s(url_data, req_info->query_string);

		int retu = registration_user(url_data);



		if (retu == 1)
			mg_printf(conn, "%d", 1);
		else if (retu == 2)
			mg_printf(conn, "%d", 2);
		else
			mg_printf(conn, "%d", 0);

		return true;
	}
};



//new
class user_current_data : public CivetHandler
{
public:
	bool
		handleGet(CivetServer *server, struct mg_connection *conn)
	{


		const struct mg_request_info *req_info = mg_get_request_info(conn);
		mg_printf(conn,
			"HTTP/1.1 200 OK\r\nAccess-Control-Allow-Origin: *\r\nContent-Type: text/html\r\nConnection: "
			"close\r\n\r\n");

		//printf("\n\n%s",req_info->query_string);

		char url_data[100];
		strcpy_s(url_data, req_info->query_string);

		//printf("\n%s",url_data);
		sub_station_list *temp1_sub;
		step_trans_list *temp1_sdt;
		user_real_time_data *temp1_user;

		temp1_sub = real_time_data_linklist;
		while (temp1_sub != nullptr)
		{
			if (strstr(url_data, temp1_sub->sub_id) != nullptr)
			{
				temp1_sdt = temp1_sub->sdt_list;
				while (temp1_sdt != nullptr)
				{
					if (strstr(url_data, temp1_sdt->sdt_id) != nullptr)
					{
						temp1_user = temp1_sdt->user_list;
						while (temp1_user != nullptr)
						{
							int temp_stat = 0;
							if (temp1_sdt->status_sdt == 0)
								temp_stat = 0;
							else
								temp_stat = temp1_user->status_user;

							if (!strcmp(url_data, temp1_user->kno))
							{
								mg_printf(conn, "<div id='return_data_real_time'><table><tr><td id='user_status'>%d</td><td id='user_real_power'>%f</td><td id='user_real_avg_power'>%f</td><td id='user_real_voltage'>%f</td><td id='user_real_avg_voltage'>%f</td></tr></table></div>",temp_stat, temp1_user->real_time_data, temp1_user->avg_use, temp1_sdt->volt, temp1_sdt->avg_volt);
								return true;
							}
							
							temp1_user = temp1_user->next_user;
						}
					}
					temp1_sdt = temp1_sdt->next_sdt;
				}
			}
			temp1_sub = temp1_sub->next_sub;
		}
		mg_printf(conn, "%d", 0);
		return true;
	}
};


//new
class user_turn_on_off_power : public CivetHandler
{
public:
	bool
		handleGet(CivetServer *server, struct mg_connection *conn)
	{
		const struct mg_request_info *req_info = mg_get_request_info(conn);
		mg_printf(conn,
			"HTTP/1.1 200 OK\r\nAccess-Control-Allow-Origin: *\r\nContent-Type: text/html\r\nConnection: "
			"close\r\n\r\n");

		char url_data[100];
		strcpy_s(url_data, req_info->query_string);
		
		sub_station_list *temp1_sub;
		step_trans_list *temp1_sdt;
		user_real_time_data *temp1_user;

		temp1_sub = real_time_data_linklist;
		while (temp1_sub != nullptr)
		{
			if (strstr(url_data, temp1_sub->sub_id) != nullptr)
			{
				temp1_sdt = temp1_sub->sdt_list;
				while (temp1_sdt != nullptr)
				{
					if (strstr(url_data, temp1_sdt->sdt_id) != nullptr)
					{
						temp1_user = temp1_sdt->user_list;
						while (temp1_user != nullptr)
						{
							if (!strcmp(url_data, temp1_user->kno))
							{
								temp1_user->status_user = temp1_user->status_user ^ 2;
								mg_printf(conn, "%d", 1);
								return true;
							}
							temp1_user = temp1_user->next_user;
						}
					}
					temp1_sdt = temp1_sdt->next_sdt;
				}
			}
			temp1_sub = temp1_sub->next_sub;
		}
		mg_printf(conn, "%d", 0);
		return true;
	}
};


//new
class generate_bills : public CivetHandler
{
public:
	bool
		handleGet(CivetServer *server, struct mg_connection *conn)
	{
		const struct mg_request_info *req_info = mg_get_request_info(conn);
		mg_printf(conn,
			"HTTP/1.1 200 OK\r\nAccess-Control-Allow-Origin: *\r\nContent-Type: text/html\r\nConnection: "
			"close\r\n\r\n");
		char url_data[1000];
		strcpy_s(url_data, req_info->query_string);
		
		//get personal information
		bool flag = false;
		char temp_data[500];
		int temp_bill_no,bill_no;
		temp_bill_no = bill_no = 0;
		ifstream reg_add_file;
		reg_add_file.open("C:\\xampp\\htdocs\\etmms\\curr_bill_file.txt");
		while (!reg_add_file.eof())
		{
			reg_add_file >> temp_data; 
			if (strstr(temp_data,"-----"))
			{
				reg_add_file >> temp_data;
				if (!strcmp(temp_data, url_data))
				{
					reg_add_file >> temp_bill_no;
					if (temp_bill_no > bill_no)
						bill_no = temp_bill_no;
				}
			}
		}
		reg_add_file.close();

		bill_no++;
		ofstream bill_file;
		bill_file.open("C:\\xampp\\htdocs\\etmms\\curr_bill_file.txt", ios::app);
		if (!bill_file.fail())
		{
			bill_file << "----------"<<endl;
			bill_file << url_data << endl;
			bill_file << bill_no << endl;
			time_t now = time(0);
			bill_file << "08\\07\\2017" << endl;
			bill_file << (rand() % bill_no)*20 + 500 << endl;
			bill_file << "Unpaid" << endl;
		}
		bill_file.close();
		mg_printf(conn, "%d", 1);
		return true;
	}
};


//new
class current_bill_data : public CivetHandler
{
public:
	bool
		handleGet(CivetServer *server, struct mg_connection *conn)
	{
		const struct mg_request_info *req_info = mg_get_request_info(conn);
		mg_printf(conn,
			"HTTP/1.1 200 OK\r\nAccess-Control-Allow-Origin: *\r\nContent-Type: text/html\r\nConnection: "
			"close\r\n\r\n");
		char url_data[1000];
		strcpy_s(url_data, req_info->query_string);

		
		char bill_no[20], kno[20], tme[30], amnt[10], sts[20];
		ifstream reg_add_file;
		reg_add_file.open("C:\\xampp\\htdocs\\etmms\\curr_bill_file.txt");
		while (!reg_add_file.eof())
		{
			reg_add_file >> kno;
			if (strstr(kno, "------"))
			{
				reg_add_file >> kno;
				if (!strcmp(kno, url_data))
				{   
						reg_add_file >> bill_no;
						reg_add_file >> tme;
						reg_add_file >> amnt;
						reg_add_file >> sts;
						//printf("\n%s\t%s\t%s\t%s\t%s",kno,bill_no,tme,amnt,sts);

						time_t now = time(0);
						mg_printf(conn, "<div id='return_data_profile'><table><tr></tr><tr><td colspan='4'><b><u>Personal Information</u></b></td></tr><tr><td><b>KNO</b></td><td id='bill_kno'>%s</td></tr><tr>", url_data);
						mg_printf(conn, "<tr><td> </td></tr><tr><td colspan='4'><b><u>Bill Information</b></u></td></tr><td><b>Bill No.</b></td><td id='bill_no'>%s</td><td><b>Till Date</b></td><td id='bill_till_date'>%s</td></tr><tr><td><b>Bill Status</b></td><td id='bill_status'>%s</td><td><b>Bill Due Date</b></td><td id='bill_last Date'>%s</td></tr><tr><td><b>Bill Amount</b></td><td id='bill_amount'>%s</td></tr><tr><td><b>Due Fine</b></td><td id='bill_fine'>%f</td></tr><tr><td><b>Total Bill</b></td><td id='bill_total'>%s</td></tr><tr><td></td><td colspan='2' ><button onclick='pay_energy_bill(%s)'>Pay Bill</button></td><td></td></tr></table></div>", bill_no, tme, sts, ctime(&now),amnt, 0, amnt,bill_no);
						//printf("\n%d",client.bill_no);
				}
			}
		}
		reg_add_file.close();
		return true;
	}
};

//new

class previous_bill_data : public CivetHandler
{
public:
	bool
		handleGet(CivetServer *server, struct mg_connection *conn)
	{
		const struct mg_request_info *req_info = mg_get_request_info(conn);
		mg_printf(conn,
			"HTTP/1.1 200 OK\r\nAccess-Control-Allow-Origin: *\r\nContent-Type: text/html\r\nConnection: "
			"close\r\n\r\n");
		char url_data[1000];
		strcpy_s(url_data, req_info->query_string);

		char bill_no[20], kno[20], tme[30], amnt[10], sts[20];
		ifstream reg_add_file;
		reg_add_file.open("C:\\xampp\\htdocs\\etmms\\prev_bill_file.txt");
		while (!reg_add_file.eof())
		{
			reg_add_file >> kno;
			if (strstr(kno, "------"))
			{
				reg_add_file >> kno;
				if (!strcmp(kno, url_data))
				{
					reg_add_file >> bill_no;
					reg_add_file >> tme;
					reg_add_file >> amnt;
					reg_add_file >> sts;
					//printf("\n%s\t%s\t%s\t%s\t%s",kno,bill_no,tme,amnt,sts);

					time_t now = time(0);
					mg_printf(conn, "<div id='return_data_profile'><table><tr></tr><tr><td colspan='4'><b><u>Personal Information</u></b></td></tr><tr><td><b>KNO</b></td><td id='bill_kno'>%s</td></tr><tr>", url_data);
					mg_printf(conn, "<tr><td> </td></tr><tr><td colspan='4'><b><u>Bill Information</b></u></td></tr><td><b>Bill No.</b></td><td id='bill_no'>%s</td><td><b>Till Date</b></td><td id='bill_till_date'>%s</td></tr><tr><td><b>Bill Status</b></td><td id='bill_status'>%s</td><td><b>Bill Due Date</b></td><td id='bill_last Date'>%s</td></tr><tr><td><b>Bill Amount</b></td><td id='bill_amount'>%s</td></tr><tr><td><b>Due Fine</b></td><td id='bill_fine'>%f</td></tr><tr><td><b>Total Bill</b></td><td id='bill_total'>%s</td></tr></table></div>", bill_no, tme, sts, ctime(&now), amnt, 0, amnt);
					//printf("\n%d",client.bill_no);
				}
			}
		}
		reg_add_file.close();
		return true;
	}
};


//new
class pay_energy_bill : public CivetHandler
{
public:
	bool
		handleGet(CivetServer *server, struct mg_connection *conn)
	{
		const struct mg_request_info *req_info = mg_get_request_info(conn);
		mg_printf(conn,
			"HTTP/1.1 200 OK\r\nAccess-Control-Allow-Origin: *\r\nContent-Type: text/html\r\nConnection: "
			"close\r\n\r\n");
		char url_data[1000];
		strcpy_s(url_data, req_info->query_string);

	
		char temp_bill_no[20];
		char *ptr = strchr(url_data,'&');
		*ptr = '\0';
		strcpy_s(temp_bill_no, ptr + 1);

		char bill_no[20], kno[20], tme[30], amnt[10], sts[20];
		int flag = 0;
		ifstream read_file;
		ofstream write_file, temp_file;

		write_file.open("C:\\xampp\\htdocs\\etmms\\prev_bill_file.txt", ios::app);
		temp_file.open("C:\\xampp\\htdocs\\etmms\\temp.txt");
		read_file.open("C:\\xampp\\htdocs\\etmms\\curr_bill_file.txt");
		while (!read_file.eof())
		{
			read_file >> bill_no;

			if (strstr(bill_no,"-----"))
			{
				read_file >> kno;
				read_file >> bill_no;
				read_file >> tme;
				read_file >> amnt;
				read_file >> sts;
				if (!strcmp(kno, url_data) && !strcmp(bill_no, temp_bill_no))
				{
					write_file << "----------"<<endl;
					write_file << kno << endl;
					write_file << bill_no << endl;
					write_file << tme << endl;
					write_file << amnt << endl;
					write_file << "Paid" << endl;
					flag = 1;
				}
				else
				{
					temp_file << "----------" << endl;
					temp_file << kno << endl;
					temp_file << bill_no << endl;
					temp_file << tme << endl;
					temp_file << amnt << endl;
					temp_file << sts << endl;
				}
			}
		}

		read_file.close();
		write_file.close();
		temp_file.close();

		remove("C:\\xampp\\htdocs\\etmms\\curr_bill_file.txt");
		rename("C:\\xampp\\htdocs\\etmms\\temp.txt", "C:\\xampp\\htdocs\\etmms\\curr_bill_file.txt");
		
		if (flag == 0)
		{
			mg_printf(conn, "%d", 0);
			return true;
		}
		else
		{
			mg_printf(conn, "%d", 1);
			return true;
		}
		return true;
	}
};



//new
class online_complaint_request : public CivetHandler
{
public:
	bool
		handleGet(CivetServer *server, struct mg_connection *conn)
	{
		const struct mg_request_info *req_info = mg_get_request_info(conn);
		mg_printf(conn,
			"HTTP/1.1 200 OK\r\nAccess-Control-Allow-Origin: *\r\nContent-Type: text/html\r\nConnection: "
			"close\r\n\r\n");

		char url_data[1000];
		strcpy_s(url_data, req_info->query_string);


		char kno[50], reason[100], discri[500], *temp1,*temp2;
	
		temp1 = strchr(url_data, '&');
		*temp1 = '\0';
		strcpy_s(kno, url_data);
		temp1++;
		temp2 = strchr(temp1,'&');
		*temp2 = '\0';
		strcpy_s(reason, temp1);
		temp2++;
		strcpy_s(discri, temp2);

		try
		{
			ofstream comp_file;
			comp_file.open("C:\\xampp\\htdocs\\etmms\\complaint.txt", ios::app);
			comp_file << "---------" << endl;
			comp_file << kno<<endl;
			comp_file << endl;
			comp_file << reason << endl;
			comp_file << discri << endl;
			comp_file.close();
			mg_printf(conn, "%d", 1);
			return true;
		}
		catch (...)
		{
			mg_printf(conn, "%d", 0);
			return true;
		}
		return true;
	}
};

//new
class previous_complaint_data : public CivetHandler
{
public:
	bool
		handleGet(CivetServer *server, struct mg_connection *conn)
	{
		const struct mg_request_info *req_info = mg_get_request_info(conn);
		mg_printf(conn,
			"HTTP/1.1 200 OK\r\nAccess-Control-Allow-Origin: *\r\nContent-Type: text/html\r\nConnection: "
			"close\r\n\r\n");
		char url_data[1000];
		strcpy_s(url_data, req_info->query_string);


		int flag = 0;
		char kno[20],rply[20],reason[100], discri[500];

		ifstream reg_add_file;
		reg_add_file.open("C:\\xampp\\htdocs\\etmms\\prev_complaint.txt");
		while (!reg_add_file.eof())
		{

			reg_add_file>>kno;
			if (strstr(kno, "-----"))
			{
				reg_add_file >> kno;
				if (!strstr(kno, url_data))
				{
					reg_add_file >> rply;
					reg_add_file >> reason;
					reg_add_file >> discri;
					flag++;
					mg_printf(conn, "<div id='return_data_profile' style='margin-top : 20px;'><table><tr><td colspan='4' class='temp2'><button>Complaint No : %d</button></tr><tr><td><b>KNO</b></td><td id='comp_kno'>%s</td></tr><tr><td><b>Reason</b></td><td id='comp_reason'>%s</td></tr><tr><td><b>Discripation</b></td><td id='comp_disc'>%s</td></tr></table></div>", flag, kno, reason, discri);
				}
			}
		 }
		reg_add_file.close();
		if (flag == 0)
			mg_printf(conn, "%d", 0);
			
		return true;

	}
};



//new
class admin_current_data_of_sub : public CivetHandler
{
public:
	bool
		handleGet(CivetServer *server, struct mg_connection *conn)
	{
		const struct mg_request_info *req_info = mg_get_request_info(conn);
		mg_printf(conn,
			"HTTP/1.1 200 OK\r\nAccess-Control-Allow-Origin: *\r\nContent-Type: text/html\r\nConnection: "
			"close\r\n\r\n");

		char url_data[100];
		strcpy_s(url_data, req_info->query_string);

		//printf("\n%s",url_data);
		sub_station_list *temp1_sub;

		temp1_sub = real_time_data_linklist;
		while (temp1_sub != nullptr)
		{
			if (strstr(url_data, temp1_sub->sub_id) != nullptr)
			{
				mg_printf(conn, "<div id='return_data_real_time'><table><tr><td id='total_sub_pow_out'>%f</td><td id='total_sub_pow_consume'>%f</td><td id='total_sub_voltage'>%f</td></tr></table></div>", temp1_sub->pow_out, temp1_sub->pow_con, temp1_sub->volt);
				return true;
			}
			temp1_sub = temp1_sub->next_sub;
		}
		mg_printf(conn, "%d",0);
		return true;
	}
};


//new
class admin_current_sub_sdt : public CivetHandler
{
public:
	bool
		handleGet(CivetServer *server, struct mg_connection *conn)
	{

		const struct mg_request_info *req_info = mg_get_request_info(conn);
		mg_printf(conn,
			"HTTP/1.1 200 OK\r\nAccess-Control-Allow-Origin: *\r\nContent-Type: text/html\r\nConnection: "
			"close\r\n\r\n");

		//printf("\n\n%s",req_info->query_string);

		char url_data[100];
		strcpy_s(url_data, req_info->query_string);

		sub_station_list *temp1_sub;
		step_trans_list *temp1_sdt;

		temp1_sub = real_time_data_linklist;
		while (temp1_sub != nullptr)
		{
			if (strstr(url_data, temp1_sub->sub_id) != nullptr)
			{
				mg_printf(conn, "<div id='return_data_real_time'><table><tr><td id='total_sdt_in_sub'>%d</td>", temp1_sub->total_sdt);
				temp1_sdt = temp1_sub->sdt_list;
				int tt = 1;
				while (temp1_sdt != nullptr)
				{
					mg_printf(conn, "<td id=%s_%d>%s</td>", url_data, tt, temp1_sdt->sdt_id);
					temp1_sdt = temp1_sdt->next_sdt;
					tt++;
				}
				mg_printf(conn, "</tr></table></div>");
				return true;
			}
			temp1_sub = temp1_sub->next_sub;
		}
		mg_printf(conn, "%d", 0);
		return true;
	}
};

//new
class admin_current_data_of_all_sdt_in_sub : public CivetHandler
{
public:
	bool
		handleGet(CivetServer *server, struct mg_connection *conn)
	{
		const struct mg_request_info *req_info = mg_get_request_info(conn);
		mg_printf(conn,
			"HTTP/1.1 200 OK\r\nAccess-Control-Allow-Origin: *\r\nContent-Type: text/html\r\nConnection: "
			"close\r\n\r\n");

		char url_data[100];
		strcpy_s(url_data, req_info->query_string);


		sub_station_list *temp1_sub;
		step_trans_list *temp1_sdt;

		temp1_sub = real_time_data_linklist;
		while (temp1_sub != nullptr)
		{
			if (strstr(url_data, temp1_sub->sub_id) != nullptr)
			{
				mg_printf(conn, "<div id='return_data_real_time'><table><tr>");

				temp1_sdt = temp1_sub->sdt_list;
				while (temp1_sdt != nullptr)
				{
					mg_printf(conn, "<td id='total_sdt_pow_out_%s'>%f</td><td id='total_sdt_pow_con_%s'>%f</td><td id='total_sdt_status_%s'>%d</td><td id='total_sdt_auto_mann_dec_stat_%s'>%d</td>", temp1_sdt->sdt_id, temp1_sdt->sdt_out, temp1_sdt->sdt_id, temp1_sdt->user_totl, temp1_sdt->sdt_id, temp1_sdt->status_sdt, temp1_sdt->sdt_id, temp1_sdt->auto_mann_dec_stat_sdt);
					temp1_sdt = temp1_sdt->next_sdt;
				}
				mg_printf(conn, "</tr></table></div>");
				return true;
			}
			temp1_sub = temp1_sub->next_sub;
		}
		mg_printf(conn, "%d", 0);
		return true;
	}
};


//new

class admin_change_supply_status_sdt : public CivetHandler
{
public:
	bool
		handleGet(CivetServer *server, struct mg_connection *conn)
	{
		const struct mg_request_info *req_info = mg_get_request_info(conn);
		mg_printf(conn,
			"HTTP/1.1 200 OK\r\nAccess-Control-Allow-Origin: *\r\nContent-Type: text/html\r\nConnection: "
			"close\r\n\r\n");

		char url_data[100];
		strcpy_s(url_data, req_info->query_string);

		sub_station_list *temp1_sub;
		step_trans_list *temp1_sdt;

		temp1_sub = real_time_data_linklist;
		while (temp1_sub != nullptr)
		{
			if (strstr(url_data, temp1_sub->sub_id) != nullptr)
			{
				temp1_sdt = temp1_sub->sdt_list;
				while (temp1_sdt != nullptr)
				{
					if (!strcmp(url_data, temp1_sdt->sdt_id))
					{
						if (temp1_sdt->status_sdt == 0)
							temp1_sdt->status_sdt = 1;
						else
							temp1_sdt->status_sdt = 0;
						mg_printf(conn, "%d", 1);
						return true;
					}
					temp1_sdt = temp1_sdt->next_sdt;
				}
			}
			temp1_sub = temp1_sub->next_sub;
		}
		mg_printf(conn, "%d", 0);
		return true;
	}
};


//new

class zoom_get_all_user_list_in_sdt : public CivetHandler
{
public:
	bool
		handleGet(CivetServer *server, struct mg_connection *conn)
	{
		const struct mg_request_info *req_info = mg_get_request_info(conn);
		mg_printf(conn,
			"HTTP/1.1 200 OK\r\nAccess-Control-Allow-Origin: *\r\nContent-Type: text/html\r\nConnection: "
			"close\r\n\r\n");

		char url_data[100];
		strcpy_s(url_data, req_info->query_string);

		sub_station_list *temp1_sub;
		step_trans_list *temp1_sdt;
		user_real_time_data *temp1_user;

		temp1_sub = real_time_data_linklist;

		int tt_user = 0;
		while (temp1_sub != nullptr)
		{
			if (strstr(url_data, temp1_sub->sub_id) != nullptr)
			{
				temp1_sdt = temp1_sub->sdt_list;
				while (temp1_sdt != nullptr)
				{
					if (!strcmp(url_data, temp1_sdt->sdt_id))
					{
						temp1_user = temp1_sdt->user_list;
						mg_printf(conn, "<div id='return_data_real_time'><table><tr>");
						while (temp1_user != nullptr)
						{
							tt_user++;
							mg_printf(conn, "<td id=zoom_get_user_id_%d>%s</td>", tt_user, temp1_user->kno);
							temp1_user = temp1_user->next_user;
						}
						mg_printf(conn, "<td id=total_user_id_sent>%d</td>", tt_user);
						mg_printf(conn, "</tr></table></div>");
						return true;
					}
					temp1_sdt = temp1_sdt->next_sdt;
				}
			}
			temp1_sub = temp1_sub->next_sub;
		}
		mg_printf(conn, "%d", 0);
		return true;
	}
};


//new
class zoom_get_all_user_data : public CivetHandler
{
public:
	bool
		handleGet(CivetServer *server, struct mg_connection *conn)
	{


		const struct mg_request_info *req_info = mg_get_request_info(conn);
		mg_printf(conn,
			"HTTP/1.1 200 OK\r\nAccess-Control-Allow-Origin: *\r\nContent-Type: text/html\r\nConnection: "
			"close\r\n\r\n");

		char url_data[100];
		strcpy_s(url_data, req_info->query_string);

		sub_station_list *temp1_sub;
		step_trans_list *temp1_sdt;
		user_real_time_data *temp1_user;

		temp1_sub = real_time_data_linklist;
		int status = 0;
		int tt_user = 0;
		while (temp1_sub != nullptr)
		{
			if (strstr(url_data, temp1_sub->sub_id) != nullptr)
			{
				temp1_sdt = temp1_sub->sdt_list;
				while (temp1_sdt != nullptr)
				{
					if (!strcmp(url_data, temp1_sdt->sdt_id))
					{
						temp1_user = temp1_sdt->user_list;
						mg_printf(conn, "<div id='return_data_real_time'><table><tr>");
						while (temp1_user != nullptr)
						{
							tt_user++;

							status = temp1_user->status_user;
							if (temp1_sdt->status_sdt == 0)
								status = 0;

							mg_printf(conn, "<td id=zoom_user_%d_real_data>%f</td><td id=zoom_user_%d_avg_data>%f</td><td id=zoom_user_%d_status>%d</td><td id=zoom_user_%d_decision_status>%d</td>", tt_user, temp1_user->real_time_data, tt_user, temp1_user->avg_use, tt_user, status, tt_user, temp1_user->auto_mann_dec_stat_user);
							temp1_user = temp1_user->next_user;
						}
						mg_printf(conn, "</tr></table></div>");
						return true;
					}
					temp1_sdt = temp1_sdt->next_sdt;
				}
			}
			temp1_sub = temp1_sub->next_sub;
		}
		mg_printf(conn, "%d", 0);
		return true;
	}
};


//new
class zoom_change_supply_status_user : public CivetHandler
{
public:
	bool
		handleGet(CivetServer *server, struct mg_connection *conn)
	{
		const struct mg_request_info *req_info = mg_get_request_info(conn);
		mg_printf(conn,
			"HTTP/1.1 200 OK\r\nAccess-Control-Allow-Origin: *\r\nContent-Type: text/html\r\nConnection: "
			"close\r\n\r\n");

		//printf("\n\n%s",req_info->query_string);

		char url_data[100];
		strcpy_s(url_data, req_info->query_string);

		sub_station_list *temp1_sub;
		step_trans_list *temp1_sdt;
		user_real_time_data *temp1_user;

		temp1_sub = real_time_data_linklist;
		while (temp1_sub != nullptr)
		{
			if (strstr(url_data, temp1_sub->sub_id) != nullptr)
			{
				temp1_sdt = temp1_sub->sdt_list;
				while (temp1_sdt != nullptr)
				{
					if (strstr(url_data, temp1_sdt->sdt_id) != nullptr)
					{

						temp1_user = temp1_sdt->user_list;
						while (temp1_user != nullptr)
						{
							if (!strcmp(url_data, temp1_user->kno))
							{
								temp1_user->status_user = temp1_user->status_user ^ 4;
								mg_printf(conn, "%d", 1);
								return true;
							}
							temp1_user = temp1_user->next_user;
						}
					 }
					temp1_sdt = temp1_sdt->next_sdt;
				}
			}
			temp1_sub = temp1_sub->next_sub;
		}
		mg_printf(conn, "%d", 0);
		return true;
	}
};


//new

class get_all_sdt_and_user_under_admin : public CivetHandler
{
public:
	bool
		handleGet(CivetServer *server, struct mg_connection *conn)
	{
		const struct mg_request_info *req_info = mg_get_request_info(conn);
		mg_printf(conn,
			"HTTP/1.1 200 OK\r\nAccess-Control-Allow-Origin: *\r\nContent-Type: text/html\r\nConnection: "
			"close\r\n\r\n");

		//printf("\n\n%s",req_info->query_string);

		char url_data[100];
		strcpy_s(url_data, req_info->query_string);

		sub_station_list *temp1_sub;
		step_trans_list *temp1_sdt;
		user_real_time_data *temp1_user;

		char color[6][10];
		strcpy_s(color[0], "#00BFFF"); //BLUE
		strcpy_s(color[1], "#00FF00"); //GREEN
		strcpy_s(color[2], "#FFFF00"); //YELLOW
		strcpy_s(color[3], "#FF0000"); //RED
		strcpy_s(color[4], "#FFA500"); //Orange //for overloading

		int color_code = 0;

		temp1_sub = real_time_data_linklist;
		while (temp1_sub != nullptr)
		{
			if (strstr(url_data, temp1_sub->sub_id) != nullptr)
			{
				temp1_sdt = temp1_sub->sdt_list;
				while (temp1_sdt != nullptr)
				{
					color_code = temp1_sdt->color_code_sdt;
					mg_printf(conn, "<tr><td><b>%s</b></td><td></td><td bgcolor='%s'></td></tr>", temp1_sdt->sdt_id, color[color_code]);
					temp1_user = temp1_sdt->user_list;
					while (temp1_user != nullptr)
					{
						color_code = temp1_user->color_code_user;
						mg_printf(conn, "<tr><td></td><td><b>%s</b></td><td bgcolor='%s'></td></tr>", temp1_user->kno, color[color_code]);
						temp1_user = temp1_user->next_user;
					}
					temp1_sdt = temp1_sdt->next_sdt;
				}
				mg_printf(conn, "<tr><td></td><td></td><td></td></tr>");
				return true;
			}
			temp1_sub = temp1_sub->next_sub;
		}
		mg_printf(conn, "%d", 0);
		return true;
	}
};


//new

class admin_change_auto_mann_decision_status_sdt : public CivetHandler
{
public:
	bool
		handleGet(CivetServer *server, struct mg_connection *conn)
	{
		const struct mg_request_info *req_info = mg_get_request_info(conn);
		mg_printf(conn,
			"HTTP/1.1 200 OK\r\nAccess-Control-Allow-Origin: *\r\nContent-Type: text/html\r\nConnection: "
			"close\r\n\r\n");

		char url_data[100];
		strcpy_s(url_data, req_info->query_string);
		//printf("\n%s",url_data);
		sub_station_list *temp1_sub;
		step_trans_list *temp1_sdt;

		temp1_sub = real_time_data_linklist;
		while (temp1_sub != nullptr)
		{
			if (strstr(url_data, temp1_sub->sub_id) != nullptr)
			{
				temp1_sdt = temp1_sub->sdt_list;
				while (temp1_sdt != nullptr)
				{
					if (!strcmp(url_data, temp1_sdt->sdt_id))
					{
						if (temp1_sdt->auto_mann_dec_stat_sdt == 0)
							temp1_sdt->auto_mann_dec_stat_sdt = 1;
						else
							temp1_sdt->auto_mann_dec_stat_sdt = 0;

						mg_printf(conn, "%d", 1);
						return true;
					}
					temp1_sdt = temp1_sdt->next_sdt;
				}
			}
			temp1_sub = temp1_sub->next_sub;
		}
		mg_printf(conn, "%d", 0);
		return true;
	}
};



//new
class admin_change_decision_status_user : public CivetHandler
{
public:
	bool
		handleGet(CivetServer *server, struct mg_connection *conn)
	{

		const struct mg_request_info *req_info = mg_get_request_info(conn);
		mg_printf(conn,
			"HTTP/1.1 200 OK\r\nAccess-Control-Allow-Origin: *\r\nContent-Type: text/html\r\nConnection: "
			"close\r\n\r\n");

		//printf("\n\n%s",req_info->query_string);

		char url_data[100];
		strcpy_s(url_data, req_info->query_string);
		//printf("\n%s",url_data);
		sub_station_list *temp1_sub;
		step_trans_list *temp1_sdt;
		user_real_time_data *temp1_user;

		temp1_sub = real_time_data_linklist;
		while (temp1_sub != nullptr)
		{
			if (strstr(url_data, temp1_sub->sub_id) != nullptr)
			{
				temp1_sdt = temp1_sub->sdt_list;
				while (temp1_sdt != nullptr)
				{
					if (strstr(url_data, temp1_sdt->sdt_id) != nullptr)
					{
						temp1_user = temp1_sdt->user_list;
						while (temp1_user != nullptr)
						{
							if (!strcmp(url_data, temp1_user->kno))
							{
								if (temp1_user->auto_mann_dec_stat_user == 0)
									temp1_user->auto_mann_dec_stat_user = 1;
								else
									temp1_user->auto_mann_dec_stat_user = 0;
								mg_printf(conn, "%d", 1);
								return true;
							}
							temp1_user = temp1_user->next_user;
						}
					}
					temp1_sdt = temp1_sdt->next_sdt;
				}
			}
			temp1_sub = temp1_sub->next_sub;
		}
		mg_printf(conn, "%d", 0);
		return true;
	}
};



//new
class login_reset_user_password : public CivetHandler
{
public:
	bool
		handleGet(CivetServer *server, struct mg_connection *conn)
	{
		const struct mg_request_info *req_info = mg_get_request_info(conn);
		mg_printf(conn,
			"HTTP/1.1 200 OK\r\nAccess-Control-Allow-Origin: *\r\nContent-Type: text/html\r\nConnection: "
			"close\r\n\r\n");
		char url_data[1000];
		strcpy_s(url_data, req_info->query_string);

		char *temp1,emil[50];
		temp1 = strchr(url_data,'&');
		*temp1 = '\0';
		temp1++;
		strcpy_s(emil, temp1);
		char kno[50];
		ifstream reg_add_file;
		reg_add_file.open("C:\\xampp\\htdocs\\etmms\\registration_file.txt");
		while (!reg_add_file.eof())
		{
			reg_add_file >> kno;
			if (strstr(kno, "-----"))
			{
				reg_add_file >> kno;
				if (!strcmp(kno, url_data))
				{
					reg_add_file >> kno; //psw
					reg_add_file >> kno; //email
					if (!strcmp(kno, emil))
					{
						//send mail to user by password
						mg_printf(conn,"%d",1);
						return true;
					}
					else
					{
						mg_printf(conn, "%d", 2);
						return true;
					}
				}
			
		   }
		}
		mg_printf(conn, "%d", 0);
		return true;
	}
};


//new
class user_past_power_statistics : public CivetHandler
{
public:
	bool
		handleGet(CivetServer *server, struct mg_connection *conn)
	{
		const struct mg_request_info *req_info = mg_get_request_info(conn);
		mg_printf(conn,
			"HTTP/1.1 200 OK\r\nAccess-Control-Allow-Origin: *\r\nContent-Type: text/html\r\nConnection: "
			"close\r\n\r\n");
		char url_data[1000];
		strcpy_s(url_data, req_info->query_string);
		char file_path[500];
		strcpy_s(file_path,"C:\\xampp\\htdocs\\etmms\\database\\");
		strcat_s(file_path,url_data);
		strcat_s(file_path, ".txt");
		
		ifstream reg_add_file;
		reg_add_file.open(file_path);
		
		int i = 0,j=1;
		double con = 0,pow_con=0;
		mg_printf(conn, "<div><table><tr>");
		while (!reg_add_file.eof())
		{
			if (j > 24)
				break;

			reg_add_file >> con;
			pow_con += con;
			i++;
			if (i >= 50)
			{
				mg_printf(conn,"<td id=data_%d>%.2f</td>",j,pow_con);
				j++;
				i = 0;
				pow_con = 0;
			}
		}
		mg_printf(conn, "</tr></table></div>");
		return true;
	}
};



//new
class zoom_admin_get_geographical_location_sdt : public CivetHandler
{
public:
	bool
		handleGet(CivetServer *server, struct mg_connection *conn)
	{
		const struct mg_request_info *req_info = mg_get_request_info(conn);
		mg_printf(conn,
			"HTTP/1.1 200 OK\r\nAccess-Control-Allow-Origin: *\r\nContent-Type: text/html\r\nConnection: "
			"close\r\n\r\n");
		char url_data[1000];
		strcpy_s(url_data, req_info->query_string);

		char temp[100];
		ifstream reg_add_file;
		reg_add_file.open("C:\\xampp\\htdocs\\etmms\\realdata\\all_sdt_data.txt");

		while (!reg_add_file.eof())
		{
			reg_add_file >> temp;
			if (strstr(temp, "------"))
			{
				reg_add_file >> temp;
				if (!strcmp(temp, url_data))
				{
					reg_add_file >> temp;
					reg_add_file >> temp;
					mg_printf(conn,"%s",temp);
					reg_add_file.close();
					return true;
				}
			}
		}
		mg_printf(conn, "%d", 0);
		return true;
	}
};

char * getBhamashahNumber(char *user_id)
{
	char temp[100];
	ifstream reg_add_file;
	reg_add_file.open("C:\\xampp\\htdocs\\etmms\\registration_file.txt");

	while (!reg_add_file.eof())
	{
		reg_add_file >> temp;
		if (strstr(temp, "------"))
		{
			reg_add_file >> temp;
			if (!strcmp(temp, user_id))
			{
				int i = 0;
				for(i=0;i<13;i++)
				reg_add_file >> temp;
				return temp;
			}
		}
	}
	return NULL;
}


class calculate_return_amount : public CivetHandler
{
public:
	bool
		handleGet(CivetServer *server, struct mg_connection *conn)
	{
		const struct mg_request_info *req_info = mg_get_request_info(conn);
		mg_printf(conn,
			"HTTP/1.1 200 OK\r\nAccess-Control-Allow-Origin: *\r\nContent-Type: text/html\r\nConnection: "
			"close\r\n\r\n");

		char bill_no[30], temp[25];
		ifstream read_file;
		read_file.open("C:\\xampp\\htdocs\\etmms\\prev_bill_file.txt");
		int j = 1;
		mg_printf(conn, "<table><tr>");
		while (!read_file.eof())
		{
			read_file >> bill_no;
			if (strstr(bill_no, "-----"))
			{
				read_file >> bill_no;				
				strcpy_s(temp,getBhamashahNumber(bill_no));
				mg_printf(conn, "<td id=kno_%d>%s</td><td id=bhm_%d>%s</td>", j, bill_no, j, temp);
				j++;
			}
		}
		mg_printf(conn, "<td id=tota_kno>%d</td><td id=bhm_></td>", j-1);
		mg_printf(conn, "</tr></table>");
		read_file.close();
		return true;
	}
};



class calculate_return_amount_by_ecostatus : public CivetHandler
{
public:
	bool
		handleGet(CivetServer *server, struct mg_connection *conn)
	{
		const struct mg_request_info *req_info = mg_get_request_info(conn);
		mg_printf(conn,
			"HTTP/1.1 200 OK\r\nAccess-Control-Allow-Origin: *\r\nContent-Type: text/html\r\nConnection: "
			"close\r\n\r\n");
		char url_data[1000];
		strcpy_s(url_data, req_info->query_string);


		char *ptr = strchr(url_data, '&');
		*ptr = '\0';

		char bill_no[20], kno[20], tme[30], amnt[10], sts[20];
		int flag = 0;
		ifstream read_file;
		ofstream write_file;

		write_file.open("C:\\xampp\\htdocs\\etmms\\paid_not_return_bill.txt", ios::app);
		read_file.open("C:\\xampp\\htdocs\\etmms\\prev_bill_file.txt");
		int i = 1;
		while (!read_file.eof())
		{
			read_file >> bill_no;

			if (strstr(bill_no, "-----"))
			{
				read_file >> kno;
				read_file >> bill_no;
				read_file >> tme;
				read_file >> amnt;
				read_file >> sts;

				if (i%2==0)
				{
					write_file << "----------" << endl;
					write_file << kno << endl;
					write_file << bill_no << endl;
					write_file << tme << endl;
					write_file << amnt << endl;
					write_file << 200+i << endl;
					write_file << "Paid" << endl;
					flag = 1;
				}
				else
				{
					write_file << "----------" << endl;
					write_file << kno << endl;
					write_file << bill_no << endl;
					write_file << tme << endl;
					write_file << amnt << endl;
					write_file <<0<< endl;
					write_file << "Paid" << endl;
					flag = 1;
				}
				i++;
			}
		}

		read_file.close();
		write_file.close();
		
		return true;
	}
};



int
main(int argc, char *argv[])
{
	//call a parallel function for creating and then updating the linklist
	auto f=async(launch::async,async_function_graph_data);


	const char *options[] = {
	    "document_root", DOCUMENT_ROOT, "listening_ports", PORT, 0};
    
    std::vector<std::string> cpp_options;
    for (int i=0; i<(sizeof(options)/sizeof(options[0])-1); i++) {
        cpp_options.push_back(options[i]);
    }

	// CivetServer server(options); // <-- C style start
    CivetServer server(cpp_options); // <-- C++ style start


	//new
	user_login_check user_credentials;
	server.addHandler("/login_check_user",user_credentials);
	//new
	admin_login_check admin_credentials;
	server.addHandler("/login_check_admin", admin_credentials);
	//new
	register_user reg_user;
	server.addHandler("/register_user",reg_user);

	//new
	register_new_sdt reg_sdt;
	server.addHandler("/register_sdt_id",reg_sdt);

	//new
	get_profile_data pro_user;
	server.addHandler("/get_profile_data",pro_user);

	//new
	user_current_data user_curr_data_req;
	server.addHandler("/user_current_data", user_curr_data_req);

	//new
	user_turn_on_off_power user_turn_on_off;
	server.addHandler("/user_change_power_status", user_turn_on_off);
	
	//new
	generate_bills gen_bills;
	server.addHandler("/generate_bill", gen_bills);

	//new
	current_bill_data curr_bill_data;
	server.addHandler("/get_current_bill_data", curr_bill_data);

	//new
	previous_bill_data prev_bills;
	server.addHandler("/get_previous_bill_data", prev_bills);

	//new
	pay_energy_bill pay_bill;
	server.addHandler("/pay_energy_bill", pay_bill);

	//new
	online_complaint_request  complaint_req;
	server.addHandler("/online_request_user", complaint_req);

	//new
	previous_complaint_data prev_comp;
	server.addHandler("/get_previous_complaint_data", prev_comp);

	//new
	admin_current_sub_sdt admin_sub_sdt;
	server.addHandler("/admin_current_data_sub_sdt", admin_sub_sdt);


	//new
	admin_current_data_of_sub admin_sub_data;
	server.addHandler("/get_current_data_of_sub", admin_sub_data);

	//new
	admin_current_data_of_all_sdt_in_sub admin_all_sdt_in_sub;
	server.addHandler("/get_current_data_of_all_sdt_in_sub", admin_all_sdt_in_sub);
	
	//new
	admin_change_supply_status_sdt admin_change_sup_stt;
	server.addHandler("/admin_change_supply_status_sdt", admin_change_sup_stt);

	//new
	zoom_get_all_user_list_in_sdt zoom_user_list;
	server.addHandler("/zoom_get_all_user_list_in_sdt", zoom_user_list);

	//new
	zoom_get_all_user_data zoom_user_data;
	server.addHandler("/zoom_get_all_user_data", zoom_user_data);

	//new
	zoom_change_supply_status_user zoom_change_sup_user;
	server.addHandler("/zoom_change_supply_status_user", zoom_change_sup_user);

	//new
	get_all_sdt_and_user_under_admin all_sdt_user_admin;
	server.addHandler("/get_all_sdt_user_data_to_show", all_sdt_user_admin);

	//new
	admin_change_auto_mann_decision_status_sdt auto_mann_dec_sdt;
	server.addHandler("/admin_change_auto_mann_decision_status_sdt", auto_mann_dec_sdt);

	//new
	admin_change_decision_status_user deci_user;
	server.addHandler("/admin_change_decision_status_user", deci_user);

	//new
	login_reset_user_password reset_user_psw;
	server.addHandler("/reset_user_psw", reset_user_psw);

	//new
	user_past_power_statistics statistics_data;
	server.addHandler("/past_power_statistics",statistics_data);

	//new
	zoom_admin_get_geographical_location_sdt geo_location;
	server.addHandler("/geographical_location_sdt", geo_location);

	calculate_return_amount calcu_amunt;
	server.addHandler("/calculate_return_amount", calcu_amunt);

	calculate_return_amount_by_ecostatus calcu_ecostatus;
	server.addHandler("/calculate_return_amount_by_ecostatus",calcu_ecostatus);

	printf("Browse files at http://localhost:%s/\n", PORT);
	printf("Run example at http://localhost:%s%s\n", PORT, EXAMPLE_URI);
	printf("Exit at http://localhost:%s%s\n", PORT, EXIT_URI);

	while (!exitNow) {
#ifdef _WIN32
		Sleep(1000);
#else
		sleep(1);
#endif
	}

	printf("Bye!\n");

	return 0;
}
