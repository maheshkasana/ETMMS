function onload_function()
{
   check_session();
   setInterval(function() { drawgraph() }, 3000);
}



function check_session()
{
    var user_kno="";
	
	user_kno=getCookie("username");
	if(user_kno=="")
		window.location.href = "login.php";

    if(user_kno.length>5 && user_kno.length<=10)
    window.location.href = "admin_file.php";
}


function logout_user_file()
{
     
	setCookie("");
	window.location.href = "login.php";
}

//clear all previouslly entred data
/*new*/
function clear_data_profile(id_sent)
{
	 
      var modal_profile_form = document.getElementById(id_sent);
        modal_profile_form.style.display = "none";
        document.getElementById("bill_info_container").innerHTML="";
}

/*new*/
function get_profile_data(id_sent)
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
				    document.getElementById("temp_recive_data").innerHTML=this.responseText;
				    document.getElementById("profile_user_kno").value=document.getElementById("pro_kno").innerHTML;
				    document.getElementById("profile_user_email").value=document.getElementById("pro_gmail").innerHTML;
				    document.getElementById("profile_user_sec_hint").value=document.getElementById("pro_hint").innerHTML;
				    document.getElementById("profile_user_alt_email").value=document.getElementById("pro_alt_gmail").innerHTML;
				    document.getElementById("profile_user_num").value=document.getElementById("pro_nu").innerHTML;
				    document.getElementById("profile_user_fname").value=document.getElementById("pro_fname").innerHTML;
				    document.getElementById("profile_user_lname").value=document.getElementById("pro_lname").innerHTML;
				    document.getElementById("profile_user_address").value=document.getElementById("pro_add").innerHTML;
				    document.getElementById("profile_user_dist").value=document.getElementById("pro_dist").innerHTML;
				    document.getElementById("profile_user_state").value=document.getElementById("pro_state").innerHTML;
				    document.getElementById("profile_user_pin").value=document.getElementById("pro_pin").innerHTML;
          document.getElementById("profile_user_aadhar").value=document.getElementById("pro_aadhar").innerHTML;
          document.getElementById("profile_user_bhamashah").value=document.getElementById("pro_bhamashah").innerHTML;                         
					document.getElementById("profile_user_phase").value=document.getElementById("pro_phase").innerHTML;
					document.getElementById("profile_user_load").value=document.getElementById("pro_load").innerHTML;
					document.getElementById("profile_user_tariff").value=document.getElementById("pro_tariff").innerHTML;
					document.getElementById("profile_user_service").value=document.getElementById("pro_service").innerHTML;
					document.getElementById("profile_user_conn_type").value=document.getElementById("pro_type").innerHTML;
					document.getElementById("profile_user_meter_no").value=document.getElementById("pro_mnu").innerHTML;
					document.getElementById("profile_user_station_code").value=document.getElementById("pro_st_code").innerHTML;
					document.getElementById("profile_user_station_name").value=document.getElementById("pro_st_name").innerHTML;    		    				     

        	}	
  		};

  xhttp.open('GET', "http://localhost:5454/get_profile_data?"+getCookie("username"),true); 
  xhttp.send(null);  


   document.getElementById(id_sent).style.display='block' ;

}


/*new*/
function get_current_bill(id_sent)
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
                   document.getElementById("bill_status").innerHTML="No Current Bill Present";
                }
        		else
        		{
				            document.getElementById(id_sent).style.display='block' ;
                    document.getElementById("bill_status").innerHTML="Current Bill";
				            document.getElementById("bill_info_container").innerHTML=this.responseText;
        		}	
        	}
        };

  xhttp.open('GET', "http://localhost:5454/get_current_bill_data?"+getCookie("username"),true); 
  xhttp.send(null);  
}

/*new*/
function get_previous_bill(id_sent)
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
                   document.getElementById("bill_status").innerHTML="No Previous Bill Present";
                }
        		else
        		{
				            document.getElementById(id_sent).style.display='block' ;
                    document.getElementById("bill_status").innerHTML="All Previous Bill";
				            document.getElementById("bill_info_container").innerHTML=this.responseText;
        	
        		}	
        	}
        };

  xhttp.open('GET', "http://localhost:5454/get_previous_bill_data?"+getCookie("username"),true); 
  xhttp.send(null);  
}



/*new*/
function pay_energy_bill(id_sent)
{
  
   var xhttp;
			if (window.XMLHttpRequest)
    			xhttp = new XMLHttpRequest();
			else if (window.ActiveXObject)
    			xhttp = new ActiveXObject("Msxml2.XMLHTTP");

  xhttp.open('GET', "http://localhost:5454/pay_energy_bill?"+getCookie("username")+"&"+id_sent,false);
  xhttp.send(null);  

  clear_data_profile("bill_form");
}


/*new*/
function get_current_data_in_temp_div()
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
               document.getElementById("graph_power").innerHTML="<p style='color: red;'><b>No Real Time Data Present</b></p>";
               document.getElementById("graph_voltage").innerHTML="<p style='color: red;'><b>No Real Time Data Present</b></p>";
               document.getElementById("graph_avg").innerHTML="<p style='color: red;'><b>No Real Time Data Present</b></p>";
               return 0;
           }
           else
           {
              document.getElementById("temp_recive_data").innerHTML=this.responseText;
              return 1;   
           }

        }
      };

  xhttp.open('GET', "http://localhost:5454/user_current_data?"+getCookie("username"),false); 
  xhttp.send(null);  

}



/*new */
 var x=new Array();
 var y=new Array();
 var z=new Array();
 
function draw_power_graph()
{
    var var1=document.getElementById("user_real_power").innerHTML;
    var var2=document.getElementById("user_real_avg_power").innerHTML;
 
   var i;
   for(i=19;i>0;i--)
    x[i]=x[i-1];
    x[0]=new Date();;

   for(i=19;i>0;i--)
    y[i]=y[i-1];
    y[0]=Number(var1);

   for(i=19;i>0;i--)
    z[i]=z[i-1];
    z[0]=Number(var2);

   
  var Power = {
   x: []=x, 
   y: []=y,
   type: 'Solid',
   name : 'Power'

};

 var Avg_Power = {
   x: []=x, 
   y: []=z,
   type: 'scatter',
   name : 'Average Power'
};

var layout = {
                  xaxis: {title: 'Real Time'},
                  yaxis: {title: 'Power(KW)'},
                  margin: {t: 40},
             };

var data1 = [Power,Avg_Power];
Plotly.newPlot('graph_power', data1,layout);

var data2 = [Avg_Power];
Plotly.newPlot('graph_avg', data2,layout);
}



/*new*/
var a=new Array();
var v=new Array();
var t=new Array();

function draw_voltage_graph()
{

    var v1=document.getElementById("user_real_voltage").innerHTML;
    var a1=document.getElementById("user_real_avg_voltage").innerHTML;
              
   var i;
   for(i=19;i>0;i--)
    t[i]=t[i-1];
    t[0]=new Date();;

   for(i=19;i>0;i--)
    v[i]=v[i-1];
    v[0]=Number(v1);

   for(i=19;i>0;i--)
    a[i]=a[i-1];
    a[0]=Number(a1);
    

  var Voltage = {
  x: []=t,
  y: []=v,
    type: 'scatter',
    name : 'Voltage'
};

 var Avg_Voltage = {
  x: []=t,
  y: []=a, 
  type: 'scatter',
  name : 'Average Voltage'
};

var layout = {
                  xaxis: {title: 'Real Time'},
                  yaxis: {title: 'Voltage'},
                  margin: {t: 40},
             };
                  
var data1 = [Voltage,Avg_Voltage];
Plotly.newPlot('graph_voltage', data1,layout);

}




/*new*/
function drawgraph()
{

  check_session();
  
  if(get_current_data_in_temp_div()==0)
   return;

  var var1=document.getElementById("user_status").innerHTML;

   if(var1==1) 
    {
               document.getElementById("power_status_button").innerHTML="&nbsp;&nbsp;Stop Consumption";
               document.getElementById("graph_power").innerHTML="";
               document.getElementById("graph_avg").innerHTML="";
               document.getElementById("graph_voltage").innerHTML="";
               draw_power_graph();
               draw_voltage_graph();

    } 
   else
   {
          if(var1==3)
          {
               document.getElementById("power_status_button").innerHTML="&nbsp;&nbsp;Start Consumption";
               document.getElementById("graph_power").innerHTML="<h2><p style='color: red;'><b>Power Turned Off By User</b></p></h2>";
               document.getElementById("graph_avg").innerHTML="<h2><p style='color: red;'><b>Power Turned Off by User</b></p></h2>";
                document.getElementById("graph_voltage").innerHTML="";
               draw_voltage_graph(); 
          }
          else
          {
               document.getElementById("power_status_button").innerHTML="&nbsp;&nbsp;No Power Supply";
               document.getElementById("graph_power").innerHTML="<h2><p style='color: red;'><b>Power Turned off by Admin</b></p></h2>";
               document.getElementById("graph_avg").innerHTML="<h2><p style='color: red;'><b>No Power Supply</b></p></h2>";
               document.getElementById("graph_voltage").innerHTML="<h2><p style='color: red;'><b>No Power Supply</b></p></h2>";
          }
   }

}

         
/*new */
function turn_off_on_power()
{

   var xhttp;
      if (window.XMLHttpRequest)
          xhttp = new XMLHttpRequest();
      else if (window.ActiveXObject)
          xhttp = new ActiveXObject("Msxml2.XMLHTTP");

  xhttp.open('GET', "http://localhost:5454/user_change_power_status?"+getCookie("username"),false); 
  xhttp.send(null);  

   var i;
   for(i=0;i<20;i++)
    y[i]=0;

   for(i=0;i<20;i++)
    z[i]=0;

  drawgraph();
}


//new
function submit_user_request()
{
     var req_res=document.getElementById("request_reason").value;
     var req_dis=document.getElementById("request_description").value;


   var xhttp;
      if (window.XMLHttpRequest)
          xhttp = new XMLHttpRequest();
      else if (window.ActiveXObject)
          xhttp = new ActiveXObject("Msxml2.XMLHTTP");

   xhttp.onreadystatechange = function()
      {   
        if(this.readyState<4)
          document.getElementById('submit_request_status').innerHTML="<img src='img/loading3.gif' style='width:30%; height:50%; border-radius: 60%;'>";
       else if(this.readyState==4 && this.status == 200)
        {
           if(this.responseText==0)
              document.getElementById('submit_request_status').innerHTML="<p style='color: red;'><b>Failed to submit, Retry</b></p>";
           else
           {
               document.getElementById('submit_request_status').innerHTML="<p style='color: green;'><b>submited successfully</b></p>";
               document.getElementById("complaint_form").style.display="none";
           }

        }
      };


  xhttp.open('GET', "http://localhost:5454/online_request_user?"+getCookie("username")+"&"+req_res+"&"+req_dis,false); 
  xhttp.send(null);  

}


//new
function get_previous_complaints(id_sent)
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
                   document.getElementById("bill_status").innerHTML="No Previous complaint present";
                }
            else
            {
                    document.getElementById(id_sent).style.display='block' ;
                    document.getElementById("bill_status").innerHTML="All Previous Complaints";
                    document.getElementById("bill_info_container").innerHTML=this.responseText;
          
            } 
          }
        };

  xhttp.open('GET', "http://localhost:5454/get_previous_complaint_data?"+getCookie("username"),false); 
  xhttp.send(null);  
}


//new
function submit_analysis_request()
{
  var pst_time=document.getElementById("past_time_data").value;
  var n=Number(pst_time[0]);

  if(n!=6)
    n=n*12;

  var data_array=new Array();
  var x_axis=new Array();
  var time_array=["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" ];
  
  var d = new Date();
  var m=d.getMonth();  
  var y=d.getFullYear();

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
                    document.getElementById("graph_power_statistics").innerHTML="<p style='color: red;'><b>Failed to Get Statistics Data, Retry</b></p>";
            else
            {
                document.getElementById("temp_recive_data").innerHTML=this.responseText; 
                var j;
                var k=m-1;
                var l=0;
                for(j=1;j<=n;j++)
                {
                  if(k<0)
                  {
                    k=11;
                    l++;
                  }
                  data_array[j-1]=document.getElementById("data_"+j).innerHTML;
                  x_axis[j-1]=time_array[k]+" "+(y-l).toString();
                   k--; 
                }
                  
                  document.getElementById("graph_power_statistics_period").innerHTML="<h3>Statistics From "+ x_axis[n-1]+" to "+x_axis[0]+"</h3>"; 
                  var past_data = {
                  x: []=x_axis,
                  y: []=data_array,
                  name : 'Power',
                  type: 'bar'
                  };

                  var data1 = [past_data];
                  var layout = {
                                    xaxis: {title: 'Month'},
                                    yaxis: {title: 'KW(power consumed)'},
                                    margin: {t: 40},
                              };
                  Plotly.newPlot('graph_power_statistics', data1,layout);
                  document.getElementById("graph_power_statistics_temp").innerHTML="<br><br>"; 

            } 
          }
        };

  xhttp.open('GET', "http://localhost:5454/past_power_statistics?"+getCookie("username"),false); 
  xhttp.send(null); 

  }




var alarm_var=false;

function set_alarm_user()
{
  
  if(alarm_var==false)
  {
    alert("Alarm Set");
    document.getElementById("set_alarm_button").innerHTML="&nbsp;&nbsp;Reset Alarm";
    alarm_var=true;
  }
  else
  {
    alert("Alarm ReSet");
    document.getElementById("set_alarm_button").innerHTML="&nbsp;&nbsp;Set Alarm";
    alarm_var=false;
  }
}