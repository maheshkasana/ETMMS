


function onload_function()
{
   check_session();
   
   get_sub_sdt_details_for_graph();
   drawgraph_admin();
   setInterval(function() { drawgraph_admin() }, 3000);
   setInterval(function() { calculate_return_amount_to_beneficiery() }, 30000);

}

//total user button uses
total_user_button_status=false;

var economy_status_array=new Array();

/*new*/
function get_economy_status_api(id)
 {
  var xhttp;
      if (window.XMLHttpRequest)
          xhttp = new XMLHttpRequest();
      else if (window.ActiveXObject)
          xhttp = new ActiveXObject("Msxml2.XMLHTTP");
        var flag=false;
        var eco_flag;
      xhttp.onreadystatechange = function()
      {
        if(this.readyState==4 && this.status == 200)
          {
              var temp1="["+this.responseText+"]";
              var temp2=JSON.parse(this.responseText);
              var temp3=temp2.hof_Details;
              eco_flag=temp3.ECONOMIC_GROUP;              
        }        
      };

   var url="https://apitest.sewadwaar.rajasthan.gov.in/app/live/Service/hofAndMember/ForApp/"+id+"?client_id=ad7288a4-7764-436d-a727-783a977f1fe1";
   xhttp.open('GET', url,false); 
   xhttp.send(); 
  
   return eco_flag;
      
}


/*new*/
function get_economy_status()
{
  if(document.getElementById("temp_recive_data").innerHTML=="")
    return;
  var totkno=Number(document.getElementById("tota_kno").innerHTML);
  var i;
  for(i=1;i<=totkno;i++)
  {
     economy_status_array[i-1]=new Array();
     economy_status_array[i-1][0]=document.getElementById("kno_"+i).innerHTML;
     economy_status_array[i-1][1]=document.getElementById("bhm_"+i).innerHTML;
     //economy_status_array[i-1][2]=get_economy_status_api(economy_status_array[i-1][1]);
     economy_status_array[i-1][2]=i%2;
  
      var xhttp;
      if (window.XMLHttpRequest)
          xhttp = new XMLHttpRequest();
      else if (window.ActiveXObject)
          xhttp = new ActiveXObject("Msxml2.XMLHTTP");

      xhttp.open('GET', "http://localhost:5454/calculate_return_amount_by_ecostatus?"+economy_status_array[i-1][0]+"&"+economy_status_array[i-1][2], false);
      xhttp.send(null);  
  }
}

/*new*/
function calculate_return_amount_to_beneficiery()
{
          var xhttp;
      if (window.XMLHttpRequest)
          xhttp = new XMLHttpRequest();
      else if (window.ActiveXObject)
          xhttp = new ActiveXObject("Msxml2.XMLHTTP");

      xhttp.onreadystatechange = function()
      {
         document.getElementById("temp_recive_data").innerHTML="";  
         if(this.readyState==4 && this.status == 200)
            {
              document.getElementById("temp_recive_data").innerHTML=this.responseText;
              get_economy_status();
          }
      } 


  xhttp.open('GET', "http://localhost:5454/calculate_return_amount", false);
  xhttp.send(null);  
}
/*new*/
function add_new_sdt()
{
    var  sdt_id="",sdt_address="",sdt_location="",sdt_phase="",sdt_station_name="";
    
     sdt_id=document.getElementById("add_sdt_id").value;
     sdt_address=document.getElementById("add_sdt_address").value;
     sdt_location=document.getElementById("add_sdt_location").value;
     sdt_phase=document.getElementById("add_sdt_phase").value;
     sdt_station_name=document.getElementById("add_sdt_station_name").value;

     if(sdt_id=="" || sdt_address=="" || sdt_location=="" || sdt_phase=="" || sdt_station_name=="")
     {
      document.getElementById("loding_register_sdt").innerHTML="<p style='color: red;'><b>Enter Valid Data</b></p>";
      return;
     }
     else
     {

          var xhttp;
      if (window.XMLHttpRequest)
          xhttp = new XMLHttpRequest();
      else if (window.ActiveXObject)
          xhttp = new ActiveXObject("Msxml2.XMLHTTP");
  
      xhttp.onreadystatechange = function()
      {
        if(this.readyState<4)
        {
          document.getElementById('loding_register_sdt').innerHTML="<img src='img/loading3.gif' style='width:30%; height:100%; border-radius: 60%;'>";
        }
        else if(this.readyState==4)
          {
            if (this.status == 200)
          {
                 if(this.responseText==1)
                    {
                        document.getElementById('loding_register_sdt').innerHTML="<p style='color: green;'><b>Registration successful</b></p>";
                        //window.location.href = "admin_file.php";
                  }
                else
              {
                if(this.responseText==2)
                          document.getElementById('loding_register_sdt').innerHTML="<p style='color: red;'><b>KNO Already Existed</b></p>";
              else
                document.getElementById('loding_register_sdt').innerHTML="<p style='color: red;'><b>Registration Failed... </b></p>";
              }
          }
          
      } 
      };

  xhttp.open('GET', "http://localhost:5454/register_sdt_id?"+getCookie("username")+"&"+sdt_id+"&"+sdt_address+"&"+sdt_location+"&"+sdt_phase+"&"+sdt_station_name+"&", false);
  xhttp.send(null);  
     }


}

/*new*/
function validate_bhamashah(user_bhama,user_aadhar)
{
  var xhttp;
      if (window.XMLHttpRequest)
          xhttp = new XMLHttpRequest();
      else if (window.ActiveXObject)
          xhttp = new ActiveXObject("Msxml2.XMLHTTP");
        var flag=false;
      xhttp.onreadystatechange = function()
      {
        if(this.readyState==4 && this.status == 200)
          {
              var temp1="["+this.responseText+"]";
              var temp2=JSON.parse(this.responseText);
              var temp3=temp2.hof_Details;
              if(user_aadhar.localeCompare(temp3.AADHAR_ID)==0)
                flag=true;
        }        
      };

   var url="https://apitest.sewadwaar.rajasthan.gov.in/app/live/Service/family/details/"+user_bhama+"?client_id=ad7288a4-7764-436d-a727-783a977f1fe1";
   xhttp.open('GET', url,false); 
   xhttp.send(); 
  
  if(flag==true)
    return 1;
  else
    return 0;
}



/*new*/
function add_new_user()
{

    var  user_kno="",user_psw="",user_email="",user_hint="",user_alt_email="",user_num="",user_fname="",user_lname="",user_add="",user_dist="",user_state="",user_pin="",user_phase="",user_load="",user_tariff="",user_service="",user_conn_type="",user_meter="",user_station_code="",user_station_name="",user_aadhar="",user_bhamashah="";
    
     user_kno=document.getElementById("add_user_kno").value;
     user_psw=document.getElementById("add_user_psw").value;
     user_email=document.getElementById("add_user_email").value;
     user_hint=document.getElementById("add_user_sec_hint").value;
     user_alt_email=document.getElementById("add_user_alt_email").value;
     user_num=document.getElementById("add_user_num").value;
     user_fname=document.getElementById("add_user_fname").value;
     user_lname=document.getElementById("add_user_lname").value;
     user_add=document.getElementById("add_user_address").value;
     user_dist=document.getElementById("add_user_district").value;
     user_state=document.getElementById("add_user_state").value;
     user_pin=document.getElementById("add_user_pin").value;
     user_phase=document.getElementById("add_user_phase").value;
     user_load=document.getElementById("add_user_load").value;
     user_tariff=document.getElementById("add_user_tariff").value;
     user_service=document.getElementById("add_user_service").value;
     user_conn_type=document.getElementById("add_user_conn_type").value;
     user_meter=document.getElementById("add_user_meter_no").value;
     user_station_code=document.getElementById("add_user_station_code").value;
     user_station_name=document.getElementById("add_user_station_name").value;     
     user_aadhar=document.getElementById("add_user_aadhar").value;
     user_bhamashah=document.getElementById("add_user_bhamashah").value;

      if(validate_bhamashah(user_bhamashah,user_aadhar)==0)
      {
        document.getElementById("loding_register_user").innerHTML="<p style='color: red;'><b>Bhamashah Varification Failed</b></p>";
        return;
      }


     if(user_kno=="" || user_psw=="" || user_email=="" || user_hint=="" || user_alt_email=="" || user_num=="" || user_fname=="" || user_lname=="" || user_add=="" || user_dist=="" || user_state=="" || user_pin=="" || user_phase=="" || user_load==""|| user_tariff=="" || user_service=="" || user_conn_type=="" || user_meter=="" || user_station_code=="" || user_station_name=="" || user_aadhar=="" || user_bhamashah=="")
     {
     	document.getElementById("loding_register_user").innerHTML="<p style='color: red;'><b>Enter Valid Data</b></p>";
     	return;
     }
     else
     {

     	    var xhttp;
			if (window.XMLHttpRequest)
    			xhttp = new XMLHttpRequest();
			else if (window.ActiveXObject)
    			xhttp = new ActiveXObject("Msxml2.XMLHTTP");
	
  		xhttp.onreadystatechange = function()
   		{
  			if(this.readyState<4)
  			{
  				document.getElementById('loding_register_user').innerHTML="<img src='img/loading3.gif' style='width:30%; height:100%; border-radius: 60%;'>";
  			}
   			else if(this.readyState==4)
        	{
        		if (this.status == 200)
    			{
      		   		 if(this.responseText==1)
              			{
                  			document.getElementById('loding_register_user').innerHTML="<p style='color: green;'><b>Registration successful</b></p>";
                   			//window.location.href = "admin_file.php";
             			}
             		else
     					{
     		 		 		if(this.responseText==2)
                  				document.getElementById('loding_register_user').innerHTML="<p style='color: red;'><b>KNO Already Existed</b></p>";
							else
								document.getElementById('loding_register_user').innerHTML="<p style='color: red;'><b>Registration Failed... </b></p>";
    					}
    			}
     			
			}	
  		};

  xhttp.open('GET', "http://localhost:5454/register_user?"+user_kno+"&"+user_psw+"&"+user_email+"&"+user_hint+"&"+user_alt_email+"&"+user_num+"&"+user_fname+"&"+user_lname+"&"+user_add+"&"+user_dist+"&"+user_state+"&"+user_pin+"&"+user_aadhar+"&"+user_bhamashah+"&"+user_phase+"&"+user_load+"&"+user_tariff+"&"+user_service+"&"+user_conn_type+"&"+user_meter+"&"+user_station_code+"&"+user_station_name, false);
  xhttp.send(null);  
     }

}

function valid_num(id_sent)
{
   var data=document.getElementById(id_sent).value;
    
    var l=data.length;
    
    if(l!=10)
    	document.getElementById(id_sent+"_valid").innerHTML="<p style='color: red;'><b>*Invalid</b></p>";
    else
    	document.getElementById(id_sent+"_valid").innerHTML="<p style='color: green;'><b>*Valid</b></p>";
}



function valid_empty(id_sent)
{
   var data=document.getElementById(id_sent);
    
  if(data.value=="")
    data.style.border="2px solid red";
  else
    data.style.border="2px solid green";      
}



function valid_email(id_sent)
{
   var email=document.getElementById(id_sent).value;
    var string="@gmail.com";
    var r=email.indexOf(string);
    if(r==-1)
    	document.getElementById(id_sent+"_valid").innerHTML="<p style='color: red;'><b>*Invalid Email</b></p>";
    else
    	document.getElementById(id_sent+"_valid").innerHTML="<p style='color: green;'><b>*Valid</b></p>";
}


function valid_psw_confirm(id_sent)
{
   var psw=document.getElementById("add_user_psw").value;
   var con_psw=document.getElementById("add_user_con_psw").value;
  
   
    var r=psw.localeCompare(con_psw);
    if(r)
    	document.getElementById("add_user_con_psw_valid").innerHTML="<p style='color: red;'><b>*Does not Match</b></p>";
    else
    	document.getElementById("add_user_con_psw_valid").innerHTML="<p style='color: green;'><b>*Matched</b></p>";
}


function check_session()
{
    var $user_kno="";
  user_kno=getCookie("username");
  if(user_kno=="")
    window.location.href = "login.php";
  
  if(user_kno.length>=10)
    window.location.href = "user_file.php";
  
  return;
}


function logout_user_file()
{
     
	setCookie("");
	window.location.href = "login.php";
}




function setCookie(cname) {
    
    document.cookie = "username" + "=" + cname + ";path=/";
}

function getCookie(cname) {
    var name = cname + "=";
    var decodedCookie = decodeURIComponent(document.cookie);
    var ca = decodedCookie.split(';');
    for(var i = 0; i < ca.length; i++) {
        var c = ca[i];
        while (c.charAt(0) == ' ') {
            c = c.substring(1);
        }
        if (c.indexOf(name) == 0) {
            return c.substring(name.length, c.length);
        }
    }
    return "";
}



function logout_user()
{
  
  setCookie("");
}



//clear all previouslly entred data
function clear_data(id_sent)
{

      var modal_add_user_form = document.getElementById(id_sent);
        modal_add_user_form.style.display = "none";

        //total user button uses
        total_user_button_status=false;
}


//validate the sid
function valid_sid()
{
   var sid=document.getElementById("adam_s_id").value;
   if(sid.length!=12)
    document.getElementById("valid_sid").innerHTML="<p style='color: red;'><b>*Invalid SID</b></p>";
  else
    document.getElementById("valid_sid").innerHTML=""; 
}



//validate the Kno
function valid_kno()
{
   var kno=document.getElementById("add_user_kno").value;
   if(kno.length!=10)
    document.getElementById("add_user_kno_valid").innerHTML="<p style='color: red;'><b>*Invalid KNO</b></p>";
  else
    document.getElementById("add_user_kno_valid").innerHTML=""; 
}


/*new*/
function generate_bill(id_sent)
{

		var bill_kno=document.getElementById('bill_user_kno').value;
		var bill_date=document.getElementById('bill_user_date').value;

    var adm_id=getCookie("username");

    if(bill_kno.indexOf(adm_id)==-1)
    {
            document.getElementById("loading_"+id_sent).innerHTML="<p style='color: red;'><b>*Enter Valid Kno, Ex.  "+adm_id+"_ ... etc</b></p>";
            return ;
    }

     	    var xhttp;
			if (window.XMLHttpRequest)
    			xhttp = new XMLHttpRequest();
			else if (window.ActiveXObject)
    			xhttp = new ActiveXObject("Msxml2.XMLHTTP");
	
  		xhttp.onreadystatechange = function()
   		{
   			if(this.readyState==4 && this.status == 200)
        	{
        		if(this.responseText==0)
				    document.getElementById("loading_"+id_sent).innerHTML="<p style='color: red;'><b>*Failed Generation</b></p>";
				  else
            {            
              document.getElementById("loading_"+id_sent).innerHTML="<p style='color: green;'><b>*Successfuly Generated</b></p>";
              clear_data(id_sent);
            }
			     }	
  		};

  xhttp.open('GET', "http://localhost:5454/generate_bill?"+bill_kno, false);
  xhttp.send(null);  
 }



//new
function get_pending_complaints(id_sent)
{
   var xhttp;
      if (window.XMLHttpRequest)
          xhttp = new XMLHttpRequest();
      else if (window.ActiveXObject)
          xhttp = new ActiveXObject("Msxml2.XMLHTTP");
  
      xhttp.onreadystatechange = function()
      {    
        if(this.readyState==4 && this.status == 200)
          {
            if(this.responseText==0)
            {
           document.getElementById(id_sent).style.display='block' ;
                   document.getElementById("complaint_status").innerHTML="No Previous complaint present";
                }
            else
            {
            document.getElementById(id_sent).style.display='block' ;
                    document.getElementById("complaint_status").innerHTML="All Pending Complaints";
            document.getElementById("complaint_info_container").innerHTML=this.responseText;
          
            } 
          }
        };

  xhttp.open('GET', "http://localhost:5454/get_previous_complaint_data?"+getCookie("username"),true); 
  xhttp.send(null);  
}


//total sdt under this sub
var total_sdt_in_sub;
//store all sdt id in this array
var all_sdt_id=new Array();
// store the current data of all std in this array index -> x-1 : power, x : avg power 
var curr_data_all_sdt=new Array();
// store the current data of the sub in this array
var curr_data_sub =new Array();



 //new
 function get_sub_sdt_in_temp()
 {
   var xhttp;
      if (window.XMLHttpRequest)
          xhttp = new XMLHttpRequest();
      else if (window.ActiveXObject)
          xhttp = new ActiveXObject("Msxml2.XMLHTTP");

    //xhttp.setTimeout(function() {}, 1000);

    xhttp.onreadystatechange = function()
      {    
        if(this.readyState==4 && this.status == 200)
        {
           if(this.responseText==0)
           {
               document.getElementById("main_sub_graph").innerHTML="<p style='color: red;'><b>No Real Time Data Present</b></p>";
               alert("Failed");
               return 0;
           }
           else
           {
              document.getElementById("temp_recive_data").innerHTML=this.responseText;
              total_sdt_in_sub=Number(document.getElementById("total_sdt_in_sub").innerHTML);
              var i=1;

              curr_data_sub[0]=new Array(); //time
              curr_data_sub[1]=new Array(); //power
              curr_data_sub[2]=new Array(); //avg_power
              curr_data_sub[3]=new Array(); //volt

              curr_data_all_sdt[0]=new Array(); 
              var x;
              for(i=1;i<=total_sdt_in_sub;i++)
              {
                all_sdt_id[i]=document.getElementById(getCookie("username")+"_"+i).innerHTML;
                x=i*2;
                curr_data_all_sdt[x-1]=new Array();
                curr_data_all_sdt[x]=new Array();
              }
               return 1; 
           }

        }
      };

   xhttp.open('GET', "http://localhost:5454/admin_current_data_sub_sdt?"+getCookie("username"),false); 
   xhttp.send(null);  
 }


//new
function   get_sub_sdt_details_for_graph()
{   
   get_sub_sdt_in_temp();   
   var i;
   for(i=1;i<=total_sdt_in_sub;i++)
   {
      document.getElementById("main_graph_table_row_"+i).style.display="table-row";
      document.getElementById("main_graph_table_row_"+i+"_sdt_id").innerHTML="SDT ID : "+all_sdt_id[i];
   }
}





//new
function get_current_data_of_sub_in_temp()
{

//this function for getting data for the main graph in admin side for total data consumed by all sdt
      var xhttp;
      if (window.XMLHttpRequest)
          xhttp = new XMLHttpRequest();
      else if (window.ActiveXObject)
          xhttp = new ActiveXObject("Msxml2.XMLHTTP");
  
      xhttp.onreadystatechange = function()
      {
        if(this.readyState==4 && this.status == 200)
          {
            if(this.responseText==0)
            {
              document.getElementById("main_sub_power_graph" ).innerHTML="<p style='color: red;'><b>No Current Data Present</b></p>";  
              document.getElementById("main_sub_voltage_graph" ).innerHTML="<p style='color: red;'><b>No Current Data Present</b></p>";
              return 0;  
            }
            else
            {
              document.getElementById("temp_recive_data").innerHTML=this.responseText;
              return 1;
            }
          }
          return 0; 
       };

  xhttp.open('GET', "http://localhost:5454//get_current_data_of_sub?"+getCookie("username"), false);
  xhttp.send(null);  
 
}


//new
function get_data_all_sdt_in_sub_in_temp()
{
//this function for getting data of all sdt under the sub
      var xhttp;
      if (window.XMLHttpRequest)
          xhttp = new XMLHttpRequest();
      else if (window.ActiveXObject)
          xhttp = new ActiveXObject("Msxml2.XMLHTTP");
  
      xhttp.onreadystatechange = function()
      {
        if(this.readyState==4 && this.status == 200)
          {
            if(this.responseText==0)
              return 0;  
            else
            {
              document.getElementById("temp_recive_data").innerHTML=this.responseText;
              return 1;
            }
          } 
       };

  xhttp.open('GET', "http://localhost:5454//get_current_data_of_all_sdt_in_sub?"+getCookie("username"), false);
  xhttp.send(null);  

}


//new
function draw_graph_all_sdt_in_sub(i)
{

  var id_row="main_graph_table_row_"+i+"_power_graph";


  var stut=Number(document.getElementById("total_sdt_status_"+all_sdt_id[i]).innerHTML);
  var dec_stut=document.getElementById("total_sdt_auto_mann_dec_stat_"+all_sdt_id[i]).innerHTML;

 if(dec_stut==0)
     document.getElementById("decision_button_"+i).innerHTML="Manual Decision";
  else
     document.getElementById("decision_button_"+i).innerHTML="Automatic Decision";
    

  if(stut==0)
  {
     document.getElementById(id_row).innerHTML="<p style='color: red;'><b>No Current Data Present Or Power Turned Off</b></p>";
     document.getElementById("power_status_button_"+i).innerHTML="Start Power Supply";    
     return;
  }

  document.getElementById(id_row).innerHTML="";
  document.getElementById("power_status_button_"+i).innerHTML="Stop Power Supply";    

     
  var sdt_pow_con = {
  x: []= curr_data_sub[0],
  y: []= curr_data_all_sdt[i*2],
  type: 'scatter',
  name : 'Power Consumed'
};


  var sdt_pow_out = {
  x: []= curr_data_sub[0],
  y: []= curr_data_all_sdt[i*2-1],
  type: 'scatter',
  name : 'Power Out SDT'
};

var layout = {
                  xaxis: {title: 'Time'},
                  yaxis: {title: 'Power(KW)'},
                  margin: {t: 40},
             };


var data = [sdt_pow_out,sdt_pow_con];
Plotly.newPlot(id_row, data, layout);
}


//new
function drawgraph_admin()
{
    check_session();


  //call function to draw graphs in ZOOM part of SDT
  zoom_draw_user_graph();
  
  //total user part
  show_all_users_under_admin(); 
 
  
   //this function for getting data for the main graph in admin side for total data consumed by all sdt
   if(get_current_data_of_sub_in_temp()==0)
   {
    document.getElementById("main_sub_power_graph" ).innerHTML="<p style='color: red;'><b>No Current Data Present</b></p>";  
    document.getElementById("main_sub_voltage_graph" ).innerHTML="<p style='color: red;'><b>No Current Data Present</b></p>";
    return;
   }

  var i=0;
  for(i=19;i>0;i--)
  {
     curr_data_sub[0][i]=curr_data_sub[0][i-1];
     curr_data_sub[1][i]=curr_data_sub[1][i-1];
     curr_data_sub[2][i]=curr_data_sub[2][i-1];
     curr_data_sub[3][i]=curr_data_sub[3][i-1];         
  }

  curr_data_sub[0][0]=new Date();
  curr_data_sub[1][0]=Number(document.getElementById("total_sub_pow_out").innerHTML);
  curr_data_sub[2][0]=Number(document.getElementById("total_sub_pow_consume").innerHTML);
  curr_data_sub[3][0]=Number(document.getElementById("total_sub_voltage").innerHTML);
  
  var sub_pow_out = {
    x: []=curr_data_sub[0],
    y: []=curr_data_sub[1],
    type: 'scatter',
    name: 'Power All SDT'
};


  var sub_pow_con = {
  x: []= curr_data_sub[0],
  y: []= curr_data_sub[2],
  type: 'scatter',
  name: 'Power All User\'s'
};

  var voltage = {
  x: []= curr_data_sub[0],
  y: []= curr_data_sub[3],
  type: 'scatter',
  name : 'Voltage'
};


var layout = {
                  xaxis: {title: 'Time'},
                  yaxis: {title: 'Power(KW)'},
                  margin: {t: 40},
             };

var data = [sub_pow_out,sub_pow_con];
Plotly.newPlot('main_sub_power_graph', data, layout);
  
  var layout1 = {
                  xaxis: {title: 'Time'},
                  yaxis: {title: 'Volt'},
                  margin: {t: 40},
             };

var data = [voltage];
Plotly.newPlot('main_sub_voltage_graph', data, layout1);


get_data_all_sdt_in_sub_in_temp();
var j=0;

for(j=1;j<=total_sdt_in_sub;j++)
 {
  for(i=19;i>0;i--)
   {
       var x;
       x=j*2;
       curr_data_all_sdt[x][i]=curr_data_all_sdt[x][i-1];
       curr_data_all_sdt[x-1][i]=curr_data_all_sdt[x-1][i-1];
    }
}

for(j=1;j<=total_sdt_in_sub;j++)
 {

      curr_data_all_sdt[j*2-1][0]=document.getElementById("total_sdt_pow_out_"+all_sdt_id[j]).innerHTML;
      curr_data_all_sdt[j*2][0]=document.getElementById("total_sdt_pow_con_"+all_sdt_id[j]).innerHTML;      
 }

for(i=1;i<=total_sdt_in_sub;i++)
  draw_graph_all_sdt_in_sub(i);
   
}


//new
function turn_off_on_power_sdt(id_sent)
{
 
  var xhttp;
      if (window.XMLHttpRequest)
          xhttp = new XMLHttpRequest();
      else if (window.ActiveXObject)
          xhttp = new ActiveXObject("Msxml2.XMLHTTP");

      xhttp.onreadystatechange = function()
      {
        if(this.readyState==4 && this.status == 200)
          {
            if(this.responseText==0)
              return 0;  
            else
            {
              var id_row="main_graph_table_row_"+id_sent+"_power_graph";
              document.getElementById(id_row).innerHTML="";
              return 1;
            }
          } 
       };

   xhttp.open('GET', "http://localhost:5454/admin_change_supply_status_sdt?"+all_sdt_id[id_sent],true); 
   xhttp.send(null); 

}


var zoom_all_user_id_sdt=new Array();
var zoom_total_user_in_sdt;
var zoom_flag_update_graph=false;
var zoom_all_user_real_time_data=new Array();

//new
function zoom_get_all_user_in_sdt_in_temp(id)
{

//this function for getting list of all users in the current sdt called for zoom

      var xhttp;
      if (window.XMLHttpRequest)
          xhttp = new XMLHttpRequest();
      else if (window.ActiveXObject)
          xhttp = new ActiveXObject("Msxml2.XMLHTTP");
  
      xhttp.onreadystatechange = function()
      {
        if(this.readyState==4 && this.status == 200)
          {
            if(this.responseText==0)
              return 0;  
            else
            {
              document.getElementById("temp_recive_data").innerHTML="";
              document.getElementById("temp_recive_data").innerHTML=this.responseText;
              return 1;
            }
          } 
       };

  xhttp.open('GET', "http://localhost:5454//zoom_get_all_user_list_in_sdt?"+id, false);
  xhttp.send(null);  

  return 0;
}


//new
function zoom_view_all_user_in_sdt(id)
{

  zoom_total_user_in_sdt=0;
  zoom_get_all_user_in_sdt_in_temp(all_sdt_id[id]);  
  
  zoom_total_user_in_sdt=document.getElementById("total_user_id_sent").innerHTML;

  var i,j;
  zoom_all_user_id_sdt[0]=all_sdt_id[id];

  for(i=1;i<=zoom_total_user_in_sdt;i++)
  {
    zoom_all_user_id_sdt[i]=document.getElementById("zoom_get_user_id_"+i).innerHTML;
    j=2*(i-1);
    zoom_all_user_real_time_data[j]=new Array();
    zoom_all_user_real_time_data[j+1]=new Array();  
  }
    
   document.getElementById("zoom_sdt_user_list_data").style.display="block";
   
   document.getElementById("zoom_sdt_id").innerHTML="<h4>All User's Under SDT ID : "+all_sdt_id[id]+"</h4>";
   
   for(i=1;i<=zoom_total_user_in_sdt;i++)
   {
     document.getElementById("zoom_sdt_table_row_"+i).style.display="table-row"; 
     document.getElementById("zoom_sdt_table_row_"+i+"_user_id").innerHTML="<b>"+zoom_all_user_id_sdt[i]+"</b>"; 
     document.getElementById("zoom_sdt_table_row_"+i+"_power_graph").innerHTML="";   
   }
   zoom_flag_update_graph=true;
}

//new
function zoom_get_data_all_user_in_temp(id)
{
//this function for getting data of real time data of all users
      var xhttp;
      if (window.XMLHttpRequest)
          xhttp = new XMLHttpRequest();
      else if (window.ActiveXObject)
          xhttp = new ActiveXObject("Msxml2.XMLHTTP");
  
      xhttp.onreadystatechange = function()
      {
        if(this.readyState==4 && this.status == 200)
          {
            if(this.responseText==0)
              return 0;  
            else
            {
              document.getElementById("temp_recive_data").innerHTML="";
              document.getElementById("temp_recive_data").innerHTML=this.responseText;
              return 1;
            }
          } 
       };

  xhttp.open('GET', "http://localhost:5454//zoom_get_all_user_data?"+id, false);
  xhttp.send(null);  

  return 0;
}




//new
function zoom_draw_each_user_graph(i)
{

  var id="zoom_sdt_table_row_"+i+"_power_graph";

  var stut=document.getElementById("zoom_user_"+i+"_status").innerHTML;
  var dec_stut=document.getElementById("zoom_user_"+i+"_decision_status").innerHTML;

  if(dec_stut==0)
         document.getElementById("zoom_decision_status_button_"+i).innerHTML="Manual Decision";    
  else
         document.getElementById("zoom_decision_status_button_"+i).innerHTML="Automatic Decision";    

  
  if(stut==0)
  {
     document.getElementById(id).innerHTML="<p style='color: red;'><b>Power Turned Off</b></p>";
     document.getElementById("zoom_power_status_button_"+i).innerHTML="Start Power supply";    
     return;
  }

 if(stut==1)
 {
    document.getElementById(id).innerHTML="";
    document.getElementById("zoom_power_status_button_"+i).innerHTML="Stop Power Supply";    

    var k=2*(i-1);

    var user_consume = {
    x: []=curr_data_sub[0],
    y: []= zoom_all_user_real_time_data[k],
    type: 'scatter',
    name : 'Power'
    };


    var user_avg = {
    x: []= curr_data_sub[0], 
    y: []= zoom_all_user_real_time_data[k+1],
    type: 'scatter',
    name : 'Average Power'
    };


var layout = {
                  xaxis: {title: 'Time'},
                  yaxis: {title: 'Power(KW)'},
                  margin: {t: 40},
             };


    var data = [user_consume,user_avg];
    Plotly.newPlot(id, data,layout);
    return ;
}

     document.getElementById(id).innerHTML="<p style='color: red;'><b>Power Turned Off by user</b></p>";
     document.getElementById("zoom_power_status_button_"+i).innerHTML="Start Power Supply";    
}




//new
function zoom_draw_user_graph()
{
   if(zoom_flag_update_graph==false)
    return;


   zoom_get_data_all_user_in_temp(zoom_all_user_id_sdt[0]);
   var i,j,k;

  for(j=1;j<=zoom_total_user_in_sdt;j++)
  {
    k=2*(j-1);
   for(i=19;i>0;i--)
   {
      zoom_all_user_real_time_data[k][i]=zoom_all_user_real_time_data[k][i-1];
      zoom_all_user_real_time_data[k+1][i]=zoom_all_user_real_time_data[k+1][i-1];      
   }
 }

   for(i=1;i<=zoom_total_user_in_sdt;i++)
   {
     j=2*(i-1);
     zoom_all_user_real_time_data[j][0]=document.getElementById("zoom_user_"+i+"_real_data").innerHTML;
     zoom_all_user_real_time_data[j+1][0]=document.getElementById("zoom_user_"+i+"_avg_data").innerHTML;
   } 


 for(i=1;i<=zoom_total_user_in_sdt;i++)
  zoom_draw_each_user_graph(i);

}



//new
function zoom_clear_data()
{
  zoom_flag_update_graph=false;

   document.getElementById("zoom_sdt_id").innerHTML="";
   
   for(i=1;i<=zoom_total_user_in_sdt;i++)
   {
     document.getElementById("zoom_sdt_table_row_"+i).style.display="none"; 
     document.getElementById("zoom_sdt_table_row_"+i+"_user_id").innerHTML=""; 
     document.getElementById("zoom_sdt_table_row_"+i+"_power_graph").innerHTML="";   
   }
  
    document.getElementById("zoom_sdt_user_list_data").style.display="none";


}



//new
function zoom_power_turn_on_off(id_sent)
{

  var xhttp;
      if (window.XMLHttpRequest)
          xhttp = new XMLHttpRequest();
      else if (window.ActiveXObject)
          xhttp = new ActiveXObject("Msxml2.XMLHTTP");

     xhttp.onreadystatechange = function()
      {
        if(this.readyState==4 && this.status == 200)
          {
            if(this.responseText==0)
              return 0;  
            else
            {
              var id_row="zoom_sdt_table_row_"+id_sent+"_power_graph";
              document.getElementById(id_row).innerHTML="";
              return 1;
            }
          } 
       };
    
   xhttp.open('GET', "http://localhost:5454/zoom_change_supply_status_user?"+zoom_all_user_id_sdt[id_sent],true); 
   xhttp.send(null); 

}




//new
function get_all_sdt_user_data_to_show_total_user_in_temp()
{
//this function for getting all users and sdt under admin

      var xhttp;
      if (window.XMLHttpRequest)
          xhttp = new XMLHttpRequest();
      else if (window.ActiveXObject)
          xhttp = new ActiveXObject("Msxml2.XMLHTTP");

      xhttp.onreadystatechange = function()
      {
        if(this.readyState==4 && this.status == 200)
          {
            if(this.responseText==0)
              {
                 document.getElementById("all_user_sdt_under_admin_table").innerHTML="<tr><td style='width: 40%;'></td><td style='width: 50%;'></td><td style='width: 10%;'></td></tr><tr ><td><b>SDT ID</b></td><td><b>USER ID</b></td><td><b>STATUS COLOUR</b></td></tr><tr><td colspan='3'>No Data Recived</td></tr>"; 
                 return 0;  
              }
            else
            {
              document.getElementById("all_user_sdt_under_admin_table").innerHTML="<tr><td style='width: 40%;'></td><td style='width: 50%;'></td><td style='width: 10%;'></td></tr><tr ><td><b>SDT ID</b></td><td><b>USER ID</b></td><td><b>STATUS COLOUR</b></td></tr>"+this.responseText; 
              return 1;
            }
          } 
       };

  xhttp.open('GET', "http://localhost:5454//get_all_sdt_user_data_to_show?"+getCookie('username'), false);
  xhttp.send(null);  

  return 0;
}


//new
function  show_all_users_under_admin()
{
  if(total_user_button_status==false)
   return;
  
   get_all_sdt_user_data_to_show_total_user_in_temp();    

}


//new
function show_all_users_under_admin_button()
{
   total_user_button_status=true;
   document.getElementById("all_user_sdt_under_admin").style.display="block";
   show_all_users_under_admin();  
}











//new
function change_decision_status_sdt(id)
{
  var xhttp;
      if (window.XMLHttpRequest)
          xhttp = new XMLHttpRequest();
      else if (window.ActiveXObject)
          xhttp = new ActiveXObject("Msxml2.XMLHTTP");

    //xhttp.setTimeout(function() {}, 1000);

   xhttp.open('GET', "http://localhost:5454/admin_change_auto_mann_decision_status_sdt?"+all_sdt_id[id],false); 
   xhttp.send(null); 

}


//new
function zoom_change_decision_status(id)
{
  var xhttp;
      if (window.XMLHttpRequest)
          xhttp = new XMLHttpRequest();
      else if (window.ActiveXObject)
          xhttp = new ActiveXObject("Msxml2.XMLHTTP");

    //xhttp.setTimeout(function() {}, 1000);

   xhttp.open('GET', "http://localhost:5454/admin_change_decision_status_user?"+zoom_all_user_id_sdt[id],false); 
   xhttp.send(null); 

}


 function initMap(X=18.7068549,Y=73.8751820) {

                         var uluru = {lat: X, lng: Y};
                         var map = new google.maps.Map(document.getElementById("google_map_info_container"), {
                         zoom: 1,
                         center: uluru
                        });
        var marker = new google.maps.Marker({
          position: uluru,
          map: map
        });         
      }

//new
function geographical_location_sdt(id)
{

  document.getElementById('google_map').style.display='block';


}


var alarm_var_admin=false;

function set_alarm_admin()
{
  
  if(alarm_var_admin==false)
  {
    alert("Alarm Set");
    document.getElementById("set_alarm_button").innerHTML="&nbsp;&nbsp;Reset Alarm";
    alarm_var_admin=true;
  }
  else
  {
    alert("Alarm ReSet");
    document.getElementById("set_alarm_button").innerHTML="&nbsp;&nbsp;Set Alarm";
    alarm_var_admin=false;
  }
}



function change_sdt_limit_value(id)
{
    document.getElementById("change_limit_value").style.display='block';
    
}

function change_limit_value_sdt()
{
  document.getElementById("change_limit_value").style.display='none';
}