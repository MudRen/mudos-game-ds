#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
        set_name(HIW"魔術師帽"NOR,({"mage hat","hat"}) );
        set("long",@long
魔術師所戴的帽子，蠻好看的。
long
);
        set_weight(5000);
  if ( clonep() )
    set_default_object(__FILE__);
else
{
                set("volume",3);
                set("unit", "頂");
                set("value",10000);
                set("limit_lv",50);
                set("armor_prop/int",5);
                set("armor_prop/armor",10);
                set("armor_prop/show_damage",1);
        }
        setup();
} 
int query_autoload() { return 1; }
