// dumpling.c
#include <ansi.h> 
inherit ITEM;
inherit F_PILL;

void create()
{
               set_name(HIC"廉價"HIW"療傷劑"NOR,({"medicine"}));
        set_weight(120);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "個");
             set("value",200);
                set("eat_msg",HIB"$N將$n一股腦全倒進嘴巴裡。"NOR);
                set("eff_msg",HIW"你的身體正在"HIY"快速回復"HIW"中！"NOR);
}
                 set("heal",([
                  "ap":100,
                  "hp":100,
                  "mp":100,
]));
}
