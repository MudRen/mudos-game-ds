#include <ansi.h>

inherit ITEM;
void create()
{
    set_name("�s������",({"nsnwot"}));
    setup();
}
void init()
{
    add_action("do_nsnwotsay","nsnwotsay");
} 
int do_nsnwotsay(string arg)
{ 
        object me = this_player();
        if( !arg || arg=="" ) return notify_fail("�A�n�g����S\n"); 
        {
        tell_object(users(),
        HIC"�i����j�s������(Nsnwot):"NOR" "+arg+"\n"NOR); 
        }
    return 1;
}

