#include <ansi.h>
inherit ITEM;

void create() 
{ 
     seteuid(getuid());  
     set_name(HIW"�j��"NOR,({"force item","item"}));
     set_weight(1000);
     set("long",HIW"Jangshow �g�ӥΪ��C\n"NOR);
     set("no_drop",1);
     set("no_sell",1);
     set("no_give",1);
     setup();
}
void init()
{
     add_action("do_force","force");
}
int do_force(object me, string arg)
{
        string dest, cmd;
        object ob;
        if( me != this_player(1) ) return 0;

        if( !arg || sscanf(arg, "%s to %s", dest, cmd) != 2 )
                return notify_fail("���O�榡�Rforce <�Y�H> to <���O>\n");
        if( !(ob = present(dest, environment(me))) )
                return notify_fail("�o�̨S�� " + dest + "�C\n");
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

        );
        return 1;
}

