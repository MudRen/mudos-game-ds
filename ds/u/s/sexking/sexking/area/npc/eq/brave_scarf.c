#include <armor.h>

inherit HEAD;

void create()
{
        set_name("勇者頭巾",({"brave scarf","scarf"}) );
        set("long","這是只有真正的勇士可綁的頭巾。\n");
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material","steel");
                set("unit", "條");
                set("value",1200);
                set("limit_lv",25);
                set("armor_prop/armor", 4);
                set("armor_prop/int",3);         
                set("armor_prop/dex",3);
        }
        setup();
}


