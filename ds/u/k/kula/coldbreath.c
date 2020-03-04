#include <armor.h>
#include <ansi.h>
inherit SURCOAT;
void create()
{
        set_name( HIW "寒氣" NOR ,({ "cold breath","breath" }) );
        set("long","這是一股低溫的寒氣。\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(800);
        set("material", "skin");
        set("unit", "件" );
        set("value",1);
        set("volume",4);
             }
        set("armor_prop/shield", 15);
        set("armor_prop/int",2);
        
        setup();
}

void init()
{
        if(!this_object()->query_light()) this_object()->start_light(1);
}

int query_autoload() { return 1; }

