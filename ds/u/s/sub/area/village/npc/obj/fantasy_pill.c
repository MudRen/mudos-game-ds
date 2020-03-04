#include <ansi.h>
inherit ITEM;
inherit F_PILL;
void create()
{
        set_name("夢幻藥丸", ({ "fantasy pill","fantasy","pill"}));
        set("long",@LONG
這是一種還沒上市的禁藥，能讓傷者的傷口迅速復原。
LONG);
        set_weight(2);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "顆");
                set("eat_msg","$N吞下一顆夢幻藥丸。");
                set("eff_msg","你感到全身的傷口迅速的復原了。"  );
        }
        set("value",2000);
        set("cure",([
         "head" : 10,
         "body" : 10,
         "right_arm" : 10,
         "left_arm" : 10,
         "right_leg" : 10,
         "left_leg" : 10,
                ]));
        setup();
}
