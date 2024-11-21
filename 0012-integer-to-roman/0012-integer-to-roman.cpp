class Solution {
public:
    string intToRoman(int num) {
        string romanFormat;
        if(num >= 1000){
            int numOfMs = num / 1000;
            romanFormat.append(string(numOfMs,'M'));
            num %= 1000;

        }

        if(num >= 500){
            if(num >= 900){
                romanFormat.append("CM");
                num -= 900;
            }else{
                romanFormat.append("D");
                num -= 500;
            }
        }
        
        if(num >= 100){
            if(num >= 400){
                romanFormat.append("CD");
                num -= 400;
            }else{
                romanFormat.append(string(num / 100, 'C'));
                num %= 100;
            }
        }

        if(num >= 50){
            if(num >= 90){
                romanFormat.append("XC");
                num -= 90;
            }else{
                romanFormat.append("L");
                num -= 50;
            }
        }
        
        if(num >= 10){
            if(num >= 40){
                romanFormat.append("XL");
                num -= 40;
            }else{
                romanFormat.append(string(num / 10, 'X'));
                num %= 10;
            }
        }

        if(num >= 5){
            if(num >= 9){
                romanFormat.append("IX");
                num -= 9;
            }else{
                romanFormat.append("V");
                num -= 5;
            }
        }
        
        if(num >= 4){
            romanFormat.append("IV");
        }else{
            romanFormat.append(string(num, 'I'));
        }
        return romanFormat;
    }
};