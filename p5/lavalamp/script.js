function lavaFunc(){
    window.lavaVar += 90;
    document.getElementsByClassName("lavaLamp")[0].style.filter = "hue-rotate("+window.lavaVar+"deg)";
    document.getElementsByClassName("lavaLamp")[0].style.animationName = "none";
    setTimeout(function(){
        document.getElementsByClassName("lavaLamp")[0].style.animationName = "";
        document.getElementsByClassName("lavaLamp")[0].style.animationPlayState = "running";
    }, 50);
}
window.lavaVar = 0;