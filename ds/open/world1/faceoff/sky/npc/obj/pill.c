#include <weapon.h>
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("九轉回魂丹", ({ "pill" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "粒");
                set("value", 3000);
                set("long", "一種相當複雜的丹藥，不過據說有奇效，只要沒進棺材，都有效果！！");
                }
        setup();
}

