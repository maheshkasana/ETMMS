


//check the login credentials 
function check_login_user()
{
//    /* get data from login form */
    var user_kno=document.getElementById('user_kno').value;
    var user_psw=document.getElementById('user_psw').value;
    
    var xhttp;
	if (window.XMLHttpRequest)
    	xhttp = new XMLHttpRequest();
	else if (window.ActiveXObject)
    	xhttp = new ActiveXObject("Msxml2.XMLHTTP");
	
  xhttp.onreadystatechange = function()
   {
  	if(this.readyState<4)
  	{
  		document.getElementById('loading').innerHTML="<img src='img/loading3.gif' style='width:30%; height:100%; border-radius: 60%;'>";
  	}
   else if(this.readyState==4)
        {
        	if (this.status == 200)
    		{
      		    if(this.responseText==1)
              {
                  document.getElementById('loading').innerHTML="<p style='color: green;'><b>Login successful, and im redirecting you wait......</b></p>";
                   setCookie(user_kno);
                   window.location.href = "user_file.php";
               }
              else
              {
                    document.getElementById('loading').innerHTML="<p style='color: red;'><b>Kno or password doesnt existed</b></p>" ;      
              }  
		   	}
     		else
     		{
     		  document.getElementById('loading').innerHTML="<p style='color: red;'><b>Login Failed... </b></p>";
        
    		}
		}
  };

  xhttp.open('GET', "http://localhost:5454/login_check_user?"+user_kno+"&"+user_psw+"&", true);
  xhttp.send(null);   
 
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



//validate the Kno
function valid_kno()
{
   var kno=document.getElementById("user_kno").value;
   if(kno.length!=10)
    document.getElementById("valid_kno").innerHTML="<p style='color: red;'><b>*Invalid KNO</b></p>";
  else
    document.getElementById("valid_kno").innerHTML=""; 
}



//clear all previouslly entred data
function clear_data(id)
{
      var temp = document.getElementById(id);
        temp.style.display = "none";
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



function valid_empty(id_sent)
{
   var data=document.getElementById(id_sent);
    
  if(data.value=="")
    data.style.border="2px solid red";
  else
    data.style.border="2px solid green";      
}



//check the login credentials 
function check_login_adam()
{
//    /* get data from login form */
    var adam_s_id=document.getElementById('adam_s_id').value;
    var adam_psw=document.getElementById('adam_psw').value;
    
    var xhttp;
  if (window.XMLHttpRequest)
      xhttp = new XMLHttpRequest();
  else if (window.ActiveXObject)
      xhttp = new ActiveXObject("Msxml2.XMLHTTP");
  
  xhttp.onreadystatechange = function()
   {
    if(this.readyState<4)
    {

      document.getElementById('loading_adam').innerHTML="<img src='img/loading3.gif' style='width:30%; height:100%; border-radius: 60%;'>";
    }
   else if(this.readyState==4)
        {  
          
          if (this.status == 200)
          {
              if(this.responseText==1)
              {
                  document.getElementById('loading_adam').innerHTML="<p style='color: green;'><b>Login successful, and im redirecting you wait......</b></p>";
                  setCookie(adam_s_id);
                   window.location.href = "admin_file.php";      
              }
              else
              {
                    document.getElementById('loading_adam').innerHTML="<p style='color: red;'><b>SID or password doesnt existed</b></p>" ;      
              }  
         }
        else
        {
          document.getElementById('loading_adam').innerHTML="<p style='color: red;'><b>Login Failed... </b></p>";
        }
    }
  };

  xhttp.open('GET', "http://localhost:5454/login_check_admin?"+adam_s_id+"&"+adam_psw+"&", true);
  xhttp.send(null);   
 
}


function reset_psw()
{
  document.getElementById('user').style.display='none';
  document.getElementById('reset').style.display='block';

}

//new
function reset_psw_user()
{
    var u_kno=document.getElementById("reset_kno").value;
    var u_email=document.getElementById("reset_email").value;

       var xhttp;
  if (window.XMLHttpRequest)
      xhttp = new XMLHttpRequest();
  else if (window.ActiveXObject)
      xhttp = new ActiveXObject("Msxml2.XMLHTTP");
  
  xhttp.onreadystatechange = function()
   {
    if(this.readyState<4)
      document.getElementById('loading_reset').innerHTML="<img src='img/loading3.gif' style='width:30%; height:100%; border-radius: 60%;'>";
    else if(this.readyState==4)
        {  
          if (this.status == 200)
          {
              if(this.responseText==1)
                  document.getElementById('loading_reset').innerHTML="<p style='color: green;'><b>Successful, Sent password to EMAIL</b></p>";
              else if(this.responseText==0)
                  document.getElementById('loading_reset').innerHTML="<p style='color: red;'><b>KNO does not Found</b></p>" ;
              else if(this.responseText==2)          
                  document.getElementById('loading_reset').innerHTML="<p style='color: red;'><b>Email Doesn't Match</b></p>" ;
         }
        else
          document.getElementById('loading_reset').innerHTML="<p style='color: red;'><b>Reset Failed</b></p>";
    }
  };
  xhttp.open('GET', "http://localhost:5454/reset_user_psw?"+u_kno+"&"+u_email, true);
  xhttp.send(null);   
}