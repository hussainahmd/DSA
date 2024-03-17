import java.util.Scanner

fun main() {
    infixToPostfix()
}

fun infixToPostfix() {
    print("\nEnter an Infix expression : ")
    val input = Scanner(System.`in`)
    val str = input.nextLine()
    var postfix: String = ""

    if(!isValid(str)){
        println("\nError! Invalid expression\n")
        return
    }
    val stack = Stack<Char>()

    for(ch in str){
        if (ch == ' ')
            continue

        else if (isOpBracket(ch))
            stack.push(ch)

        else if (isOperand(ch))
            postfix += ch

        else if (isOperator(ch))
        {
            if (stack.isEmpty())
                stack.push(ch);
            else
            {
                while (!stack.isEmpty() && priority(ch, stack.peek()))
                    postfix += stack.pop();
                stack.push(ch);
            }
        }
        else if (isCloBracket(ch)){
            when(ch){
                ')' -> {
                    while (!stack.isEmpty() && stack.peek() != '(')
                        postfix += stack.pop()
                }
                '}' -> {
                    while (!stack.isEmpty() && stack.peek() != '{')
                        postfix += stack.pop()
                }
                ']' -> {
                    while (!stack.isEmpty() && stack.peek() != '[')
                        postfix += stack.pop()
                }
            }
            stack.pop(); // rem opBracket from stack
        }
    }
    while (!stack.isEmpty())
        postfix += stack.pop();

    print("\nPostfix expression : $postfix\n\n");
}

fun isValid(str: String): Boolean {
    val stack = Stack<Char>()
    for (ch in str) {
        if(isOpBracket(ch))
            stack.push(ch)

        else if(isCloBracket(ch)){
            if(stack.isEmpty())
                return false
            else{
                when(ch){
                    ')' -> {
                        if(stack.pop() != '(')
                            return false
                    }
                    '}' -> {
                        if (stack.pop() != '{')
                            return false;
                    }
                    ']' -> {
                        if (stack.pop() != '[')
                            return false;
                    }
                }
            }
        }
        else if (isOperand(ch) || isOperator(ch))
            continue;

        else
            return false;
    }
    if (!stack.isEmpty())
        return false;

    return true
}

fun isOperand(ch: Char) = ch in 'A'..'Z' || ch in 'a'..'z' || ch in '0'..'9'

fun isOperator(ch: Char) = when (ch) {
    '+', '-', '*', '/', '%', '^' -> true
        
    else -> false
}

fun isOpBracket(ch: Char) = when (ch) {
    '(', '{', '[' -> true

    else -> false
}

fun isCloBracket(ch: Char) = when (ch) {
    ')', '}', ']' -> true

    else -> false
}

fun precedence(ch: Char) = when(ch) {
    '^' -> 3

    '*', '/', '%' -> 2

    '+', '-' -> 1

    else -> -1
}

fun priority(ch: Char, stackTop: Char) = when {
    isOpBracket(stackTop) || precedence(ch) > precedence(stackTop) -> false; // push

    precedence(ch) <= precedence(stackTop) -> true; // check for next ch on stackTop

    else -> false
}

/* ******************************************************************************************* */

class Stack<T>(){

    private val items = mutableListOf<T>()

    fun isEmpty(): Boolean = if(items.isEmpty()) true else false

    fun size() = items.size

    fun peek() = items[items.size - 1]

    fun push(item: T){
        items.add(item)
        //println("Item pushed : $item")
    }

    fun pop(): T? {
        if(items.isEmpty()){
            println("Pop error! Stack is empty")
            return null
        }
        val temp = items.removeAt(items.size - 1)
        //println("Item popped : $temp")
        return temp
    }

    fun display() {
        if(items.isEmpty()){
            println("Error! Stack is empty")
            return
        }
        print("Stack -> ")
        for(i in items){
            print("$i ")
        }
        println()
    }
}