#include <weapon.h>
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIY"�v�騦"NOR"�q����"NOR, ({ "sha-zin-gu passport","passport" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "�i");
                set("long", "�i�X�v�騦���q����"); 
                set("value", 100);                }
        setup();
}

