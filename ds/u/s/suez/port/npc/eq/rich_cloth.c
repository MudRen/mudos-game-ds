#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("華服",({"cloth"}) );
        set("long","十分華麗的衣服，用高級的材料製成。\n");
        set_weight(300);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","件");
                set("value",1500);
                set("volume",1);
                set("armor_prop/armor",1);
        }
        setup();
}



