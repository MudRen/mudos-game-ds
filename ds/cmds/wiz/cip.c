#include <ansi.h>

inherit F_CLEAN_UP;

string check_ip(object ob, object *user);

int main(object me, string arg)
{
        int i, num;
        string msg, result;
        object *user;

        user = users();

        for(i = 0;i < sizeof(user);i++)
                user[i]->set_temp("pending/ipcheck", 0);

        msg = "\n�ˬd�b�u�W���aIP�G\n\n";
        num = 0;
        for(i = 0;i < sizeof(user);i++) {
          if(user[i]->query_temp("pending/ipcheck") )     continue;
           reset_eval_cost();

                if( result = check_ip(user[i], user) ) {
msg += HIW + result + NOR"�ثe���q"HIY + query_ip_name(user[i]) + NOR"�s�u���C\n";
                        num++;
                }
        }
        if(num == 0)    msg += "\n�ˬd���G�G�ثe�u�W���a�� IP �U���ۦP�C\n";

   if(num > 0)     msg += sprintf("\n�ˬd���G�G�� 2 ���a�ΥH�W�ۦP IP �ƶq%d �C\n",num);
        write(msg);
        return 1;
}

string check_ip(object ob, object *user)
{
        int i, find = 0;
        string result, ip, id;

        id = ob->query("id");
        ip = query_ip_name(ob);
        result = ob->query("name") + "(" + ob->query("id") + ")  ";
  for(i = 0;i < sizeof(user);i++) {
     if(user[i]->query("id") != id && query_ip_name(user[i]) == ip) {
     result += user[i]->query("name") + "(" + user[i]->query("id") + ")  ";
                        user[i]->set_temp("pending/ipcheck", 1);
                        if(id && user[i]->query("id") )
                                find++;
                }
        }

        if( find )      return result;

        return 0;
}

int help(object me)
{
        write(@HELP
���O�榡: checkip

�ˬd�u�W�ۦPIP�����a�C

HELP
        );
        return 1;
}
