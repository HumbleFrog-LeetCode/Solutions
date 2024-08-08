class Solution {
public:
    string numberToWords(int num) {
        static int numbers[] = {1000000000, 1000000, 1000, 100, 90, 80, 70, 60, 50, 40, 30, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        static string words[] = {"Billion", "Million", "Thousand", "Hundred", "Ninety", "Eighty", "Seventy", "Sixty", "Fifty", "Forty", "Thirty", "Twenty", "Nineteen", "Eighteen", "Seventeen", "Sixteen", "Fifteen", "Fourteen", "Thirteen", "Twelve", "Eleven", "Ten", "Nine", "Eight", "Seven", "Six", "Five", "Four", "Three", "Two", "One"};

        if(num == 0)
            return "Zero";

        static int n = sizeof(numbers)/sizeof(numbers[0]);    

        for(int i = 0; i<n; i++) {
            if(num >= numbers[i])
                return (num >= 100 ? numberToWords(num/numbers[i]) + " " : "")
                    + words[i]
                    + (num % numbers[i] ? " " + numberToWords(num % numbers[i]) : "");
        }
        return "";
    }
};
