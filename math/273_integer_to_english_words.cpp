unordered_map<int, string> numberMap = {
    {0, "Zero"},
    {1, "One"},
    {2, "Two"},
    {3, "Three"},
    {4, "Four"},
    {5, "Five"},
    {6, "Six"},
    {7, "Seven"},
    {8, "Eight"},
    {9, "Nine"},
    {10, "Ten"},
    {11, "Eleven"},
    {12, "Twelve"},
    {13, "Thirteen"},
    {14, "Fourteen"},
    {15, "Fifteen"},
    {16, "Sixteen"},
    {17, "Seventeen"},
    {18, "Eighteen"},
    {19, "Nineteen"},
    {20, "Twenty"},
    {30, "Thirty"},
    {40, "Forty"},
    {50, "Fifty"},
    {60, "Sixty"},
    {70, "Seventy"},
    {80, "Eighty"},
    {90, "Ninety"}};

class Solution
{
public:
    string rtrim(string s)
    {
        s.erase(s.find_last_not_of(' ') + 1);
        return s;
    }

    string convertNumberLessThan1000(int num, bool zero)
    {
        if (num == 0)
        {
            if (zero)
            {
                return numberMap[num];
            }
            else
            {
                return "";
            }
        }
        // less than or equal to 20
        if (num <= 20)
        {
            return numberMap[num];
        }
        // 20 < num < 100
        if (num < 100)
        {
            int ones = num % 10;
            int tens = num - ones;
            if (ones != 0)
            {
                return numberMap[tens] + " " + numberMap[ones];
            }
            else
            {
                return numberMap[tens];
            }
        }
        // num >= 100
        int ones = num % 10;
        int tens = num / 10 % 10;
        int hundreds = num / 100;
        if (num % 100 == 0)
        {
            return numberMap[hundreds] + " Hundred";
        }
        if (tens * 10 + ones <= 20)
        {
            return numberMap[hundreds] + " " + "Hundred" + " " + numberMap[tens * 10 + ones];
        }
        else
        {
            if (ones == 0)
            {
                return numberMap[hundreds] + " " + "Hundred" + " " + numberMap[tens * 10];
            }
            else
            {
                return numberMap[hundreds] + " " + "Hundred" + " " + numberMap[tens * 10] + " " + numberMap[ones];
            }
        }
    }

    string numberToWords(int num)
    {
        if (num < 1000)
        {
            return convertNumberLessThan1000(num, true);
        }
        else if (num < 1000000)
        {
            int ones = num % 1000;
            int thousands = (num - ones) / 1000;
            return rtrim(convertNumberLessThan1000(thousands, false) + " " + "Thousand" + " " + convertNumberLessThan1000(ones, false));
        }
        else if (num < 1000000000)
        {
            int ones = num % 1000;
            num /= 1000;
            int thousands = num % 1000;
            num /= 1000;
            int millions = num % 1000;
            string millionInEnglish = convertNumberLessThan1000(millions, false);
            string thousandInEnglish = convertNumberLessThan1000(thousands, false);
            string onesInEnglish = convertNumberLessThan1000(ones, false);
            string result = millionInEnglish + " Million";
            cout << thousandInEnglish << endl;
            if (thousandInEnglish != "")
            {
                result += " " + thousandInEnglish + " Thousand";
            }
            if (onesInEnglish != "")
            {
                result += " " + onesInEnglish;
            }
            return result;
        }
        else
        {
            int ones = num % 1000;
            num /= 1000;
            int thousands = num % 1000;
            num /= 1000;
            int millions = num % 1000;
            num /= 1000;
            int billions = num % 1000;
            string billionInEnglish = convertNumberLessThan1000(billions, false);
            string millionInEnglish = convertNumberLessThan1000(millions, false);
            string thousandInEnglish = convertNumberLessThan1000(thousands, false);
            string onesInEnglish = convertNumberLessThan1000(ones, false);
            string result = billionInEnglish + " Billion";
            if (millionInEnglish != "")
            {
                result += " " + millionInEnglish + " Million";
            }
            if (thousandInEnglish != "")
            {
                result += " " + thousandInEnglish + " Thousand";
            }
            if (onesInEnglish != "")
            {
                result += " " + onesInEnglish;
            }
            return result;
        }
    }
};