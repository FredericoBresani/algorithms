let intervalId = null;
function timer(){
    let horas = document.querySelector(".horas").value;
    let minutos = document.querySelector(".min").value;
    let segundos = document.querySelector(".sec").value;
    if (horas == ""){
        horas = "00";
        
    }
    if (minutos == ""){
        minutos = "00";
        
    }
    if (segundos == ""){
        segundos = "00";
        
    }
    horas = parseInt(horas);
    minutos = parseInt(minutos);
    segundos = parseInt(segundos);

    intervalId = setInterval(()=>{

        if (segundos == 0 && minutos == 0 && horas == 0){
            stop();
            window.alert("Alarme!!!");
        }
        else if (segundos < 0 || minutos < 00 || horas < 0){
            stop();
            window.alert("Acho que você digitou valores errados");
        } else {
            if (segundos == 0){
                if (minutos == 0){
                    horas--;
                    minutos = 59;
                    segundos
                } else {
                    minutos--;
                    segundos = 59;
                }
            } else {
                segundos--;
            }
            document.querySelectorAll(".s p")[1].innerHTML = ("00" + segundos).slice(-2);
            document.querySelectorAll(".m p")[1].innerHTML = ("00" + minutos).slice(-2);
            document.querySelectorAll(".h p")[1].innerHTML = ("00" + horas).slice(-2);
        }
        
    

    }, 100)
}
function stop(){
    if(intervalId){
        console.log("Entrei aqui");
        clearInterval(intervalId);
    }
}
function resetar(){
    stop();
    document.querySelectorAll(".s p")[1].innerHTML = "00";
    document.querySelectorAll(".m p")[1].innerHTML = "00"; 
    document.querySelectorAll(".h p")[1].innerHTML = "00";
    document.querySelector(".horas").value = "";
    document.querySelector(".min").value = "";
    document.querySelector(".sec").value = "";
}
document.querySelector(".start").addEventListener('click', timer);
document.querySelector(".reset").addEventListener('click', resetar)