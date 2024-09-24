class Solution {
public:
string mods(string str1, string str2)
    { 
       while(str1.length() >= str2.length() && str1.substr(0, str2.length()) == str2)
       {
        str1 = str1.substr(str2.length(), str1.length() - str2.length());
       }
       return str1;
    }
    string gcdOfStrings(string str1, string str2) {
        if(str2 == "")
        return str1;
        else
        {
        string md = mods(str1, str2);
        if(md.length() < str2.length())
        return gcdOfStrings(str2, md);
        else
        return "";
        }
    }
    
};