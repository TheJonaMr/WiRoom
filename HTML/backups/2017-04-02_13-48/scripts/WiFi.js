/*jslint browser: true*/
/*global $, jQuery, alert*/

var canvas;
var ctx;

function draw(fillColor, incr, canv) {
    "use strict";
    canvas = document.getElementById(canv);
    if (canvas.getContext) {
        ctx = canvas.getContext('2d');

        ctx.fillStyle = fillColor;
        ctx.strokeStyle = fillColor;

        ctx.beginPath();
        ctx.arc(50, 170 + incr, 150 + incr, 0, Math.PI * -0.5, true);
        ctx.arc(50, 40, 20, Math.PI * 1.5, 1.5, true);
        ctx.arc(50, 170 + incr, 110 + incr, Math.PI * -0.5, 0, false);
        ctx.arc(180 + incr, 170 + incr, 20,  Math.PI * -1, Math.PI * -2, true);

        ctx.moveTo(50, 20);
        ctx.stroke();
        ctx.fill('evenodd');
    }
}

$(function ($) {
    "use strict";
    draw('white', 0, 'WiFi_Bar1');
    draw('white', 100, 'WiFi_Bar2');
    draw('white', 200, 'WiFi_Bar3');
});