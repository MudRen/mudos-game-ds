#include <armor.h>
inherit NECK;
void create()
{
        set_name("超原力鍊", ({ "magic power necklace","necklace" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","這是一件由三千福特的電力交集而成的透明寶甲。\n");
                set("unit", "件");
                set("material", "gold");
                set("no_sell",1);
                set("no_sac",1);
                set("value",700);          
                set("wear_msg", "$N把全身的原力凝聚於脖子上, 好像形成了一條項鍊\n");
                set("unequip_msg", "$N的精神一個恍惚, $n突然消失了。\n");
           }
        set("armor_prop/dodge",2);
        set("armor_prop/armor",5);
        setup();
}


