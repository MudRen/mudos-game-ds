#include <ansi.h>
inherit ITEM;
void create()
{
     set_name(HIW"�l�ꪱ�㪺���l"NOR,({"toy box","box"})); 
     set("long","\n�Х�help box\n");
     set("no_sell",1);
     setup();
}
void init()
{
        add_action("do_help","help");
}
int do_help(string str)
{
        if(str != "box") return 0;
        write(HIW"�A�n�l��(catch)����H\n"NOR);
        add_action("do_catch","catch");
        return 1;
}
int do_catch(string str1)
{ 
        object toy;
        if(!str1)
        {
        message_vision(
        HIW"�{��������G\n\n"NOR
        HIY"1.��l�C\n\n"NOR
        HIG"Please use�ycatch with number�z\n"NOR,this_player()
        );
        return 1;
        }
        if(str1 =="1")
        {
        message_vision(
        HIW"$N�ϥX���_�]�k\n"NOR
        HIW"���M�@���l�C�N�]�F�X�ӡC\n"NOR,this_player()
        );
        toy=new("/u/j/jangshow/sword");
        toy->move(this_player());
        return 1;
        }
        else
        {
        write(HIM"�S���Ӫ����....\n"NOR);
        }
        return 1;
}


