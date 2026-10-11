print("""
    -------Welcome-------
    ---To--Calculator----
    ---available-marks---
    -- (+ / - *) or stop-
    ---------------------
    """)
while True:

    str_mark = input("Enter a mark : ").lower()

    match str_mark:
        case '+' | '-' | '*' | '/':
            number_one = float(input("Enter a number : "))
            number_two = float(input("Enter another number : "))

            match str_mark:
                case '+':
                    print(f"Result : {number_one + number_two}")
                case '-':
                    print(f"Result : {number_one - number_two}")
                case '*':
                    print(f"Result : {number_one * number_two}")
                case '/':
                    if number_two == 0:
                        print("Number cannot be divided by zero")
                    else:
                        result = number_one / number_two
                        print(f"Result : {result}")

        case 'help' | '?':
            print("Available marks : +, -, *, /")
            print("Type 'stop' to exit")

        case 'stop':
            print("Good bye!")
            break

        case _:
            print("Your mark is invalid")

