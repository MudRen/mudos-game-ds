#include <armor.h>
inherit ARMOR;

void create()
{
        set_name("皮甲",({"leather armor","armor"}) );
        set("long","皮革韖製後製成，大小只剛好可以保護胸部，冒險者初期必備。\n");
        set_weight(1000);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","件");
                set("value",500);
                set("volume",3);
                set("armor_prop/armor",7);
        }
        setup();
}

