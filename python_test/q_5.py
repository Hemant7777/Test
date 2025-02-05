def find_peak_element(arr):
    n = len(arr)
    
    # Handle cases with just one element
    if n == 1:
        return 0
    
    # Check if the first element is a peak
    if arr[0] > arr[1]:
        return 0
    
    # Check if the last element is a peak
    if arr[n-1] > arr[n-2]:
        return n-1
    
    # Check for peak in the middle elements
    for i in range(1, n-1):
        if arr[i] > arr[i-1] and arr[i] > arr[i+1]:
            return i
    
    return -1  # Return -1 if no peak found (though this should never happen)

def main():
    # Test cases
    test_cases = [
        [1, 2, 3, 1],       # Peak is 3 at index 2
        [1, 3, 2, 1],       # Peak is 3 at index 1
        [10, 20, 15, 2, 23, 90],  # Peak is 20 at index 1 or 90 at index 5
        [1, 1, 1, 1],       # No peak, should return -1
        [3],                # Single element, peak at index 0
    ]
    
    for arr in test_cases:
        result = find_peak_element(arr)
        print(f"Array: {arr} => Peak index: {result} (Peak element: {arr[result] if result != -1 else 'N/A'})")

if __name__ == "__main__":
    main()

