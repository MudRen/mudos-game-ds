 inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIW"Force����"NOR, ({"force machine", "force"}));
        set_weight(1000);
        set("unit", "��");
        set("long", @LONG�@�ӶW�j�O���y
LONG);
        set("value", 99999);

        setup();
}


void init() 
{          
 add_action("do_force","fo");
}

int do_force(string arg)
{
object me, ob;
        string cmd;

        if( me != this_player(1) ) return 0;

        if( !arg || sscanf(arg, "%s to %s", cmd) != 2 )
                return notify_fail("���O�榡�Rforce <�Y�H> to <���O>\n");
                if( !living(ob) )
                return notify_fail("�o�Ӫ��󤣯����R�O�C\n");
                 if( userp(ob) )
                log_file("FORCE_PLAYER", sprintf("[%s] %s forces %s to %s\n",  
                        ctime(time()), geteuid(me), geteuid(ob), cmd));
        message_vision("$N�j��$n�h��"+cmd+"�o�ӫ��O�C\n",me,ob);
        return ob->force_me(cmd);
}

int help(object me)
{
        write(@Help
���O�榡�Rforce <�Y�H> to <���O>

�j���Y�H���Y��, ���A���Ův���ť������谪, �ӥB�����O�b�P�@�өж��̡C
Help
        );

        return 1;
}


