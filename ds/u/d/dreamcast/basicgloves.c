#include <armor.h>
#include <ansi.h>
inherit HANDS;
void create()
{
        set_name(BLU"魂"RED"昊"HIW"手""套"NOR ,({ "Dreamcast gloves","gloves" }) );
        set("long","這是昊天魂凝聚在一起所成的手套\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(800);
        set("material", "skin");
        set("unit", "個" );
       set("value",1000);
               set("armor_prop/armor", 3);
        set("limit_dex",6);
        set("armor_prop/str", 2);
        set("armor_prop/con", -1);
        }
        setup();
}

