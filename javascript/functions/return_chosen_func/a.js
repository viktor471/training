function get_func_number_with_prompt(){
    let answer = prompt("enter function name", _default="write_in_page");
    return  answer == "write_in_page" ?
            () => {
                let header = document.getElementById("header");
                let name = prompt("What is your name?", _default = "vitya")
                header.textContent = "Hello, " + name;
            }:
            answer == "prompt" ?
            () => {
                prompt("prompt function")
            }:
            // default function
            () => {
                prompt("default function");
            }
}

function main(){
    get_func_number_with_prompt()();
    print(get_func_number_with_prompt)
}
