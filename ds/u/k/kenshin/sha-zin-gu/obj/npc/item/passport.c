#include <weapon.h>
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIY"暇日谷"NOR"通行證"NOR, ({ "sha-zin-gu passport","passport" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "張");
                set("long", "進出暇日谷之通行證"); 
                set("value", 100);                }
        setup();
}

