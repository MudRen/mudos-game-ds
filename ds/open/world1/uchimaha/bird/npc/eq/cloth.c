#include <armor.h>
#include <ansi.h>
inherit CLOTH;
 
void create()
{
set_name(HIC"羽衣"NOR,({"bird robe","robe"}) );
set("long","這是一件用羽毛製成的衣服, 雖然非常輕薄, 但是防禦力也不壞。\n");
set_weight(2500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
              set("material", "cloth");
              set("unit", "件");
              set("material", "silk");
              set("armor_prop/armor", 10);
              set("limit_dex",10);
              set("armor_prop/dex", 1);
        }
        setup();
}
