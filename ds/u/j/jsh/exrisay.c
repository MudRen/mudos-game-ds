#include <ansi.h>

inherit ITEM;
void create()
{
    set_name("���I",({"exri"}));
    setup();
}
void init()
{
    add_action("do_exrisay","exrisay");
} 
int do_exrisay(string arg)
{ 
        object me = this_player();
        if( !arg || arg=="" ) return notify_fail("�A�n�g����S\n"); 
        {
        tell_object(users(),
        HIC"�i����j���I(Exri):"NOR" "+arg+"\n"NOR); 
        }
    return 1;
}

