#include <armor.h>
#include <ansi.h>
inherit WAIST;
void create()
{
        set_name( HIC "冰封腰帶" NOR ,({ "ice waist","waist" }) );
        set("long","這是可拉用來綁住褲管用的腰帶。\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(100);
        set("material", "gold");
        set("unit", "個" );
        set("value",1);
             }
        set("armor_prop/con",2);
        set("armor_prop/armor",6);
        set("armor_prop/shield",6);

        setup();
}

void init()
{
 if( environment(this_object()) == this_player() )
  this_player()->set_temp("has_light",1);
}


int query_autoload() { return 1; }

