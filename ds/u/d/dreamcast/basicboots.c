#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name(RED"��"BLU"��"HIR"�P"HIW"�u" NOR, ({ "Dreamcast boots", "boots" }) );
        set("long","�o���u�O�������Q�δc�]�P�K�@���E\n");
        set_weight(1800);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "leather" );
                set("unit", "��" );
                set("value" , 130);
                set("volume",3);
                set("armor_prop/armor", 4);
                set("armor_prop/shield", 5);
        }
        setup();
}

