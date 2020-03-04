#include <armor.h>
inherit BOOTS;
void create()
{
        set_name("虛無幻鞋", ({ "none boots","boots" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","一雙由空氣分子排成長鍊狀的可融性鞋子。\n");
                set("unit", "張");
                set("material", "sheet");
                set("no_sell",1);
                set("no_sac",1);
                set("value",1000);          
                set("wear_msg", "$N的腳上圍繞著幾許\弱風以直線方向流動。\n");
                set("unequip_msg", "$N腳四周的空氣停止流動了。\n");
           }
        set("armor_prop/dodge",7);
        set("armor_prop/armor",-4);
        setup();
}

