
<!DOCTYPE html>
<html>
<head>
	<title>ETMMS</title>
    <link rel="icon" href="img/icon.png" type="image/x-icon">
    <script type="text/javascript"  src="etmms_user_file.js"></script>
    <script type="text/javascript"  src="etmms_login.js"></script>
    <script type="text/javascript"  src="plot.js"></script>

   <link rel="stylesheet" href="assets/dist/css/bootstrap.min.css"/>
   <link rel="stylesheet" href="assets/dist/css/bootstrap-theme.css"/>

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


<style type="text/css">
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

.container_profile {
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
    right: 25px;
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
.animate_profile {
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
    border: 1px solid black;
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
			        
	    	        <li><a class="navbar-brand" href="user_file.php"><span class="glyphicon glyphicon-flash"></span><b>&nbsp;&nbsp;ETMMS</b></a></li>
				</ul>
			</div>
			<ul class="nav navbar-nav navbar-right mobile-bar">
				<li><a href="#"><span class="glyphicon glyphicon-home fa-lg"></span><b>&nbsp;&nbsp;Home</b></a></li>
				<li ><a href="#contactus"><span class="glyphicon glyphicon-phone-alt fa-lg"></span><b>&nbsp;&nbsp;Contact Us</b></a></li>
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
<table>
 <tr ><td style="width: 20%; "></td><td style="width: 40%;"><p>Real Time Power Consumption</p></td><td style="width: 40%;"></td></tr>
 <tr ><td></td><td></td><td></td></tr>
  <tr>
 <td>
 <div  class="left_side_info_table" style="width: 100%;">
 <div class="col-3 menu">
  <ul>
    <li style="align-self: center;"><a href="#profile.php" style="color: white;"  onclick="get_profile_data('profile_form')"><span class="glyphicon glyphicon-user"></span><b>&nbsp;&nbsp;Profile</b></a></li>
    <li><a href="#profile.php" style="color: white; " onclick="get_current_bill('bill_form')"><span class="glyphicon glyphicon-usd"></span></span><b>&nbsp;&nbsp;Pay Energy Bill</b></a></li>
    <li><a href="#profile.php" style="color: white; "  onclick="get_previous_bill('bill_form')"><span class="glyphicon glyphicon-stats"></span><b>&nbsp;&nbsp;Previous Bill</b></a></li>
    <li><a href="#profile.php" style="color: white; "  onclick="document.getElementById('complaint_form').style.display='block'"><span class="glyphicon glyphicon-tasks"></span><b>&nbsp;&nbsp;Online Request</b></a></li>
    <li><a href="#profile.php" style="color: white; " onclick="get_previous_complaints('bill_form')"><span class="glyphicon glyphicon-open-file"></span><b>&nbsp;&nbsp;Previous Complaints</b></a></li>
    <li ><a href="#profile.php" style="color: white; " onclick="turn_off_on_power()"><span class="glyphicon glyphicon-certificate"></span><b id="power_status_button"></b></a></li>
    <li><a href="#profile.php" style="color: white; "  onclick="set_alarm_user()" ><span class="glyphicon glyphicon-bell"></span><b id="set_alarm_button">Set Alarm</b></a></li>
    <li><a href="#profile.php" style="color: white; " onclick="document.getElementById('analysis_div').style.display='block'"><span class="glyphicon glyphicon-equalizer"></span><b>&nbsp;&nbsp;Analysis</b></a></li>
     <li ><a href="#profile.php" style="color: white; "><span class="glyphicon glyphicon-phone-alt fa-lg"></span><b>&nbsp;&nbsp;</b></a></li>
	<li ><a href="#profile.php" style="color: white; "><span class="glyphicon glyphicon-bell fa-lg"></span><b>&nbsp;&nbsp;</b></a></li>
  </ul>
</div>
</div>
</td>
<td colspan="2">
	<div><p><h4><b>Power</p></b></h4></div>
	<div id="graph_power"   style="width: 100%;"></div>
</td>
</tr>

 <tr ><td></td><td></td><td></td></tr>
 
 <tr>
 <td>
 	
 </td>
 <td >
   <div><p><h4><b>Voltage</p></b></h4></div>
   <div id="graph_voltage"   style="width: 100%; "></div>
 </td>
  <td>
    <div><p><h4><b>Average Power</p></b></h4></div>
    <div id="graph_avg"   style="width: 100%;"></div>
  </td>
</tr>
<tr>
	<td colspan="3" style="background-color:#262626; color : white; height: 30px; margin-bottom: 0%;" id="contactus">
	</td>
</tr>
</table>
 <!table End >

 <!for profile form>

<div id="profile_form" class="modal">  
  <div class="modal-content animate_profile">
   <div class="imgcontainer">
      <span onclick="clear_data_profile('profile_form')" class="close" title="Close Modal">&times;</span>
    </div>
    <div class="container_profile">
    <form>
    <button style="margin-top: 5%;"><b>Consumer Profile</b></button>
     <table style="width: 100%; border-spacing: 5px;">
      <tr>
      	<td colspan="4"><label><h5><b><u>Personal Information<u></b></h5></label></td>
      </tr>
      <tr>
      	<td style="width: 20%;"><label><b>K NO</b></label></td>
      	<td  style="width: 30%;"><input type="text" id="profile_user_kno"></td>
      	<td  style="width: 20%;"><label><b>Email</b></label></div></td>
      	<td  style="width: 30%;"><input type="text" id="profile_user_email" ></div></td>
      </tr>
      <tr>
      	<td><label><b>Security Hint</b></label></td>
      	<td><input type="text" id="profile_user_sec_hint"></td>
      	<td><label><b>Alternate Email</b></label></td>
      	<td><input type="text" id="profile_user_alt_email" ></td>
      </tr>
      <tr>
      	<td><label><b>Mobile No</b></label></td>
      	<td><input type="text" id="profile_user_num" ></td>
      	<td><label><b>First Name</b></label></td>
      	<td><input type="text" id="profile_user_fname" ></td>
      </tr>
      <tr>
      	<td><label><b>Last Name</b></label></td>
      	<td><input type="text" id="profile_user_lname" ></td>
      	<td><label><b>Address</b></label></td>
      	<td><input type="text" id="profile_user_address"></td>
      </tr>
      <tr>
      	<td><label><b>District</b></label></td>
      	<td><input type="text" id="profile_user_dist" ></td>
      	<td><label><b>State</b></label></td>
      	<td><input type="text" id="profile_user_state" ></td>
      </tr>
      <tr>
      	<td><label><b>PIN</b></label></td>
      	<td><input type="text" id="profile_user_pin" ></td>
        <td><label><b>Aadhar No</b></label></td>
        <td><input type="text" id="profile_user_aadhar" ></td>
      </tr>
      <tr>
        <td><label><b>Bhamashah No</b></label></td>
        <td><input type="text" id="profile_user_bhamashah" ></td>
      </tr>
      <tr>
      	<td colspan="4"><label><h5><b><u>Technical Information<u></b></h5></label></td>
      </tr>
      <tr>
      	<td><label><b>Phase</b></label></td>
      	<td><input type="text" id="profile_user_phase" ></td>
      	<td><label><b>Connected Load</b></label></td>
      	<td><input type="text" id="profile_user_load" ></td>
      </tr>
      <tr>
      	<td><label><b>Tariff Code</b></label></td>
      	<td><input type="text" id="profile_user_tariff" ></td>
      	<td><label><b>Service Status</b></label></td>
      	<td><input type="text" id="profile_user_service" ></td>
      </tr>
      <tr>
      	<td><label><b>Connection Type</b></label></td>
      	<td><input type="text" id="profile_user_conn_type" ></td>
      	<td><label><b>Meter No</b></label></td>
      	<td><input type="text" id="profile_user_meter_no"></td>

      </tr>
      <tr>
      	<td><label><b>Power Station Code</b></label></td>
      	<td><input type="text" id="profile_user_station_code"></td>
      	<td><label><b>Power Station Name</b></label></td>
      	<td><input type="text" id="profile_user_station_name" ></td>
      </tr>
      </table>
      </form>
   </div>
   </div>
</div>



<! bill form done>

<div id="bill_form" class="modal">  
  <div class="modal-content animate_profile">
   <div class="imgcontainer">
      <span onclick="clear_data_profile('bill_form')" class="close" title="Close Modal">&times;</span>
    </div>
    <div class="container_profile">
    <button style="margin-top: 5%;" id="bill_status"><b></b></button>
    <div id="bill_info_container">
    	
    </div>
   </div>
   </div>
</div>
<! bill form done>

<! Complaint form done>

<div id="complaint_form" class="modal" style="display: none;">  
  <div class="modal-content animate_profile">
      <span onclick="clear_data_profile('complaint_form')" class="close" title="Close Modal">&times;</span>
      <div style="text-align: center; width: 100%;"><h3><b>Complaint Form</b></h3></div>
      <table style="width: 100%; margin-top: 50px;">
        <tr><td style="width: 30%;"></td><td style="width: 70%;"></td></tr>
        <tr><td></td><td></td></tr>
        <tr><td><b>Reason</b></td><td><input type="text" name="request_reason" id="request_reason"></td></tr>
        <tr><td></td><td></td></tr>
        <tr><td><b>Description</b></td><td><textarea rows="4"  id="request_description" style="width: 100%;"></textarea></td></tr>
        <tr><td></td><td></td></tr>
        <tr><td id="submit_request_status"></td><td><button onclick="submit_user_request()"><b>Submit</b></button></td></tr>     
      </table>
   </div>
</div>

<! Analysis>

<div id="analysis_div" class="modal" style="display: none;">  
  <div class="modal-content animate_profile">
      <span onclick="clear_data_profile('analysis_div')" class="close" title="Close Modal">&times;</span>
      <div style="text-align: center; width: 100%;"><h3><b>Power Consumption Statistics</b></h3></div>
      <table style="width: 100%; margin-top: 50px;">
        <tr><td style="width: 30%;"></td><td style="width: 70%;"></td></tr>
        <tr><td></td><td></td></tr>
        <tr><td><b>Select Time</b></td>      
            <td>
                <select id="past_time_data"  onchange="valid_empty('past_time_data')" style="width: 100%; height : 40px;">
                  <option ><solid>6 Months</solid></option>
                  <option ><solid>1 Year</solid></option>
                  <option ><solid>2 Year</solid></option>
                </select>
            </td>
         </tr>   
        <tr><td></td><td></td></tr>
        <tr><td id="submit_analysis_request"></td><td><button onclick="submit_analysis_request()"><b>Submit</b></button></td></tr>     
      </table>
      <div id="graph_power_statistics_period"></div>   
      <div id="graph_power_statistics"></div>
      <div id="graph_power_statistics_temp"></div>
   </div>
</div>


<! Temp Div to recive data and use>
<div id="temp_recive_data" style="    display: none; position: fixed; z-index: -1;"> </div>






</body>
</html>