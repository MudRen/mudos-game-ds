//paper.c

#include <ansi.h>
inherit ITEM;

void create()
{

        set_name(HIW"�j�r��"NOR,({"big word paper","big","word","paper"}));
set("long","�Ϊk:trans xxx");
        setup();

}

void init()
{
        add_action("do_trans","trans");
}

string process1(string arg);
string process2(string arg);
string process3(string arg);
string process4(string arg);
string process5(string arg);
string process6(string arg);

int do_trans(string arg)
{
        int i;
        mapping str = ([]);
        object me;

        me = this_player();     
        if( sizeof(arg) > 8 ) arg = arg[0..7];

        for( i = 0; i < sizeof(arg); i++)
        {
                if(str["line1"] == 0) str["line1"] = process1(arg[i..i]);
                else str["line1"] += process1(arg[i..i]);
                if(str["line2"] == 0) str["line2"] = process2(arg[i..i]);
                else str["line2"] += process2(arg[i..i]);
                if(str["line3"] == 0) str["line3"] = process3(arg[i..i]);
                else str["line3"] += process3(arg[i..i]);
                if(str["line4"] == 0) str["line4"] = process4(arg[i..i]);
                else str["line4"] += process4(arg[i..i]);
                if(str["line5"] == 0) str["line5"] = process5(arg[i..i]);
                else str["line5"] += process5(arg[i..i]);
                if(str["line6"] == 0) str["line6"] = process6(arg[i..i]);
                else str["line6"] += process6(arg[i..i]);
        }
        write( str["line1"]+"\n"+str["line2"]+"\n"+str["line3"]+"\n"+str["line4"]+
                "\n"+str["line5"]+"\n"+str["line6"]+"\n");
        return 1;
}

string process1(string arg)
{

        switch(arg) {
                
                case "a" : 
                case "b" : 
                case "c" : 
                case "e" : 
                case "f" : 
                case "g" : 
                case "i" : 
                case "j" : 
                case "m" : 
                case "o" : 
                case "p" : 
                case "q" : 
                case "r" : 
                case "s" : 
                case "t" : 
                case "z" : 
                case "2" : 
                case "3" : 
                case "5" : 
                case "6" : 
                case "7" : 
                case "8" : 
                case "9" : 
                case "0" : 
                case "?" : 
                        return "�~�w�w�w��";
                case "d" : 
                case "1" : 
                        return "�~�w�w��  ";
                case "h" : 
                case "k" : 
                case "n" : 
                case "u" : 
                case "v" : 
                case "x" : 
                case "y" : 
                case "*" : 
                        return "�~��  �~��";
                case "l" :
                        return "�~��      ";
                case "w" : 
                        return "�~�����~��";
                case "4" :
                        return "�~���~��  ";
                case "!" :
                case "+" :
                case ":" :
                case ";" :
                        return "  �~�w��  ";
                case "-" :
                case "=" :
                case "," :
                case "~" :
                        return "          ";
                case "/" :
                        return "    �~��  ";
                case "^" :
                        return "   �~��   ";
                case "(" :
                case "{" :
                case "[" :
                case "<" :
                        return "�~�w��    ";
                case ")" :
                case "}" :
                case "]" :
                case ">" :
                        return "    �~�w��";
                default :
        }


return "";      
}

string process2(string arg)
{
        switch(arg) {
                
                case "a" :
                case "b" :
                case "c" :
                case "o" :
                case "p" :
                case "q" :
                case "r" :
                case "7" :
                case "?" :
                        return "�x�~�w���x";
                
                case "d" :
                        return "�x�~������";
                case "e" :
                case "f" :
                case "g" :
                case "s" :
                        return "�x�~�w�w��";
                case "h" :
                case "u" :
                case "v" :
                case "y" :
                        return "�x�x  �x�x";
                case "i" :
                case "j" :
                case "t" :
                        return "����  �~��";
                case "k" :
                        return "�x�x�~���x";
                case "l" :
                        return "�x�x      ";
                case "m" :
                        return "�x�~�����x";
                case "n" :
                        return "�x�����x�x";
                case "w" :
                        return "�x�x�x�x�x";
                case "x" :
                        return "�x���w���x";
                case "z" :
                case "2" :
                case "3" :
                        return "���w��  �x";
                case "1" :
                        return "����  �x  ";
                case "4" :                      
                        return "�x�x�x�x  ";
                case "5" :
                case "6" :
                        return "�x  �~�w��";
                case "8" :
                        return "�x  �~���x";
                case "9" :
                case "0" :
                        return "�x�~��  �x";
                case "!" :
                case "+" :
                case ":" :
                case ";" :
                        return "  �x  �x  ";
                case "-" :
                        return "          ";
                case "*" :
                        return "�����w����";
                case "/" :
                        return "    ����  ";
                case "=" :
                        return "�~�w�w�w��";
                case "," :
                        return "  �~�w��  ";
                case "~" :
                        return "�~��      ";
                case "^" :
                        return " �~������ ";
                case "(" :
                case "{" :
                case "[" :
                case "<" :
                        return "�x�~��    ";
                case ")" :
                case "}" :
                case "]" :
                case ">" :
                        return "    �����x";
                default :
        }       
        return "";
}

string process3(string arg)
{
        switch(arg) {
                case "a" :
                case "o" :
                case "q" :
                case "u" :
                case "v" :
                        return "�x�x  �x�x";
                case "b" :
                case "h" :
                case "p" :
                case "r" :
                case "y" :
                        return "�x���w���x";
                case "c" :
                        return "�x�x  ����";
                case "d" :
                        return "�x�x�����x";
                case "e" :
                case "f" :
                        return "�x���w��  ";
                case "g" :
                        return "�x�x�~�w��";
                case "i" :
                case "j" :
                case "t" :
                case "1" :
                case "!" :
                case "," :
                        return "  �x  �x  ";
                case "k" :
                        return "�x�����~��";
                case "l" :
                case "(" :
                case "{" :
                case "[" :
                case "<" :
                        return "�x�x      ";
                case "m" :
                case "w" :
                        return "�x�x�x�x�x";
                case "n" :
                case "8" :
                        return "�x  �����x";
                case "s" :
                case "~" :
                        return "�x���w�w��";
                case "x" :
                        return "����  �~��";
                case "z" :
                        return "  �~���~��";
                case "2" :
                case "3" :
                        return "�~�w��  �x";
                case "4" :
                        return "�x�x�x�x  ";
                case "5" :
                case "6" :
                        return "�x  ���w��";
                case "7" :
                case "?" :
                        return "�����~���x";
                case "9" :
                        return "�x����  �x";
                case "0" :
                        return "�x�x�x  �x";
                case "+" :
                        return "�~��  ����";
                case "-" :
                case "/" :
                        return "�~�w�w�w��";
                case "*" :
                        return "  ���~��  ";
                case "=" :
                        return "���w�w�w��";
                case ":" :
                case ";" :
                        return "  ���w��  ";
                case "^" :
                        return " �x�~���x ";
                case ")" :
                case "}" :
                case "]" :
                case ">" :
                        return "      �x�x";
                        
                default :
        }
        
        return "";      
}

string process4(string arg)
{
        switch(arg) {
                
                case "a" :
                case "v" :
                        return "�x���w���x";
                case "b" :
                case "h" :
                        return "�x�~�w���x";
                case "c" :
                case "l" :
                        return "�x�x  �~��";
                case "d" :
                case "q" :
                        return "�x�x�~���x";
                case "e" :
                case "f" :
                        return "�x�~�w��  ";
                case "g" :
                        return "�x�x�����x";
                case "i" :
                case "j" :
                case "t" :
                case "1" :
                        return "  �x  �x  ";
                case "k" :
                        return "�x�~������";
                case "m" :
                case "w" :
                        return "�x�x�x�x�x";
                case "n" :
                        return "�x�~��  �x";
                case "o" :
                case "u" :
                        return "�x�x  �x�x";
                case "p" :
                        return "�x�~�w�w��";
                case "r" :
                        return "�x�~���~��";
                case "s" :
                case "~" :
                        return "���w�w���x";
                case "x" :
                        return "�~��  ����";
                case "y" :
                case "+" :
                        return "����  �~��";            
                case "z" :
                        return "�~���~��  ";
                case "2" :
                        return "�x  �~�w��";
                case "3" :
                case "5" :
                case "9" :
                        return "���w��  �x";
                case "4" :
                        return "�x��������";
                case "6" :
                case "8" :
                        return "�x  �~���x";
                case "7" :
                        return "  �~���~��";
                case "0" :
                        return "�x�x�x  �x";
                case "!" :
                        return "  ���w��  ";
                case "?" :
                        return "    ���w��";
                case "-" :
                case "/" :
                        return "���w�w�w��";
                case "*" :
                        return "  �~����  ";
                case "=" :
                        return "�~�w�w�w��";
                case ";" :
                case ":" :
                        return "  �~�w��  ";
                case "," :
                        return "  �����x  ";
                case "^" :
                        return " �������� ";
                case "(" :
                case "{" :
                case "[" :
                case "<" :
                        return "�x�x      ";
                case ")" :
                case "}" :
                case "]" :
                case ">" :
                        return "      �x�x";
                default :
        }
        
        return "";      
}

string process5(string arg)
{
        switch(arg) {
        
                case "a" :
                case "x" :
                        return "�x�~�w���x";
                case "b" :
                case "c" :
                case "g" :
                case "l" :
                case "o" :
                case "u" :
                        return "�x���w���x";    
                case "d" :
                        return "�x�����~��";
                case "e" :
                        return "�x���w�w��";
                case "f" :
                case "p" :
                        return "�x�x      ";
                case "h" :
                        return "�x�x  �x�x";
                case "i" :
                case "1" :
                        return "�~��  ����";
                case "j" :
                case ";" :
                        return "�~��  �x  ";
                case "k" :
                case "n" :
                        return "�x�x�����x";
                case "m" :
                        return "�x�x�x�x�x";
                case "q" :
                        return "�x��������";
                case "r" :
                        return "�x�x�x����";
                case "s" :
                        return "�~�w�w���x";
                case "t" :
                case "y" :
                case "7" :
                case "+" :
                case ":" :
                        return "  �x  �x  ";
                case "v" :
                        return "����  �~��";
                case "w" :
                        return "�x�������x";
                case "z" :
                case "2" :
                        return "�x  ���w��";
                case "3" :
                case "5" :
                case "9" :
                        return "�~�w��  �x";
                case "4" :
                        return "���w���~��";
                case "6" :
                case "8" :
                        return "�x  �����x";
                case "0" :
                        return "�x����  �x";
                case "!" :
                case "?" :
                        return "  �~�w��  ";
                case "-" :
                case "^" :
                        return "          ";
                case "*" : 
                        return "�~�~�w����";
                case "/" :
                        return "  �~��    ";
                case "=" :
                        return "���w�w�w��";
                case "," :
                        return "  �~���x  ";
                case "~" :
                        return "      ���� ";
                case "(" :
                case "{" :
                case "[" :
                case "<" :
                        return "�x����    ";
                case ")" :
                case "}" :
                case "]" :
                case ">" :
                        return "    �~���x";


                
                default :
        }
        
        return "";      
}

string process6(string arg)
{
        switch(arg) {
                case "a" :
                case "h" :
                case "k" :
                case "n" :
                case "x" :
                case "*" :
                        return "����  ����";
                case "b" :
                case "c" :
                case "e" :
                case "g" :
                case "i" :
                case "l" :
                case "o" :
                case "s" :
                case "u" :
                case "w" :
                case "z" :
                case "1" :
                case "2" :
                case "3" :
                case "5" :
                case "6" :
                case "8" :
                case "9" :
                case "0" :
                        return "���w�w�w��";
                case "d" :
                case "j" :
                case ";" :
                        return "���w�w��  ";
                case "f" :
                case "p" :
                        return "����      ";
                case "m" :
                        return "����������";
                case "q" :
                        return "���w�w����";
                case "r" :
                        return "�������w��";
                case "t" :
                case "v" :
                case "y" :
                case "7" :
                case "!" :
                case "?" :
                case "+" :
                case ":" :
                case "," :
                        return "  ���w��  ";
                case "4" :
                        return "    ����  ";
                case "-" :
                case "=" :
                case "~" :
                case "^" :
                        return "          ";
                case "/" :
                        return "  ����    ";
                case "(" :
                case "{" :
                case "[" :
                case "<" :
                        return "���w��    ";
                case ")" :
                case "}" :
                case "]" :
                case ">" :
                        return "    ���w��";
                                
                default :
        }
        
        return "";      
}

