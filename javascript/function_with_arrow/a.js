var prompt = require("prompt");
prompt.start();

let age = prompt("Сколько вам лет?", 18);

let welcome = (age < 18) ?
  () => alert("Привет") :
  () => alert("Здравйствуйте!");

welcome();
