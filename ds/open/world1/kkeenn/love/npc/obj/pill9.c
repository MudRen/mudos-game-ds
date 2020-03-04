#include <ansi.h>
inherit ITEM;
inherit F_PILL;
void create()
{
        set_name(HIC"【"HIW"情城八神丹"HIC"】"NOR, ({ "love god pill","pill" }));
        set("long",
        "情城池中的療傷至寶，是由情城池八位仙子手中的八顆神丹，十分\n"
        "珍貴，其療效可以恢復身體原來的狀況。\n"
        );
        set_weight(500);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "顆");
                set("eat_msg","$N吃下一顆香氣四溢的藥丸。");
                set("eff_msg",HIG "你直覺得有股暖氣遊走於全身穴道之中，身體的狀況也復原了。" NOR );
        }
        set("value", 10000);
        set("heal",([
                "ap": 2000,
                "hp": 2000,
                "mp": 2000,
        ]));
        set("cure",([
                "head": 100,
                "left_arm": 100,
                "right_hand": 100,
                "left_leg": 100,
                "right_arm": 100,
                "body": 100,
        ]));
        setup();
}
