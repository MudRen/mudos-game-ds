#include <armor.h>
#include <ansi.h>
inherit WAIST;
void create()
{
        set_name(HIB"隴天"HIW"靈珠"NOR,({"sky pearl","pearl"}) );
        set("long","在隴天山上，吸收了七七四十九天的神力所打造的珠子。\n");
      set_weight(200);
        set("unit","顆");
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","顆");
                set("value",3000);
                set("material","silver");
                set("limit_lv", 15);
                set("limit_str", 30);
             }
                set("armor_prop/armor", 10);
                set("armor_prop/str", 2);
                set("armor_prop/int", 1);
                set("armor_prop/shield", 10);
                set("armor_prop/sou", 1);
                set("armor_prop/tec", -1);
        setup();
}

