#include <armor.h>
inherit CLOTH;
void create()
{
        set_name("布衣",({"cloth"}) );
        set("long","常見的布衣，有各種樣式，但布衣就是布衣。\n");
        set_weight(300);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","件");
                set("value",100);
                set("volume",1);
                set("armor_prop/armor",1);
        }
        setup();
}


