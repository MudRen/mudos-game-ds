// dumpling.c
#include <ansi.h> 
inherit ITEM;
inherit F_PILL;

void create()
{
           set_name("高級療傷劑",({"better medicine","medicine"}));
        set_weight(120);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "個");
                set("value",1000);
                set("eat_msg",HIB"$N將$n一股腦全倒進嘴巴裡。"NOR);
                set("eff_msg",HIW"你的身體正在"HIY"快速回復"HIW"中！"NOR);
}
                 set("heal",([
                  "ap":500,
                  "hp":500,
                  "mp":500,
]));
}
