<!DOCTYPE html>
<html>
<head>

<title>ETMMS</title>
<link rel="icon" href="img/icon.png" type="image/x-icon">
<script type="text/javascript"  src="etmms_login.js"></script>
</head>
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

.container {
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
    /*height: 70%;*/
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
.animate {
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

body { 
  background: url(img/data_graph.jpg) no-repeat center center fixed; 
  -webkit-background-size: cover;
  -moz-background-size: cover;
  -o-background-size: cover;
  background-size: cover;
}


</style>
<body onload="logout_user()">
<div style="width: 100%; height: 20%; position: relative; align-content: center; margin-top: 20%; ">
<solid><h1><center><b>Electricity Theft Monitoring<br>&amp;<br>Management System</b></center></h1></solid>
</div>


<div style=" width : 100%; ">
<button style="width: 20%; margin-left: 25%;" onclick="document.getElementById('user').style.display='block'" style="width:auto;">Power  Consumer</button>
<button style="width: 20%; margin-left: 10%;"  onclick="document.getElementById('adam').style.display='block'" style="width:auto;">Administration</button>


</div>



<div id="user" class="modal">
  
  <div class="modal-content animate">
    <div class="imgcontainer">
      <span onclick="clear_data('user')" class="close" title="Close Modal">&times;</span>
      <img style="width: 10%;" src="img/user1.png" alt="User" class="avatar">
    </div>
    <div class="container">
      <label><b>User's K NO</b></label>
      <input type="text" placeholder="Enter K Number" id="user_kno" name="user_kno" onchange="valid_empty('user_kno')" required>

      <label><b>Password</b></label>
      <input type="password" placeholder="Enter Password" id="user_psw" name="user_psw" required onchange="valid_empty('user_psw')">

      <button  onclick="check_login_user()">Login</button>
      <div id="loading" style="z-index: 1000;  width: 30%; height: 10%; margin-left: 45%; "></div>
    </div>
    <div class="container" style="background-color:#f1f1f1">
      <button type="button" onclick="document.getElementById('user').style.display='none'" class="cancelbtn">Cancel</button>
      <span class="psw">Forgot <a href="#" onclick="reset_psw()">password?</a></span>
    </div>
  </div>
</div>






<div id="adam" class="modal">
  <div class="modal-content animate">
    <div class="imgcontainer">
      <span onclick="clear_data('adam')" class="close" title="Close Modal">&times;</span>
       <img style="width: 10%;" src="img/station.png" alt="SubStation" class="avatar">
    </div>
    
    <div class="container">
      <label><b>Station ID</b></label>
      <input type="text" placeholder="Enter Station ID" id="adam_s_id" name="adam_s_id"  required   onchange="valid_sid()"><div id="valid_sid"></div>

      <label><b>Password</b></label>
      <input type="password" placeholder="Enter Password" id="adam_psw"  required  name="adam_psw">
        
      <button  onclick="check_login_adam()">Login</button>
      <div id="loading_adam" style="z-index: 1000;  width: 30%; height: 10%; margin-left: 45%; "></div>
    </div>
    <div class="container" style="background-color:#f1f1f1">
      <button type="button" onclick="document.getElementById('adam').style.display='none'" class="cancelbtn">Cancel</button>
    </div>
  </div>
</div>



<div id="reset" class="modal">
  
  <div class="modal-content animate">
    <div class="imgcontainer">
      <span onclick="clear_data('reset')" class="close" title="Close Modal">&times;</span>
      <img style="width: 10%;" src="img/user1.png" alt="User" class="avatar">
    </div>
    <div class="container">
      <label><b>User's K NO</b></label>
      <input type="text" placeholder="Enter K Number" id="reset_kno" name="reset_kno" onchange="valid_empty('reset_kno')" required>

      <label><b>Confirm Email</b></label>
      <input type="text" placeholder="Enter email id" id="reset_email" name="reset_email" onchange="valid_empty('reset_email')" required>

      <button  onclick="reset_psw_user()">Submit</button>
      <div id="loading_reset" style="z-index: 1000;  width: 30%; height: 10%; margin-left: 45%; "></div>
    </div>
  </div>
</div>




<script>
// Get the modal
var modal_user = document.getElementById('user');
var modal_adam = document.getElementById('adam');

// When the user clicks anywhere outside of the modal, close it
window.onclick = function(event) {
    if (event.target == modal_user || event.target == modal_adam) {
          modal_user.style.display = "none";
          modal_adam.style.display = "none";
          document.getElementById('user_kno').value="";
          document.getElementById('user_psw').value="";
          document.getElementById('loading').innerHTML="";
          document.getElementById("valid_kno").innerHTML="";
          document.getElementById('adam_s_id').value="";
          document.getElementById('adam_psw').value="";
          document.getElementById('loading_adam').innerHTML="";
          document.getElementById("valid_sid").innerHTML="";
       }
}

</script>
</body>
</html>
