#include <armor.h>
#include <ansi.h>
inherit MASK;
void create()
{
        set_name(CYN"神武鐵面"NOR ,({ "god mask","mask" }) );
        set("long","神武教掌門人所穿戴的半月形面具。\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(10000);
//              set("rigidity",10);
                set("material", "iori");
                set("unit","面");
                set("value",4000);
                set("volume",1);
                set("armor_prop/armor", 10);
                set("limit_int",20);
        }
        setup();
}
