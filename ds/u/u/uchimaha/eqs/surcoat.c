#include <armor.h>
#include <ansi.h>
inherit SURCOAT;
void create()
{
        set_name(HIW"NIKY"HIC"披風"NOR ,({ " niky surcoat","surcoat" }) );
        set("long","這是烏漆嗎黑專用的護具。\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(850);
        set("material", "surcoat");
        set("unit", "件" );
        set("value",400);
        
          set("armor_prop/armor", 20);
          set("armor_prop/shield", 20);
          set("armor_prop/hit",  100);
          set("armor_prop/dodge",  100);
          set("value", 1800);
        }
        setup();
}
