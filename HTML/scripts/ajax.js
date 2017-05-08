var username = "";
var password = "";

function ajax() {
    "use strict";
    
    username = document.getElementById("username").value;
    password = document.getElementById("password").value;
    
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function () {
        if (this.readyState === 4 && this.status === 200) {
            document.getElementById("demo").innerHTML = this.responseText;
        }
    };
    
    document.getElementById("demo").innerHTML = "this.responseText<br>" + username + "<br>" + password
    xhttp.open("POST", "http://houseofege.asuscomm.com/ax/uD", true);
    xhttp.send("AJAXdat=" + "username=" + username + "&password=" + password);
}