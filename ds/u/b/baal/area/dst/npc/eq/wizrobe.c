#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name(HIW"白法師袍"NOR ,({ "wizard robe","robe" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
 set("long",@LONG
一件元素法師穿的袍子。(version1)
LONG
     );
                set("unit", "件");
        set("value",500);
                set("material", "silk");
                set("armor_prop/shield",30);
            set("armor_prop/wit",2);
                set("armor_prop/armor", 5);
        }
        setup();
}

