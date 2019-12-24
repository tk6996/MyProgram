var mouseOverHiddenAnswer = true;
var life = 3;
function randomOperator() {
    const operator = ['+', '-', 'x', '/', '%'];
    return operator[Math.floor(Math.random() * 5)];
}
function randomNumber1(operator) {
    let num;
    switch (operator) {
        case '+': case '-': case '/': case '%':
            num = Math.floor(Math.random() * 1000);
            break;
        case 'x':
            num = Math.floor(Math.random() * 100);
            break;
        default:
            break;
    }
    return num;
}
function randomNumber2(operator) {
    let num;
    switch (operator) {
        case '+': case '-':
            num = Math.floor(Math.random() * 1000);
            break;
        case 'x':
            num = Math.floor(Math.random() * 100);
            break;
        case '/': case '%':
            num = Math.ceil(Math.random() * 99);
            break;
        default:
            break;
    }
    return num;
}
function fillNumber() {
    if (document.getElementById("timeValue").innerHTML == 0) {
        if (life == 0) {
            life = 3;
            document.getElementById("scoreValue").innerHTML = "0000";
            document.getElementById('l3').style.visibility = "initial";
            document.getElementById('l2').style.visibility = "initial";
            document.getElementById('l1').style.visibility = "initial";

        }
        let op = randomOperator();
        document.getElementById("op").innerHTML = op;
        let num1 = String(randomNumber1(op)).padStart(4, '0');
        let number1list = ["n13", "n12", "n11", "n10"];
        for (let index = 0; index < number1list.length; index++) {
            document.getElementById(number1list[index]).innerHTML = num1.charAt(index);
        }
        let num2 = String(randomNumber2(op)).padStart(4, '0');
        let number2list = ["n23", "n22", "n21", "n20"];
        for (let index = 0; index < number2list.length; index++) {
            document.getElementById(number2list[index]).innerHTML = num2.charAt(index);
        }
        let number3list = ["n33", "n32", "n31", "n30"];
        for (let index = 0; index < number3list.length; index++) {
            document.getElementById(number3list[index]).innerHTML = '0';
        }
        document.getElementById('inputKeypad').innerHTML = '0000';
        document.getElementById("bthAns").disabled = false;
        mouseOverHiddenAnswer = true;
        document.getElementById("timeValue").innerHTML = 10;
        timer();
    }
}
function showAnswer() {
    ;
    let num1 = Number(document.getElementById("n13").innerHTML + document.getElementById("n12").innerHTML + document.getElementById("n11").innerHTML + document.getElementById("n10").innerHTML);
    let num2 = Number(document.getElementById("n23").innerHTML + document.getElementById("n22").innerHTML + document.getElementById("n21").innerHTML + document.getElementById("n20").innerHTML);
    let operator = document.getElementById("op").innerHTML;
    let answer = 0;
    switch (operator) {
        case '+':
            answer = num1 + num2;
            break;
        case '-':
            answer = num1 - num2;
            break;
        case 'x':
            answer = num1 * num2;
            break;
        case '/':
            answer = Math.floor(num1 / num2);
            break;
        case '%':
            answer = num1 % num2;
            break;
        default:
            break;
    }
    let number3list = ["n33", "n32", "n31", "n30"];
    let ans = "0000";
    if (answer < 0)
        ans = '-' + String(Math.abs(answer)).padStart(3, '0');
    else
        ans = String(answer).padStart(4, '0');
    for (let index = 0; index < number3list.length; index++) {
        document.getElementById(number3list[index]).innerHTML = ans.charAt(index);
    }
    return ans;
}
function hiddenAnswer() {
    if (mouseOverHiddenAnswer) {
        let number3list = ["n33", "n32", "n31", "n30"];
        let ans = "0000";
        for (let index = 0; index < number3list.length; index++) {
            document.getElementById(number3list[index]).innerHTML = ans.charAt(index);
        }
    }
}
function inputNumber(number) {
    document.getElementById("inputKeypad").innerHTML = document.getElementById("inputKeypad").innerHTML.slice(1, 4) + number;
}
function answer() {
    let answer = document.getElementById("inputKeypad").innerHTML;
    let trueAnswer = showAnswer();
    document.getElementById("bthAns").disabled = true;
    mouseOverHiddenAnswer = false;
    document.getElementById("timeValue").innerHTML = 0;
    if (answer == trueAnswer)
        document.getElementById("scoreValue").innerHTML = String(Number(document.getElementById("scoreValue").innerHTML) + 10).padStart(4, '0');
    else
        failed();
}
function timer() {
    let time = document.getElementById("timeValue").innerHTML - 1;
    if (time < 0)
        time = 0;
    document.getElementById("timeValue").innerHTML = time;
    if (time == 0) {
        if (!mouseOverHiddenAnswer)
            return;
        showAnswer();
        document.getElementById("bthAns").disabled = true;
        mouseOverHiddenAnswer = false;
        failed();
    }
    else {
        setTimeout(timer, 1000);
    }
}
function failed() {
    const heart = ["l1", "l2", "l3"];
    if (life > 0) {
        life--;
        document.getElementById(heart[life]).style.visibility = "hidden";
    }
}
window.onload = () => {
    document.getElementById("bthAns").disabled = true;
}
document.addEventListener("keypress", (e) => {

    if ("0123456789-".indexOf(e.key) >= 0)
        inputNumber(e.key);
    else if (e.key == "C" || e.key == "c")
        document.getElementById('inputKeypad').innerHTML = '0000';

})