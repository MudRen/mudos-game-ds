// eval.c
//
// Modified by Kenny@Broken.History (3/3/1997)

inherit F_DBASE;
inherit F_CLEAN_UP;

string doith(string arg);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        string file, filename, err;
        mixed  ret;
        //      int    cost;

        if (!arg) return notify_fail("���O�榡�Reval <LPC �R�O>\n");

        file = me->query("id");
        filename = "/u/"+file[0..0]+"/"+file+"/";
        if (get_dir(filename) == 0)
                return notify_fail("�A�S���p�H�u�@�ؿ��M����ϥΦ����O�T\n");
        filename += ("eval."+file+".c");
        file = @EndText
// This file is made by the "eval" command.
 
#include <socket_err.h>
#include <ansi2.h>
#include <command.h>
#include <function.h>
#include <localtime.h>
//#include <nature.h>
#include <origin.h>
//#include <quest.h>
#include <room.h>
//#include <stats.h>
#include <type.h>
#include <user.h>
 
inherit F_CLEAN_UP;
 
void eval(string euid)
{
        int cost;

        cost = eval_cost();
EndText
        + doith(replace_string(arg, "\n", "")) + ";\n"+ @EndText
        cost -= eval_cost();
cost -= 3;
printf("\nEval cost: %d\n", cost);
}
EndText;
        if (ret=find_object(filename)) destruct(ret);
        write_file(filename, file, 1);

        //        log_file("static/EVAL", sprintf("[%s] %s eval %s\n",
        //                ctime(time()), geteuid(me), arg));

        //      cost = eval_cost();
        err = catch(call_other(filename, "eval", this_player(1)->query("id")));
        //      cost -= eval_cost();
        if (!err)
        {
                write("���榨�\\�C\n");
                //              write(sprintf("������O�ơR%d\n���榨�\\�C\n", cost));
                rm(filename);
                if (ret=find_object(filename)) destruct(ret);
                /*
                                if (wizardp(me)) {
                                   CHANNEL_D->do_channel( me, ",",
                                        sprintf("�ϥ�[eval]���O - %s�C",arg));
                                }
                */
        }
        else write("���楢�ѡT\n");
        return 1;
}


string doith(string arg) {
        int i;    // pointer to string within array containing an exploded bit 
        int j;    // pointer to character within a given string
        int cnt;  // current count of (+1) ('s and (-1) )'s
        int poq;  // (waiting on) parethesisisis or quote; dual state
        string *inp = explode(arg, ";");

        for (i=0; i<sizeof(inp); i++) {
                for (j=0; j<strlen(inp[i]); j++) {
                        if(!poq && inp[i][j] == ')') cnt --;
                        if(!poq && inp[i][j] == '(') cnt ++;
                        if(inp[i][j] == '\\' && inp[i][j+1] == '"') j+=2;
                        if(inp[i][j] == '"') poq = (!poq);  // toggle poq state
                        if(strlen(inp[i])==j+1) {
                                if(sizeof(inp) == i+1) {
                                        if (cnt>0)
                                                write("!!!!!! �A�h�g�F "+cnt+" �ӥ��A���u(�v !!!!!!\n");
                                        else if(cnt<0)
                                                write("!!!!!! �A�h�g�F "+(-cnt)+" �ӥk�A���u)�v!!!!!!\n");
                                        else if(poq)
                                                write("!!!!!! �r�ꤣ���`���� !!!!!!\n");
                                        // error or no error we return here at the end
                                        return "\t"+implode(inp, ";\n\t");
                                }
                                else if (poq || cnt)
                                        inp[i] = inp[i] + ";"+ inp[i+1], inp -= ({inp[i+1]});
                        }
                }
        }
}


int help(object me)
{
        write(@HELP
���O�榡�Reval <LPC �R�O>
 
������w�� LPC �R�O�C
 
�Ҧp�Reval this_player()->set( "test", ({"test_data"}) )
 
�������O�Rinfo�Bdata�Bsetqmark�Bcall�C
 
HELP
        );
        return 1;
}

