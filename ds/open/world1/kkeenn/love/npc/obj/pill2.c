#include <ansi.h>
inherit ITEM;
inherit F_PILL;

void create()
{
        set_name(HIM"絮丹"NOR, ({ "she ball","ball" }));
        set("long",
        "一顆擁有千年功\力的丹丸，具有十分神奇的療效，一套共有八顆，\n"
        "合稱【情城八神】。\n"
        );
        set_weight(500);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "顆");
                set("eat_msg","$N吃下一顆冰冷冷的藥丸。");
                set("eff_msg",HIG "你直覺得有股冷氣遊走在任督二脈之中，身上的傷口似乎也漸漸消失了。" NOR );
        }
        set("value", 3000);
        set("heal",([
                "ap": 500,                "hp": 450,
                "mp": 450,
        ]));
        setup();
}

