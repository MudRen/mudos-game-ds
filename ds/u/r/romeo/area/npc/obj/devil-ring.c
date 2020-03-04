#include <armor.h>
#include <ansi.h>
inherit FINGER;
void create()
{
        set_name(HIB "魔星殘風戒" NOR,({ "devil-ring","ring" }) );
        set("long",
"這是一隻會發光的夜光戒，十分的好看。\n"
);
        set_weight(900);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",5);
        set("material", "leather");
        set("unit", "隻" );
        set("limit_con",25);
        set("limit_level",20);
        set("value",100);
        set("armor_prop/armor",1);
        set("armor_prop/dex", -1);
        set("armor_prop/int", -1);
        }
        set_temp("has_light",1);        //發光.
        setup();
}
