#include <armor.h>
#include <ansi.h>
inherit FINGER;
void create()
{
        set_name(HIR"�y��"HIC"�٫�"NOR, ({ "ball ring", "ring"  }) );
        set("long",
                "�o�O�Q���ܶ±M�Ϊ��@��C\n");
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��" );
                set("armor_prop/armor",  5);
                set("armor_prop/shield",  5);
                set("armor_prop/hit",  100);
                set("armor_prop/dodge",  100);  
                set("limit_dex",4);
                set("value", 1800);
        }
        setup();
}


