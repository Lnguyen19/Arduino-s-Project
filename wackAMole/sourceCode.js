
document.getElementById('start').onclick = function(){





const gettingAll = document.querySelectorAll(".space");

const molin = document.getElementById("moling");

const system = document.getElementById('mainGame');
let current;
let score = 0;
document.getElementById('score').textContent = score;
function clicked(){

console.log("yo clicked on the target");
}

function trying(within){

	within.classList.remove('mole');
}
function randomShits(){
 //gettingAll.forEach(Boxing=>{Boxing.classList.remove('molin')}) 
gettingAll.forEach(trying);

let position = gettingAll[Math.floor(Math.random() * 9)]
 position.classList.add('mole');
  current = position.id;

}

function makingIt(){
let time = null;
time = setInterval(randomShits,700);

}
function playSound(){
    new Audio('slap.mp3').play();
}

function makingItWork(parameter){

parameter.addEventListener('mousedown',()=>{
    if(parameter.id==current){
        score  = score+5;
        console.log('You clicked on this shit');

        document.getElementById('score').textContent = score;
        playSound();
    }
    else {
        score = score-5;
        document.getElementById('score').textContent = score;
    }

})


}

gettingAll.forEach(makingItWork);

makingIt();
}

