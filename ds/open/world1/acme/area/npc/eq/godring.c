#include <armor.h>
#include <ansi.h>
inherit FINGER;
void create()
{
        set_name(CYN"神武焰戒"NOR ,({ "god ring","ring" }) );
        set("long","神武教掌門人所穿戴之紅如火戒指。\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(8000);
//              set("rigidity",10);
//              set("material", "iori");
                set("unit","件");
                set("value",10000);
                set("armor_prop/armor", 1);
                set("armor_prop/int", 1);
                set("limit_int",20);
        }
        setup();
}
