#include <armor.h>
#include <ansi.h>
inherit FINGER;
void create()
{
        set_name(CYN"������"NOR ,({ "wind ring","ring" }) );
        set("long","�@�u�x���ť����]�O�٫��C\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(50);
        set("material", "shield");
        set("unit", "�u" );
        set("value",1000);
        set("armor_prop/dex", 100);
        }
        setup();
} 
