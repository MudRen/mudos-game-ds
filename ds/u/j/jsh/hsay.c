#include <ansi.h>

inherit ITEM;
void create()
{
    set_name("周伯通",({"Hkiori"}));
    setup();
}
void init()
{
    add_action("do_hsay","hsay");
} 
int do_hsay(string arg)
{ 
        object me = this_player();
        if( !arg || arg=="" ) return notify_fail("你要寫什麼﹖\n"); 
        {
        tell_object(users(),
        HIC"【閒聊】周伯通(Hkiori):"NOR" "+arg+"\n"NOR); 
        }
    return 1;
}

