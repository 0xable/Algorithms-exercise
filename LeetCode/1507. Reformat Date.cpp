// https://leetcode.com/problems/reformat-date/

class Solution {
public:
    // Dirty...
    // 0 ms
    // 6.2 MB
    string reformatDate(string date) {
        stringstream ss(date);
        string day, month, year;
        getline(ss, day, ' ');
        getline(ss, month, ' ');
        getline(ss, year, ' ');
        string result = year + "-" + getMonth(month) + "-";

        if (day.length() == 3) {
            result += "0" + day.substr(0, 1);
        } else {
            result += day.substr(0, 2);
        }
        return result;
    }

    string getMonth(string input) {
        map<string, string> monthTable;
        monthTable["Jan"] = "01";
        monthTable["Feb"] = "02";
        monthTable["Mar"] = "03";
        monthTable["Apr"] = "04";
        monthTable["May"] = "05";
        monthTable["Jun"] = "06";
        monthTable["Jul"] = "07";
        monthTable["Aug"] = "08";
        monthTable["Sep"] = "09";
        monthTable["Oct"] = "10";
        monthTable["Nov"] = "11";
        monthTable["Dec"] = "12";
        return monthTable[input];
    }
};