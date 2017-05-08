/*jslint browser: true*/
/*global $, jQuery, alert*/

var darkCover;
var idTop;
var idLeft;

function f(id) {
    "use strict";
    darkCover = document.getElementById("darkCover");
    idTop = id.offsetTop;
    idLeft = id.offsetLeft;
    
    $(id).toggleClass("control-animate control-hover");
    
    $(darkCover).toggleClass("noDarkCover darkCover");
    
    id.innerHTML = id.offsetTop + "_" + id.offsetLeft;

}