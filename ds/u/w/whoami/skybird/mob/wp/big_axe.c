#include <ansi.h>
#include <weapon.h>
inherit AXE;
void create()
{
        set_name("巨斧",({"big axe","axe"}));
        set("long","這是一把大型兵刃，力量要夠大才能使用得順手。\n");
        set_weight(13000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("volume",3);
        set("material","iron");
        set("unit", "把");
        set("value",6500);
        set("limit_str",60);
        }
        init_axe(60, TWO_HANDED);
        setup();
}

