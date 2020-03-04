#include <ansi.h>
inherit ITEM;
void create()
{
     set_name(HIW"召喚玩具的盒子"NOR,({"toy box","box"})); 
     set("long","\n請先help box\n");
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
        write(HIW"你要召喚(catch)什麼？\n"NOR);
        add_action("do_catch","catch");
        return 1;
}
int do_catch(string str1)
{ 
        object toy;
        if(!str1)
        {
        message_vision(
        HIW"現有的玩具：\n\n"NOR
        HIY"1.氣勁劍\n\n"NOR
        HIG"Please use『catch with number』\n"NOR,this_player()
        );
        return 1;
        }
        if(str1 =="1")
        {
        message_vision(
        HIW"$N使出神奇魔法\n"NOR
        HIW"忽然一把氣勁劍就跑了出來。\n"NOR,this_player()
        );
        toy=new("/u/j/jangshow/sword");
        toy->move(this_player());
        return 1;
        }
        else
        {
        write(HIM"沒那個玩具唷....\n"NOR);
        }
        return 1;
}


