#include <weapon.h>
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("四彩令旗", ({ "flag", }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "這是十萬大山寨主用來號令各旗主的用品.");
                }
        setup();
}

