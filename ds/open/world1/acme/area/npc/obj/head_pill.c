#include <ansi.h>
inherit ITEM;
inherit F_PILL;
void create()
{
        set_name("清心醒腦丹", ({ "head_pill"}));
        set("long",@LONG
這是一顆只有在清心藥鋪才買得到的丹，此丹呈三角狀。
LONG
        );
        set_weight(50);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
	        set("unit", "顆");
	        set("eat_msg","$N吃下一顆清心醒腦丹。");
	        set("eff_msg",HIG "你感到全身上下一陣清涼，精神登時振奮許\多。\n" NOR );
        }
        set("value",150);
        set("cure",([
         "head" : 10,
         ]));
        setup();
}
