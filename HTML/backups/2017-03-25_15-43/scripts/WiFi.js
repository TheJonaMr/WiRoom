function draw1(fillColor) {
    var canvas1 = document.getElementById('WiFi_Bar1');
    if (canvas1.getContext) {
        var ctx1 = canvas1.getContext('2d');

        ctx1.fillStyle = fillColor;
        ctx1.strokeStyle = fillColor;

        ctx1.beginPath();
        ctx1.arc(50, 170, 150, 0, Math.PI * -0.5, true);
        ctx1.arc(50, 40, 20, Math.PI * 1.5, 1.5, true);
        ctx1.arc(50, 170, 110, Math.PI * -0.5, 0, false);
        ctx1.arc(180, 170, 20,  Math.PI * -1, Math.PI * -2, true);

        ctx1.moveTo(50, 20);
        ctx1.stroke();
        ctx1.fill('evenodd');
    }
}

function draw2(fillColor) {
    var canvas2 = document.getElementById('WiFi_Bar2');
    if (canvas2.getContext) {
        var ctx2 = canvas2.getContext('2d');
        
        ctx2.fillStyle = fillColor;
        ctx2.strokeStyle = fillColor;

        ctx2.beginPath();
        ctx2.arc(50, 270, 250, 0, Math.PI * -0.5, true);
        ctx2.arc(50, 40, 20, Math.PI * 1.5, 1.5, true);
        ctx2.arc(50, 270, 210, Math.PI * -0.5, 0, false);
        ctx2.arc(280, 270, 20,  Math.PI * -1, Math.PI * -2, true);

        ctx2.moveTo(50, 20);
        ctx2.stroke();
        ctx2.fill('evenodd');
    }
}
    
function draw3(fillColor) {
    var canvas3 = document.getElementById('WiFi_Bar3');
    if (canvas3.getContext) {
        var ctx3 = canvas3.getContext('2d');
        
        ctx3.fillStyle = fillColor;
        ctx3.strokeStyle = fillColor;

        ctx3.beginPath();
        ctx3.arc(50, 370, 350, 0, Math.PI * -0.5, true);
        ctx3.arc(50, 40, 20, Math.PI * 1.5, 1.5, true);
        ctx3.arc(50, 370, 310, Math.PI * -0.5, 0, false);
        ctx3.arc(380, 370, 20,  Math.PI * -1, Math.PI * -2, true);

        ctx3.moveTo(50, 20);
        ctx3.stroke();
        ctx3.fill('evenodd');
    }
}

$(function ($) {
    draw1('white');
    draw2('white');
    draw3('white');
});

$('img.fish').hover(function() {
  var pos = 0;
  var id = setInterval(frame, 5);
  function frame() {
    if (pos == 350) {
      clearInterval(id);
    } else {
      pos++; 
      elem.style.top = pos + 'px'; 
      elem.style.left = pos + 'px'; 
    }
  }
});

function changeColor(id) {
    var c=document.getElementById("myCanvas");
var ctx=c.getContext("2d");
var img=document.getElementById("scream");
ctx.drawImage(img,0,0);
var imgData=ctx.getImageData(0,0,c.width,c.height);
// invert colors
for (var i=0;i<imgData.data.length;i+=4)
  {
  imgData.data[i]=255-imgData.data[i];
  imgData.data[i+1]=255-imgData.data[i+1];
  imgData.data[i+2]=255-imgData.data[i+2];
  imgData.data[i+3]=255;
  }
ctx.putImageData(imgData,0,0);
    
}

//ctx.arc(x, y, radius, startAngle, endAngle, anticlockwise);
//ctx.moveTo(170,190);