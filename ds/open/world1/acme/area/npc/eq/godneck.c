#include <armor.h>
#include <ansi.h>
inherit NECK;
void create()
{
        set_name(CYN"神武守令"NOR ,({ "god neck","neck" }) );
        set("long","神武教教主所佩帶的護身符。\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(8000);
//              set("rigidity",10);
//              set("material", "iori");
                set("unit","個");
                set("value",10000);
                set("armor_prop/int", 1);
                set("armor_prop/armor", 1);
                set("limit_int",20);
                set("armor_prop/show_damage",1);
        }
        setup();
}
