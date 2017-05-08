function f(id) {
    $(id).toggleClass("control-animate control-hover");
    
    var darkCover = document.getElementById("darkCover");
    $(darkCover).toggleClass("noDarkCover darkCover");
    
    var idTop = id.offsetTop;
    var idLeft = id.offsetLeft;
    
    id.innerHTML = id.offsetTop + "_" + id.offsetLeft;

}