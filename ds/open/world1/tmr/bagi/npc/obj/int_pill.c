#include <ansi.h>
inherit ITEM;
inherit F_PILL;

void create()
{
        set_name("長生悟心丹", ({ "long int pill","pill" }));
        set("long",
"一顆呈雞血紅的丹丸，入鼻略帶腥味。\n"
        );
        set_weight(220);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
        set("unit", "顆");
        set("value", 500);
                set("heal_ap",70+random(16));
        set("eat_msg","$N吃下一顆暗紅帶臭味的藥丸。");
        set("eff_msg",HIB "一股腥臭的味道在你嘴裡久久不散...\n" NOR );
        }
        setup();
}

