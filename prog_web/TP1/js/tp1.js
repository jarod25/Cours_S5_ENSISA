const acButton = document.getElementById('btn-AC');
const cButton = document.getElementById('btn-C');
const pmButton = document.getElementById('btn-pm');
const percentButton = document.getElementById('btn-percent');
const addButton = document.getElementById('btn-add');
const subButton = document.getElementById('btn-sub');
const multButton = document.getElementById('btn-mult');
const pointButton = document.getElementById('btn-point');
const eqButton = document.getElementById('btn-eq');
const divButton = document.getElementById('btn-div');
let result = document.getElementById('display');
let initialSituation = true;
let currentNumber = null; 
let currentOperator = null; 
const buttons = {
    '0': 'btn-0',
    '1': 'btn-1',
    '2': 'btn-2',
    '3': 'btn-3',
    '4': 'btn-4',
    '5': 'btn-5',
    '6': 'btn-6',
    '7': 'btn-7',
    '8': 'btn-8',
    '9': 'btn-9',
};

function handleNumberClick(number) {
    if (initialSituation) {
        result.innerHTML = number;
        initialSituation = false;
    } else {
        result.innerHTML += number;
    }
}

Object.entries(buttons).forEach(([number, id]) => {
    document.getElementById(id).addEventListener('click', function() {handleNumberClick(number)});
});

pointButton.addEventListener('click', function() {
    if (result.innerHTML.indexOf('.') == -1) {
        result.innerHTML += '.';
        if (initialSituation) {
            result.innerHTML = '0.';
            initialSituation = false;
        }
    }
});

cButton.addEventListener('click', clearDisplay);

function clearDisplay() {
    result.innerHTML = '0';
    initialSituation = true;
}

function manageOperator(operator) {
    if (initialSituation) return;
    if (currentNumber === null) {
        currentNumber = parseFloat(result.innerHTML);
    } else if (!initialSituation) {
        compute();
    }
    currentOperator = operator;
    initialSituation = true;
}

function compute(operator) {
    if (currentOperator && currentNumber !== null) {
        const secondNumber = parseFloat(result.innerHTML);
        let computationResult;

        switch (currentOperator) {
            case '+':
                computationResult = currentNumber + secondNumber;
                break;
            case '-':
                computationResult = currentNumber - secondNumber;
                break;
            case '*':
                computationResult = currentNumber * secondNumber;
                break;
            case '/':
                computationResult = secondNumber !== 0 ? currentNumber / secondNumber : "Error, can't devide by 0";
                break;
            default:
                computationResult = secondNumber;
        }

        result.innerHTML = `<span class="text-muted small-text fade-in">${currentNumber} ${currentOperator} ${secondNumber}</span><br>${computationResult}`;
        
        currentNumber = computationResult; 
        currentOperator = null;
        initialSituation = true;
    }
    if (operator == '=') {
        currentNumber = null;
    }
}

addButton.addEventListener('click', () => manageOperator('+'));
subButton.addEventListener('click', () => manageOperator('-'));
multButton.addEventListener('click', () => manageOperator('*'));
divButton.addEventListener('click', () => manageOperator('/'));

eqButton.addEventListener('click', () => compute('='));

acButton.addEventListener('click', function () {
    currentNumber = null;
    currentOperator = null;
    clearDisplay();
});

document.addEventListener('keydown', function (event) {
    const key = event.key;

    if (buttons.hasOwnProperty(key)) {
        handleNumberClick(key);
    }

    if (key === '.') {
        pointButton.click();
    }

    if (key === '+') {
        manageOperator('+');
    } else if (key === '-') {
        manageOperator('-');
    } else if (key === '*') {
        manageOperator('*');
    } else if (key === '/') {
        manageOperator('/');
    }

    if (key === 'Enter' || key === '=') {
        compute('=');
    } else if (key === 'Backspace') {
        if (result.innerHTML.length > 1) {
            result.innerHTML = result.innerHTML.slice(0, -1);
        } else {
            clearDisplay();
        }
    } else if (key === 'Escape') {
        acButton.click();
    }
});
