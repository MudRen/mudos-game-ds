#include <ansi.h>

inherit ITEM;
void create()
{
    set_name("�P�B�q",({"Hkiori"}));
    setup();
}
void init()
{
    add_action("do_hsay","hsay");
} 
int do_hsay(string arg)
{ 
        object me = this_player();
        if( !arg || arg=="" ) return notify_fail("�A�n�g����S\n"); 
        {
        tell_object(users(),
        HIC"�i����j�P�B�q(Hkiori):"NOR" "+arg+"\n"NOR); 
        }
    return 1;
}

