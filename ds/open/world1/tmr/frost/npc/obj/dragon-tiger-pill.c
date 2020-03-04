#include <ansi.h>
inherit ITEM;
inherit F_PILL;
void create()
{
        set_name( "通天龍虎丹", ({ "dragon-tiger pill","pill" }));
        set("long",@LONG
這是一粒由神真異獸龍虎身上取得的藥丸，傳說具有非常神奇的補血效果。
LONG
        );
        set_weight(500);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "顆");
                set("eat_msg","$N吞下一顆大如拳頭的藥丸，差點沒哽在喉嚨裡。");
                set("eff_msg",HIG "你覺得體內的血液不停地沸騰，似乎又有用不完的鮮血。" NOR );
        }
        set("value", 5000);
        set("heal",([
                "hp": 3000,
        ]));
        setup();
}

