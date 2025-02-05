def reverse_string(s):
    return s[::-1]

def run_test_cases():
    test_cases = ["hello", "world", "Python", "12345", "abcde"]
    for test in test_cases:
        result = reverse_string(test)
        print(f"Input: '{test}', Reversed: '{result}'")

def get_valid_input():
    while True:
        user_input = input("Enter a string to reverse: ")
        if user_input.strip():  # Ensures the input is not empty
            result = reverse_string(user_input)
            print(f"Reversed: '{result}'")
            break
        else:
            print("Error: Please enter a non-empty string.")

def main():
    # Run test cases
    print("Running default test cases...\n")
    run_test_cases()

    # Ask for user input
    print("\nNow, let's reverse a string based on your input:")
    get_valid_input()

if __name__ == "__main__":
    main()

