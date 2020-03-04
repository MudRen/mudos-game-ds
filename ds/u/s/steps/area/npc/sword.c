#include <ansi.h>
inherit NPC;
inherit SELLMAN;
void create()
{
        set_name(CYN"幻劍"NOR, ({ "sword" }) );
        set("gender", "男性" );
        set("level",15);
        set("age", 15);
        set("long",
                "他是蛋糕店的太子，有時候會來蛋糕店幫忙\n"
        );
        set("chat_chance", 4);
        set("chat_msg", ({
                "幻劍向天大喊：我要努力！我要加油！\n",
                "幻劍喃喃自說：我們這家蛋糕店一定會發揚光大！\n",
                "幻劍滿面笑容的說：這位客人，我們的都是鮮製蛋糕，請問有什麼需要嗎？\n",
        }));
        set("sell_list",([      
                 __DIR__"cake/mangocake"        : 20, 
                 __DIR__"cake/chocolatecake"        : 25, 
                 __DIR__"cake/berrycake"        : 23, 
        ]));
            setup();
}
void init()
{
        add_action("do_list","list");
        add_action("do_buy","buy");
}
