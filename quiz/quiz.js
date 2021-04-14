function sob(){
  if (this.style.backgroundColor != "rgba(66, 66, 196, 0.5)"){

    this.style.backgroundColor = "rgba(66, 66, 196, 0.274)";
  }
}
function sobOut(){
  if (this.style.backgroundColor != "rgba(66, 66, 196, 0.5)"){
    this.style.backgroundColor = "transparent";
  }
  
}
function selection(){
  let qualThis = this.innerHTML;
  this.style.backgroundColor = "rgba(66, 66, 196, 0.5)";
  for (let loopLi = 0; loopLi < quantidadeOpt; loopLi++){
    if (document.querySelectorAll(".opt li")[loopLi].innerHTML != qualThis){
      document.querySelectorAll(".opt li")[loopLi].style.backgroundColor = "transparent";
    }
  }
  
}
let set = {
  question: 'O que é C++?',
  0: 'Uma marca de roupa',
  1: 'Um software',
  2: 'Uma engine', 
  3: 'Uma linguagem de programação',
  c: 'Uma linguagem de programação',
}
let set0 = {
    question: 'Qual o maior Nome do setanejo?',
    0: 'Tiao Carreiro',
    1: 'Fiduma e Jeca',
    2: 'Diego e Arnaldo', 
    3: 'Leo e Raphael',
    c: 'Tiao Carreiro',
}
let set1 = {
  question: 'Quem é o Melhor mineiro que você conhece?',
  0: 'Daniel de oliveira',
  1: 'Caio do BBB',
  2: 'Fernandovb01', 
  3: 'Dilma Rousseff',
  c: 'Fernandovb01',
}
let listaSets = [set, set0, set1];
let pos = 0, points = 0;
function submit(){
  let verify = false;
  let opt = document.querySelectorAll(".opt li");
  let answer = 0;
  let correct = "";
  for (let whichAnswer = 0; whichAnswer < quantidadeOpt && verify == false; whichAnswer++){
    if (opt[whichAnswer].style.backgroundColor == "rgba(66, 66, 196, 0.5)"){
      answer = whichAnswer;
      correct = document.querySelectorAll(".opt li")[answer].innerHTML;
      verify = true;
    }
  }
  if (correct == listaSets[pos].c){
    points++;
    pos++;
  } else {
    pos++;
  }
  console.log(points);
  if (pos < listaSets.length){
    document.querySelector("h2").innerHTML = listaSets[pos].question;
    for (let attOpt = 0; attOpt < quantidadeOpt; attOpt++){
      document.querySelectorAll(".opt li")[attOpt].innerHTML = listaSets[pos][attOpt];
      }
    document.querySelectorAll(".opt li")[answer].style.backgroundColor = "transparent";
  } else {
    stop(points);
  }
  
}

function stop(points){
  console.log("parei");
  let corpo = document.querySelector(".corpo");
  let child1 = document.querySelector(".pergunta");
  let child2 = document.querySelector(".respostas");
  let child3 = document.querySelector(".submit");
  corpo.removeChild(child1);
  corpo.removeChild(child2);
  corpo.removeChild(child3);
  //----------------------------------------------------//
  let mensagem = document.createElement('h2');
  let divMensagem = document.createElement('div');
  divMensagem.setAttribute('class', 'pergunta')
  divMensagem.insertAdjacentElement('beforeend', mensagem);
  //-------------------------------------------------------//
  let divResposta = document.createElement('div');
  divResposta.setAttribute('class', 'respostas');
  let pont = document.createElement('p');
  pont.innerHTML = `A sua pontuação total foi de ${points}.`;
  divResposta.insertAdjacentElement('beforeend', pont);

  if (points <= Math.floor(listaSets.length / 2)){
    mensagem.innerHTML = "Você reprovou!";
  }
  else if (points == Math.floor(listaSets.length / 2) + 1){
   mensagem.innerHTML = "Você está na média."   
  } else {
     mensagem.innerHTML = "Parabéns você acertou todas!!!";
  }
  document.querySelector(".corpo").insertAdjacentElement('beforeend', divMensagem);
  document.querySelector(".corpo").insertAdjacentElement('beforeend', divResposta);
}

let quantidadeOpt = document.querySelectorAll(".opt li").length;
for (let loopOpt = 0; loopOpt < quantidadeOpt; loopOpt++){
  document.querySelectorAll(".opt li")[loopOpt].addEventListener('mouseover', sob);
  document.querySelectorAll(".opt li")[loopOpt].addEventListener('mouseout', sobOut);
  document.querySelectorAll(".opt li")[loopOpt].addEventListener('click', selection);
}
document.querySelector(".submit button").addEventListener('click', submit);