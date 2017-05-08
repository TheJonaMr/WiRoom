/*jslint browser: true*/
/*global $, jQuery, alert*/

var c;
var ctx;
var img;
var i;

function changeColor(r, g, b, a, fish) {
    "use strict";
    c = document.getElementById(fish);
    ctx = c.getContext("2d");
    img = document.getElementById("fishContainer");
    ctx.drawImage(img, 0, 0);
    var imgData  = ctx.getImageData(0, 0, c.width, c.height);
    // invert colors
    for (i = 0; i < imgData.data.length; i += 4) {
        if (imgData.data[i + 3] !== 0) {
            imgData.data[i] = r;
            imgData.data[i + 1] = g;
            imgData.data[i + 2] = b;
            imgData.data[i + 3] = a;
        }
            
    }
    ctx.putImageData(imgData, 0, 0);
}

$(function ($) {
    "use strict";
    changeColor('255', '255', '255', '255', 'fish1');
});

var changed = false;
$(document).ready(function () {
    "use strict";
    $("canvas.fish").click(function () {
        if (changed === false) {
            changeColor('80', '119', '189', '255', 'fish1');
            changed = true;
        } else {
            changeColor('255', '255', '255', '255', 'fish1');
            changed = false;
        }
    });
});