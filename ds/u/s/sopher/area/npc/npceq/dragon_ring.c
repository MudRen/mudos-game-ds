#include <armor.h>
#include <ansi.h>
inherit FINGER;
void create()
{
        set_name(HIR"�s���٫�"NOR ,({ "dragon ring","ring" }) );
        set("long","�@�u�x�۬������]�O�٫��C\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(50);
        set("material", "shield");
        set("unit", "�u" );
        set("value",1000);
set("armor_prop/dex", 1);
        }
        setup();
} 
