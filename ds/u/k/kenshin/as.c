#include <ansi.h>

inherit ITEM;
void create()
{
    set_name("[0;1;33m�[1m�[1m�[1m�[1;36m�[1mo[1m�[1mn[1;37m�[1m�[0m",({"angel's say","say","angel"}));
    setup();
}
void init()
{
    add_action("do_cc","cc");
} 
int do_cc(string arg)
{ 
        object me = this_player();
        if( !arg || arg=="" ) return notify_fail("�A�n�g����S\n"); 
        {
        tell_object(users(),
        HIC"�i"HIY"�B��"HIR"���˴���"HIC"�j�Ū��p(Kenshin):"NOR" "+arg+"\n"NOR); 
        }
    return 1;
}
 int query_autoload() { return 1; }

