#include <ansi.h>
inherit ITEM;
string check_ip(object ob, object *user);
void create()

{
        set_name(HIW"IP������[2003�~����]"NOR, ({"ip machine", "machine"}));
        set_weight(1000);
        set("unit", "��");
        set("long", @LONG����IP�Ϊ�
LONG);
        set("value", 99999);

        setup();
}


void init() 
{          
 add_action("do_checkip","cip");
}

int do_checkip(string arg)
{
        int i, num;
        string msg, result;
        object *user;

        user = users();

        for(i = 0;i < sizeof(user);i++)
                user[i]->set_temp("pending/ipcheck", 0);

        msg = HIG"\n�»a"HIC"��J�F���O�A�u��"HIW"IP������"HIC"�f���f�����n�I�I
"HIY"�����X�ӤF�A����"HIR"���G"HIY"�p�U�G\n\n"NOR;
        num = 0;
        for(i = 0;i < sizeof(user);i++) {
          if(user[i]->query_temp("pending/ipcheck") )     continue;
           reset_eval_cost();

                if( result = check_ip(user[i], user) ) {
msg += NOR + result + HIC"�ثe���q"HIR + query_ip_name(user[i]) + NOR"�s�u��"HIB"�ڤۤC��C\n"NOR;
                        num++;
                }
        }
        if(num == 0)    msg += HIR"\n�������G�^���G�S��"HIY"����IP"HIR"�b�u�W�C\n"NOR;

   if(num > 0)     msg += sprintf(HIY"\n�������G�^���G��"HIR"����IP"HIY"�åB"HIB"�ƶq"HIY"��"HIW"[ "HIM"%d ��"HIW" ] �C\n"NOR,num);
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

