let input = document.getElementById("display");
const buttons = document.querySelectorAll(".symbols button");

const operators = ["+", "-", "*", "/", "."];
const mathExpressionRegex = /^[\d\.\s\+\-\*/\(\)]+$/;

buttons.forEach(button => {
    button.addEventListener("click", () => {
        const value = button.textContent;

        if (value === "C") {
            input.value = "";
        } else if (value === "DEL") {
            if (input.value === "Error") {
                input.value = "";
            } else {
                input.value = input.value.slice(0, -1);
            }
        } else if (value === "=") {
            if (input.value === "Error" || input.value.trim() === "") {
                return;
            }
            if (!mathExpressionRegex.test(input.value)) {
                input.value = "Error";
                return;
            }
            try {
                input.value = eval(input.value);
            } catch (error) {
                input.value = "Error";
            }
        } else {
            if (input.value === "Error") {
                input.value = "";
            }

            const lastChar = input.value.slice(-1);

            if (operators.includes(value) && operators.includes(lastChar)) {
                input.value = input.value.slice(0, -1) + value;
            } else {
                input.value += value;
            }
        }
    });
});