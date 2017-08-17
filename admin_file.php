



<!DOCTYPE html>
<html>
<head>
	<title>ETMMS</title>
    <link rel="icon" href="img/icon.png" type="image/x-icon">
    <script type="text/javascript"  src="etmms_admin_file.js"></script>
    <script type="text/javascript"  src="plot.js"></script>

   <link rel="stylesheet" href="assets/dist/css/bootstrap.min.css"/>
   <link rel="stylesheet" href="assets/dist/css/bootstrap-theme.css"/>

   <link rel="stylesheet" href="common_file.css"/>

<style type="text/css">
	
  .col-3 {width: 100%;}


.menu ul {
    list-style-type: none;
    margin: 0;
    padding: 0;
}
.menu li {
    padding: 8px;
    margin-bottom: 7px;
    background-color: #262626;
    color: #ffffff;
    box-shadow: 0 1px 3px rgba(0,0,0,0.12), 0 1px 2px rgba(0,0,0,0.24);
}
.menu li:hover {
    background-color: #666666;
}
</style>

<style>
/* Full-width input fields */
input[type=text], input[type=password] {
    width: 100%;
    padding: 12px 20px;
    margin: 8px 0;
    display: inline-block;
    border: 1px solid #ccc;
    box-sizing: border-box;
}

/* Set a style for all buttons */
button {
    background-color:  #666666;
    color: white;
    padding: 14px 20px;
    margin: 8px 0;
    border: none;
    cursor: pointer;
    width: 100%;
}

/* Extra styles for the cancel button */
.cancelbtn {
    width: auto;
    padding: 10px 18px;
    background-color: #f44336;
}

/* Center the image and position the close button */
.imgcontainer {
    text-align: center;
    margin: 24px 0 12px 0;
    position: relative;
}

img.avatar {
    width: 40%;
    border-radius: 50%;
}

.container_form {
    padding: 16px;
}

span.psw {
    float: right;
    padding-top: 16px;
}

/* The Modal (background) */
.modal {
    display: none; /* Hidden by default */
    position: fixed; /* Stay in place */
    z-index: 1; /* Sit on top */
    left: 0;
    top: 0;
    width: 100%; /* Full width */
    height: 100%; /* Full height */
    overflow: auto; /* Enable scroll if needed */
    background-color: rgb(0,0,0); /* Fallback color */
    background-color: rgba(0,0,0,0.4); /* Black w/ opacity */
    padding-top: 60px;
}

/* Modal Content/Box */
.modal-content {
    background-color: #fefefe;
    margin: 5% auto 15% auto; /* 5% from the top, 15% from the bottom and centered */
    border: 1px solid #888;
    width: 60%; /* Could be more or less, depending on screen size */
    
}

/* The Close Button (x) */
.close {
    position: absolute;
    right: 50px;
    top: 0;
    color: #000;
    font-size: 35px;
    font-weight: bold;
}

.close:hover,
.close:focus {
    color: red;
    cursor: pointer;
}

/* Add Zoom Animation */
.animate_form {
    -webkit-animation: animatezoom 0.6s;
    animation: animatezoom 0.6s
}

@-webkit-keyframes animatezoom {
    from {-webkit-transform: scale(0)} 
    to {-webkit-transform: scale(1)}
}
    
@keyframes animatezoom {
    from {transform: scale(0)} 
    to {transform: scale(1)}
}

/* Change styles for span and cancel button on extra small screens */
@media screen and (max-width: 300px) {
    span.psw {
       display: block;
       float: none;
    }
    .cancelbtn {
       width: 100%;
    }
}


/* for registration form */
.td_first{
	width: 25%;
}

.td_sec{
	width: 50%;
}

.td_third{
	width: 25%;
}


table {
    font-family: arial, sans-serif;
    border-collapse: collapse;
    width: 100%;
}

td, th {
    border: 1px solid #dddddd;
    text-align: left;
    padding: 8px;
}

tr:nth-child(even) {
    background-color: #dddddd;
}

</style>



</head>
<body  onload="onload_function()">
<div class="navbar1" style="float:left; z-index : 2; opacity: 1;">
    <div class="navbar-more-overlay" style="width:100%; height:100%;"></div>
	<nav class="navbar navbar-inverse navbar-fixed-top animate">
		<div class="container">
			<div class="navbar-header" >
			   <ul class="nav navbar-nav navbar-left mobile-bar">
			        
	    	        <li><a class="navbar-brand" href="admin_file.php"><span class="glyphicon glyphicon-flash"></span><b>&nbsp;&nbsp;ETMMS</b></a></li>
				</ul>
			</div>
			<ul class="nav navbar-nav navbar-right mobile-bar">
				<li><a href="#"><span class="glyphicon glyphicon-home fa-lg"></span><b>&nbsp;&nbsp;Home</b></a></li>
				<li id="user_kno_icon"></li>
				<li id="user_logout"></li>
				<script type="text/javascript">
				var $user_kno=getCookie("username");
				  if($user_kno=="")
				  {
				  	document.getElementById('user_kno_icon').innerHTML="<a href='login.php'><span class='glyphicon glyphicon-log-in fa-lg'></span><b>&nbsp; &nbsp; LogIn</b></a>";
				  }
			      else
				  { 
				  	document.getElementById('user_kno_icon').innerHTML="<a href='#profile.php'><span class='glyphicon glyphicon-user fa-lg'></span><b>&nbsp;&nbsp;"+$user_kno+"</b></a>";

				  	document.getElementById('user_logout').innerHTML="<a onclick='logout_user_file()'><span class='glyphicon glyphicon-log-out fa-lg'></span><b>&nbsp;&nbsp;Logout</b></a>"; 	
				  }
				</script>
			</ul>
		</div>
	 </nav>
</div> 

<!MAIN table>
<table id="main_graph_table">
<tr ><td style="width: 20%; "></td><td style="width: 50%;"><p>Real Time Power Administration</p></td><td style="width: 30%;"></td></tr>
<tr ><td></td><td></td><td></td></tr>
<tr>
<td>
<div  class="left_side_info_table" style="width: 100%; ">
<div class="col-3 menu"  style=" float: top;">
  <ul>
    <li style="align-self: center;"><a href="#profile.php" style="color: white; "   onclick="document.getElementById('add_user_form').style.display='block'"><span class="glyphicon glyphicon-user"></span><b>&nbsp;&nbsp;Add New User</b></a></li>
    <li style="align-self: center;"><a href="#profile.php" style="color: white; "   onclick="document.getElementById('add_sdt_form').style.display='block'"><span class="glyphicon glyphicon-certificate"></span><b>&nbsp;&nbsp;Add New SDT</b></a></li>
    <li><a href="#profile.php" style="color: white;" onclick="set_alarm_admin()"><span class="glyphicon glyphicon-bell"></span><b id="set_alarm_button">&nbsp;&nbsp;Set Alarm</b></a></li>
    <li><a href="#profile.php" style="color: white; " onclick="get_pending_complaints('complaint_form')"><span class="glyphicon glyphicon-open-file"></span><b>&nbsp;&nbsp;Complaints</b></a></li>
    <li><a href="#profile.php" style="color: white; " onclick="show_all_users_under_admin_button()"><span class="glyphicon glyphicon-equalizer"></span><b>&nbsp;&nbsp;Total Users</b></a></li>
    <li><a href="#profile.php" style="color: white; " onclick="document.getElementById('generate_bill_form').style.display='block'"><span class="glyphicon glyphicon-print" ></span><b>&nbsp;&nbsp;Generate Bills</b></a></li>
    <li><a href="#profile.php" style="color: white; "><b>&nbsp;&nbsp;</b></a></li>
    <li><a href="#profile.php" style="color: white; "><b>&nbsp;&nbsp;</b></a></li>
    <li><a href="#profile.php" style="color: white; "><b>&nbsp;&nbsp;</b></a></li>
    <li><a href="#profile.php" style="color: white; "><b>&nbsp;&nbsp;</b></a></li>
    <li><a href="#profile.php" style="color: white; "><b>&nbsp;&nbsp;</b></a></li>


    <li><a href="#profile.php" style="color: white; " onclick="stop_graph()"><span class="glyphicon glyphicon-equalizer"></span><b id="stop_graph_data">&nbsp;&nbsp;Stop</b></a></li>
  </ul>
</div>
</div>
</td>
<td>
<div><p><h4><b>Total Power Consumed By all SDT</p></b></h4></div>
<div id="main_sub_power_graph"   style=" margin-top: 50px; "></div>
</td>
<td>
<div><p><h4><b>Voltage</p></b></h4></div>
<div id="main_sub_voltage_graph"   style=" margin-top: 50px; "></div>
</td>
</tr>

<tr ><td></td><td></td><td></td></tr>
<tr id="main_graph_table_row_1" style="display: none;">
 <td colspan="2"> 
  <div><p><h4><b id="main_graph_table_row_1_sdt_id"></b></h4></p></div>
  <div id="main_graph_table_row_1_power_graph"   style="margin-top: 50px; "></div>
 </td>
 <td>
   <button onclick="turn_off_on_power_sdt(1)" id="power_status_button_1">Power Action 1</button>
   <button onclick="zoom_view_all_user_in_sdt(1)" >View All User's</button>
   <button onclick="change_decision_status_sdt(1)" id="decision_button_1">Decision</button>
   <button onclick="geographical_location_sdt(1)" id="decision_button_1">Location</button>
   <button onclick="change_sdt_limit_value(1)" id="decision_button_1">Change Limit</button>
 </td>  
</tr>

<tr ><td></td><td></td><td></td></tr>
<tr id="main_graph_table_row_2" style="display: none;">
 <td colspan="2"> 
  <div><p><h4><b id="main_graph_table_row_2_sdt_id"></b></h4></p></div>
  <div id="main_graph_table_row_2_power_graph"></div>
 </td>
 <td>
   <button onclick="turn_off_on_power_sdt(2)" id="power_status_button_2">Power Action 2</button>
   <button onclick="zoom_view_all_user_in_sdt(2)" >View All User's</button>
   <button onclick="change_decision_status_sdt(2)" id="decision_button_2">Decision</button>
   <button onclick="geographical_location_sdt(2)" id="decision_button_2">Location</button>
   <button onclick="change_sdt_limit_value(2)" id="decision_button_2">Change Limit</button>
 </td>  
</tr>


<tr ><td></td><td></td><td></td></tr>
<tr id="main_graph_table_row_3" style="display: none;">
 <td colspan="2"> 
  <div><p><h4><b id="main_graph_table_row_3_sdt_id"></b></h4></p></div>
  <div id="main_graph_table_row_3_power_graph"   style="width: 100%; margin-top: 50px; "></div>
 </td>
 <td>
   <button onclick="turn_off_on_power_sdt(3)" id="power_status_button_3">Power Action 3</button>
   <button onclick="zoom_view_all_user_in_sdt(3)" >View All User's</button>
   <button onclick="change_decision_status_sdt(3)" id="decision_button_3">Decision</button>
   <button onclick="geographical_location_sdt(3)" id="decision_button_3">Location</button>
   <button onclick="change_sdt_limit_value(3)" id="decision_button_3">Change Limit</button>
 </td>  
</tr>


<tr ><td></td><td></td><td></td></tr>
<tr id="main_graph_table_row_4" style="display: none;">
 <td colspan="2"> 
  <div><p><h4><b id="main_graph_table_row_4_sdt_id"></b></h4></p></div>
  <div id="main_graph_table_row_4_power_graph"   style="width: 100%; margin-top: 50px; "></div>
 </td>
 <td>
   <button onclick="turn_off_on_power_sdt(4)" id="power_status_button_4">Power Action 4</button>
   <button onclick="zoom_view_all_user_in_sdt(4)" >View All User's</button>
   <button onclick="change_decision_status_sdt(4)" id="decision_button_4">Decision</button>
   <button onclick="geographical_location_sdt(4)" id="decision_button_4">Location</button>
   <button onclick="change_sdt_limit_value(4)" id="decision_button_4">Change Limit</button>
 </td>  
</tr>

<tr ><td></td><td></td><td></td></tr>
<tr id="main_graph_table_row_5" style="display: none;">
 <td colspan="2"> 
  <div><p><h4><b id="main_graph_table_row_5_sdt_id"></b></h4></p></div>
  <div id="main_graph_table_row_5_power_graph"   style="width: 100%; margin-top: 50px; "></div>
 </td>
 <td>
   <button onclick="turn_off_on_power_sdt(5)" id="power_status_button_5">Power Action 4</button>
   <button onclick="zoom_view_all_user_in_sdt(5)" >View All User's</button>
   <button onclick="change_decision_status_sdt(5)" id="decision_button_5">Decision</button>
   <button onclick="geographical_location_sdt(5)" id="decision_button_5">Location</button>
   <button onclick="change_sdt_limit_value(5)" id="decision_button_5">Change Limit</button>
 </td>  
</tr>

<tr ><td></td><td></td><td></td></tr>
<tr id="main_graph_table_row_6" style="display: none;">
 <td colspan="2"> 
  <div><p><h4><b id="main_graph_table_row_6_sdt_id"></b></h4></p></div>
  <div id="main_graph_table_row_6_power_graph"   style="width: 100%; margin-top: 50px; "></div>
 </td>
 <td>
   <button onclick="turn_off_on_power_sdt(6)" id="power_status_button_6">Power Action 4</button>
   <button onclick="zoom_view_all_user_in_sdt(6)">View All User's</button>
   <button onclick="change_decision_status_sdt(6)" id="decision_button_6">Decision</button>
   <button onclick="geographical_location_sdt(6)" id="decision_button_6">Location</button>
   <button onclick="change_sdt_limit_value(6)" id="decision_button_6">Change Limit</button>
 </td>  
</tr>
<tr>
  <td colspan="3" style="background-color:#262626; color : white; height: 30px;" id="contactus">
  
  </td>
</tr>
</table>
 <!table End >



 <!for sdt registration form>

<div id="add_sdt_form" class="modal">  
  <div class="modal-content animate_form">
    <div class="imgcontainer">
      <span onclick="clear_data('add_sdt_form')" class="close" title="Close Modal">&times;</span>
      <img style="width: 10%;" src="img/station.png" alt="SDT" class="avatar">
    </div>

    <div class="container_form">
    <button><b>New SDT Registration</b></button>
     <table style="width: 100%;">
      <tr>
        <td><label><h5><b><u>Official Information</u></b></h5></label></td>
      </tr>
      <tr>
        <td class="td_first"><label><b>SDT ID</b></label></td>
        <td  class="td_sec"><input type="text" placeholder="Enter SDT ID" id="add_sdt_id" name="add_sdt_id"  onchange="valid_empty('add_sdt_id')" required></td>
        <td  class="td_third"><div id="add_sdt_id_valid"></div></td>
      </tr>
      <tr>
        <td><label><b>Address</b></label></td>
        <td><input type="text" placeholder="Enter Address" id="add_sdt_address" name="add_sdt_address" onchange="valid_empty('add_sdt_address')"  required></td>
        <td><div id="add_sdt_address_valid"></div></td>
      </tr>
      <tr>
        <td><label><b>Location</b></label></td>
        <td><input type="text" placeholder="GoogleLocation" id="add_sdt_location" name="add_sdt_location"  onchange="valid_empty('add_sdt_location')" required></td>
        <td><div id="add_sdt_location_valid"></div></td>
      </tr>
      <tr>
        <td><label><b>Phase</b></label></td>
        <td><select id="add_sdt_phase" name="add_sdt_phase"  onchange="valid_empty('add_sdt_phase')" style="width: 100%;">
          <option value="Single Phase"><solid>Single Phase</solid></option>
          <option value="Three Phase"><solid>Three Phase</solid></option>
        </select></td>
        <td><div id="add_sdt_phase_valid"></div></td>
      </tr>
      <tr>
        <td><label><b>Power Station Name</b></label></td>
        <td><input type="text" placeholder="Power Station Name" id="add_sdt_station_name" name="="add_sdt_station_name""  onchange="valid_empty('add_sdt_station_name')" required></td>
        <td><div id="add_sdt_station_name_valid"></div></td>
      </tr>
      <tr>
        <td><button type="Reset" style="background-color:  #860000;"><b>Reset</b></button></td>
        <td><button  onclick="add_new_sdt();"  style="background-color:  #004700;"><b>Register</b></button></td>
        <td><div id="loding_register_sdt"></div></td>
      </tr>
      </table>
   </div>
   </div>
</div>

<! SDT registration form done>




 <!for registration form>

<div id="add_user_form" class="modal">  
  <div class="modal-content animate_form">
    <div class="imgcontainer">
      <span onclick="clear_data('add_user_form')" class="close" title="Close Modal">&times;</span>
      <img style="width: 10%;" src="img/user1.png" alt="User" class="avatar">
    </div>

    <div class="container_form">
    <button><b>New User Registration Form</b></button>
     <table style="width: 100%;">
      <tr>
      	<td><label><h5><b><u>Personal Information</u></b></h5></label></td>
      </tr>
      <tr>
      	<td class="td_first"><label><b>K NO</b></label></td>
      	<td  class="td_sec"><input type="text" placeholder="Enter K Number" id="add_user_kno"  onchange="valid_kno('add_user_kno')" required></td>
      	<td  class="td_third"><div id="add_user_kno_valid"></div></td>
      </tr>
      <tr>
      	<td><label><b>Password</b></label></td>
      	<td><input type="password" placeholder="Enter Password" id="add_user_psw" onchange="valid_empty('add_user_psw')"  required></td>
      	<td><div id="add_user_psw_valid"></div></td>
      </tr>
      <tr>
      	<td><label><b>Confirm Password</b></label></td>
      	<td><input type="password" placeholder="confirm Password" id="add_user_con_psw"  onchange="valid_psw_confirm('add_user_con_psw')" required></td>
      	<td><div id="add_user_con_psw_valid"></div></td>
      </tr>
      <tr>
      	<td><label><b>Email</b></label></td>
      	<td><input type="text" placeholder="xyz@gmail.com" id="add_user_email"  onchange="valid_email('add_user_email')" required></td>
      	<td><div id="add_user_email_valid"></div></td>
      </tr>
      <tr>
      	<td><label><b>Security Hint</b></label></td>
      	<td><input type="text" placeholder="" id="add_user_sec_hint"  onchange="valid_empty('add_user_sec_hint')" required></td>
      	<td><div id="add_user_sec_hint_valid"></div></td>
      </tr>
      <tr>
      	<td><label><b>Alternate Email</b></label></td>
      	<td><input type="text" placeholder="xyz@gmail.com" id="add_user_alt_email"  onchange="valid_email('add_user_alt_email')" required></td>
      	<td><div id="add_user_alt_email_valid"></div></td>
      </tr>
      <tr>
      	<td><label><b>Mobile No</b></label></td>
      	<td><input type="text" placeholder="+91**********" id="add_user_num"  onchange="valid_num('add_user_num')" required></td>
      	<td><div id="add_user_num_valid"></div></td>
      </tr>
      <tr>
      	<td><label><b>First Name</b></label></td>
      	<td><input type="text" placeholder="First Name" id="add_user_fname"  onchange="valid_empty('add_user_fname')" required></td>
      	<td><div id="add_user_fname_valid"></div></td>
      </tr>
      <tr>
      	<td><label><b>Last Name</b></label></td>
      	<td><input type="text" placeholder="Last Name" id="add_user_lname"  onchange="valid_empty('add_user_lname')" required></td>
      	<td><div id="add_user_lname_valid"></div></td>
      </tr>
      <tr>
      	<td><label><b>Address</b></label></td>
      	<td><input type="text" placeholder="Address" id="add_user_address"  onchange="valid_empty('add_user_address')" required></td>
      	<td><div id="add_user_address_valid"></div></td>
      </tr>
      <tr>
      	<td><label><b>District</b></label></td>
      	<td><input type="text" placeholder="District" id="add_user_district"  onchange="valid_empty('add_user_district')" required></td>
      	<td><div id="add_user_district_valid"></div></td>
      </tr>
      <tr>
      	<td><label><b>State</b></label></td>
      	<td><input type="text" placeholder="State" id="add_user_state"  onchange="valid_empty('add_user_state')" required></td>
      	<td><div id="add_user_state_valid"></div></td>
      </tr>
      <tr>
      	<td><label><b>PIN</b></label></td>
      	<td><input type="text" placeholder="EX : 303304" id="add_user_pin"  onchange="valid_empty('add_user_pin')" required></td>
      	<td><div id="add_user_pin_valid"></div></td>
      </tr>
    
      <tr>
        <td><label><b>Aadhar Card No</b></label></td>
        <td><input type="text" placeholder="EX : 347381****92" id="add_user_aadhar"  onchange="valid_empty('add_user_aadhar')" required></td>
        <td><div id="add_user_aadhar_valid"></div></td>
      </tr>
      <tr>
        <td><label><b>Bhamashah Card No</b></label></td>
        <td><input type="text" placeholder="EX : 33474******92" id="add_user_bhamashah"  onchange="valid_empty('add_user_bhamashah')" required></td>
        <td><div id="add_user_bhamashah_valid"></div></td>
      </tr>
      <tr>
      	<td><label><h5><b><u>Technical Information</u></b></h5></label></td>
      </tr>
      <tr>
      	<td><label><b>Phase</b></label></td>
      	<td><select id="add_user_phase"  onchange="valid_empty('add_user_phase')" style="width: 100%;">
  				<option value="Single Phase"><solid>Single Phase</solid></option>
  				<option value="Three Phase"><solid>Three Phase</solid></option>
			</select></td>
      	<td><div id="add_user_phase_valid"></div></td>
      </tr>
       <tr>
      	<td><label><b>Connected Load</b></label></td>
      	<td><select id="add_user_load"  onchange="valid_empty('add_user_load')" style="width: 100%;">
  				<option ><solid>0.50KW</solid></option>
  				<option ><solid>1.00KW</solid></option>
  				<option ><solid>Above 1.00KW</solid></option>
			</select></td>
      	<td><div id="add_user_load_valid"></div></td>
      </tr>
      <tr>
      	<td><label><b>Tariff Code</b></label></td>
      	<td><select id="add_user_tariff"  onchange="valid_empty('add_user_tariff')" style="width: 100%;">
  				<option ><solid>1</solid></option>
  				<option ><solid>2</solid></option>
  				<option ><solid>3</solid></option>
  				<option ><solid>4</solid></option>
			</select></td>
      	<td><div id="add_user_tariff_valid"><p>1 :BPL, 2 :Farmers</p><p>3 :APL</p></div></td>
      </tr>
       <tr>
      	<td><label><b>Service Status</b></label></td>
      	<td><select id="add_user_service"  onchange="valid_empty('add_user_service')" style="width: 100%;">
  				<option ><solid>R-Regular</solid></option>
  				<option ><solid>T-Temporary</solid></option>
  			</select></td>
      	<td><div id="add_user_service_valid"></div></td>
      </tr>
      <tr>
      	<td><label><b>Connection Type</b></label></td>
      	<td><select id="add_user_conn_type"  onchange="valid_empty('add_user_conn_type')" style="width: 100%;">
  				<option ><solid>Domestic</solid></option>
  				<option ><solid>Commercial</solid></option>
  			</select></td>
      	<td><div id="add_user_conn_type_valid"></div></td>
      </tr>
      <tr>
      	<td><label><b>Meter No</b></label></td>
      	<td><input type="text" placeholder="Meter number" id="add_user_meter_no"  onchange="valid_empty('add_user_meter_no')" required></td>
      	<td><div id="add_user_meter_no_valid"></div></td>
      </tr>
      <tr>
      	<td><label><b>Power Station Code</b></label></td>
      	<td><input type="text" placeholder="Power Station Code" id="add_user_station_code"  onchange="valid_empty('add_user_station_code')" required></td>
      	<td><div id="add_user_station_code_valid"></div></td>
      </tr>
      <tr>
      	<td><label><b>Power Station Name</b></label></td>
      	<td><input type="text" placeholder="Power Station Name" id="add_user_station_name"  onchange="valid_empty('add_user_station_name')" required></td>
      	<td><div id="add_user_station_name_valid"></div></td>
      </tr>
      <tr>
     	<td><button type="Reset" style="background-color:  #860000;"><b>Reset</b></button></td>
      	<td><button  onclick="add_new_user()"  style="background-color:  #004700;"><b>Register</b></button></td>
        <td><div id="loding_register_user"></div></td>
      </tr>
      </table>
    
   </div>
   </div>
</div>

<! registration form done>



 <!for bill generation form>

<div id="generate_bill_form" class="modal">  
  <div class="modal-content animate_form">
    <div class="imgcontainer">
      <span onclick="clear_data('generate_bill_form')" class="close" title="Close Modal">&times;</span>
      <img style="width: 10%;" src="img/station.png" alt="User" class="avatar">
    </div>

    <div class="container_form">
    
    <button><b>Bill Generation Form</b></button>
     <table style="width: 100%;">
      <tr>
      	<td class="td_first"><label><b>K NO</b></label></td>
      	<td  class="td_sec"><input type="text" placeholder="Enter K Number" id="bill_user_kno"  onchange="valid_kno('bill_user_kno')" required></td>
      	<td  class="td_third"><div id="bill_user_kno_valid"></div></td>
      </tr>
      <tr>
      	<td><label><b>Till Date</b></label></td>
      	<td><input type="text" placeholder="Enter Date Ex : DD/MM//YY" id="bill_user_date" onchange="valid_empty('bill_user_date')"  required></td>
      	<td><div id="bill_user_date_valid"></div></td>
      </tr>
      <tr>
     	<td><button type="Reset" style="background-color:  #660000;"><b>Reset</b></button></td>
      	<td><button  onclick="generate_bill('generate_bill_form')"  style="background-color:  #595959;"><b>Generate Bill</b></button></td>
        <td><div id="loading_generate_bill_form"></div></td>
      </tr>
      </table>
   </div>
   </div>
</div>

<! for bill generation form done>


<! Zoom for SDT div>
<div id="zoom_sdt_user_list_data" class="modal" style="display: none;">
<div class="modal-content animate_form">
  <span onclick="zoom_clear_data()" class="close" title="Close Modal">&times;</span>
   
<table id="zoom_sdt_user_graph_table">
<tr ><td style="width: 20%; "></td><td id="zoom_sdt_id" style="width: 50%;"></td><td style="width: 30%;"></td></tr>

<tr ><td></td><td></td><td></td></tr>
<tr id="zoom_sdt_table_row_1" style="display: none;">
 <td colspan="2"> 
  <div><p><h4><b id="zoom_sdt_table_row_1_user_id"></b></h4></p></div>
  <div id="zoom_sdt_table_row_1_power_graph"   style="margin-top: 50px; "></div>
 </td>
 <td>
   <button onclick="zoom_power_turn_on_off(1)" id="zoom_power_status_button_1">Power Action 1</button>
   <button onclick="zoom_change_decision_status(1)" id="zoom_decision_status_button_1">Decision</button>
   <button onclick="change_sdt_limit_value(1)" id="zoom_decision_button_1">Change Limit</button>
 </td>  
</tr>

<tr ><td></td><td></td><td></td></tr>
<tr id="zoom_sdt_table_row_2" style="display: none;">
 <td colspan="2"> 
  <div><p><h4><b id="zoom_sdt_table_row_2_user_id"></b></h4></p></div>
  <div id="zoom_sdt_table_row_2_power_graph"   style="margin-top: 50px; "></div>
 </td>
 <td>
   <button onclick="zoom_power_turn_on_off(2)" id="zoom_power_status_button_2">Power Action 2</button>
   <button onclick="zoom_change_decision_status(2)" id="zoom_decision_status_button_2">Decision</button>
   <button onclick="change_sdt_limit_value(1)" id="zoom_decision_button_1">Change Limit</button>
 </td>  
</tr>

<tr ><td></td><td></td><td></td></tr>
<tr id="zoom_sdt_table_row_3" style="display: none;">
 <td colspan="2"> 
  <div><p><h4><b id="zoom_sdt_table_row_3_user_id"></b></h4></p></div>
  <div id="zoom_sdt_table_row_3_power_graph"   style="margin-top: 50px; "></div>
 </td>
 <td>
   <button onclick="zoom_power_turn_on_off(3)" id="zoom_power_status_button_3">Power Action 3</button>
   <button onclick="zoom_change_decision_status(3)" id="zoom_decision_status_button_3">Decision</button>
   <button onclick="change_sdt_limit_value(1)" id="zoom_decision_button_1">Change Limit</button>
 </td>  
</tr>

<tr ><td></td><td></td><td></td></tr>
<tr id="zoom_sdt_table_row_4" style="display: none;">
 <td colspan="2"> 
  <div><p><h4><b id="zoom_sdt_table_row_4_user_id"></b></h4></p></div>
  <div id="zoom_sdt_table_row_4_power_graph"   style="margin-top: 50px; "></div>
 </td>
 <td>
   <button onclick="zoom_power_turn_on_off(4)" id="zoom_power_status_button_4">Power Action 4</button>
  <button onclick="zoom_change_decision_status(4)" id="zoom_decision_status_button_4">Decision</button>
   <button onclick="change_sdt_limit_value(1)" id="zoom_decision_button_1">Change Limit</button>
  </td>  
</tr>

<tr ><td></td><td></td><td></td></tr>
<tr id="zoom_sdt_table_row_5" style="display: none;">
 <td colspan="2"> 
  <div><p><h4><b id="zoom_sdt_table_row_5_user_id"></b></h4></p></div>
  <div id="zoom_sdt_table_row_5_power_graph"   style="margin-top: 50px; "></div>
 </td>
 <td>
   <button onclick="zoom_power_turn_on_off(5)" id="zoom_power_status_button_5">Power Action 5</button>
   <button onclick="zoom_change_decision_status(5)" id="zoom_decision_status_button_5">Decision</button>
   <button onclick="change_sdt_limit_value(1)" id="zoom_decision_button_1">Change Limit</button>
 </td>  
</tr>
<tr ><td></td><td></td><td></td></tr>
<tr id="zoom_sdt_table_row_6" style="display: none;">
 <td colspan="2" > 
  <div><p><h4><b id="zoom_sdt_table_row_6_user_id"></b></h4></p></div>
  <div id="zoom_sdt_table_row_6_power_graph"   style="margin-top: 50px; "></div>
 </td>
 <td>
   <button onclick="zoom_power_turn_on_off(6)" id="zoom_power_status_button_6">Power Action 6</button>
   <button onclick="zoom_change_decision_status(6)" id="zoom_decision_status_button_6">Decision</button>
   <button onclick="change_sdt_limit_value(1)" id="zoom_decision_button_1">Change Limit</button>
 </td>  
</tr>

</table>
</div>
</div>



<! To show all user sdt under admin with status>
<div id="all_user_sdt_under_admin" class="modal" style="display: none;">
<div class="modal-content animate_form">
  <span onclick="clear_data('all_user_sdt_under_admin')" class="close" title="Close Modal">&times;</span>
   
<table id="all_user_sdt_under_admin_table" style="margin-top: 50px;">

</table>
</div>
</div>




<! compalint form done>

<div id="complaint_form" class="modal">  
  <div class="modal-content animate_profile">
   <div class="imgcontainer">
      <span onclick="clear_data('complaint_form')" class="close" title="Close Modal">&times;</span>
    </div>
    <div class="container_profile">
    <button style="margin-top: 5%;" id="complaint_status"><b></b></button>
    <div id="complaint_info_container">
      
    </div>
   </div>
   </div>
</div>
<!compalint form done>


<! google map form form done>

<div id="google_map" class="modal" style="display: block;">  
  <div class="modal-content animate_profile">
   <div class="imgcontainer">
      <span onclick="clear_data('google_map')" class="close" title="Close Modal" >&times;</span>
    </div>
    <div class="container_profile">
    <button style="margin-top: 5%;" id="google_map_id"><b></b></button>
    <div id="google_map_info_container" style="width: 500px; height: 500px; min-width: 100%; min-height: 100%; background-color: green;"></div>
   </div>
   </div>
</div>
<!compalint form done>

 <script async defer src="https://maps.googleapis.com/maps/api/js?key=AIzaSyDt9Fcsq_sBaI92EisJlfvAbzKEdmlnq1Q&callback=initMap"></script>


<!change limit value>

<div id="change_limit_value" class="modal">  
  <div class="modal-content animate_profile">
   <div class="imgcontainer">
      <span onclick="clear_data('change_limit_value')" class="close" title="Close Modal" >&times;</span>
    </div>
    <div class="container_profile">
    <button style="margin-top: 5%;" id="change_limit_value"><b></b></button>
    <div id="change_limit_value_info_container">
    <table>
        <tr><td><b>Select Time</b></td>      
            <td>
                <select id="time_data_change"  onchange="valid_empty('time_data_change')" style="width: 100%; height : 40px;">
                  <option ><solid>Increase</solid></option>
                  <option ><solid>Decrease</solid></option>
                </select>
            </td>
         </tr>   
        <tr>
        <td><label><b>Value Change</b></label></td>
        <td><input type="text" placeholder="value" id="change_limit_value_input"  onchange="valid_empty('change_limit_value_input')" required></td>
        <td><div id="change_limit_value_input_valid"></div></td>
      </tr>
      <tr>
      <td><button type="Reset" style="background-color:  #860000;"><b>Reset</b></button></td>
        <td><button  onclick="change_limit_value_sdt()"  style="background-color:  #004700;"><b>Change Value</b></button></td>
        <td><div id="loding_register_user"></div></td>
      </tr>
      </table>
    
    </div>

   </div>
   </div>
</div>
<!compalint form done>

<! Temp Div to recive data and use>
<div id="temp_recive_data" style="    display: none; position: fixed; z-index: -1;"> </div>



</body>
</html>