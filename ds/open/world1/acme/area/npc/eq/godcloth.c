#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name(CYN"神武束身"NOR ,({ "god cloth","cloth" }) );
        set("long","神武教掌門人所穿戴的夜行服。\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(15000);
//              set("rigidity",10);
//              set("material", "iori");
                set("unit","件");
                set("value",6000);
                set("volume",2);
                set("armor_prop/armor", 20);
                set("armor_prop/dex", 1);
                set("limit_con",15);
        }
        setup();
}
