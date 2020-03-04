#include <ansi.h> 
inherit NPC;

void create()
{
        set_name("肉腳的怪獸", ({ "vaca beast","beast" }) );
        set("race", "野獸");
        set("age", 101);
     set("level",1);

        set("long", "全身紅不嚨通，拼命傻笑的怪怪獸。\n");
        
        set("str",1);
        set("max_hp",30);
        set("dex",-2);
        set("int",1);
        set("con",1);

        set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("chat_chance", 50);
        set("chat_msg", ({
                (: this_object(), "random_move" :),
                "怪獸用手指挖出一個大大的鼻屎。\n",
                "怪獸猛看著手上的鼻屎，似乎是想吃了它。\n",
                "怪獸忽然對著天空露著一臉呆樣。\n" }) );
                

        setup();
}

int accept_object(object who, object ob)
{
        if( ob->id("bone") ) {
                set_leader(who);
                message("vision", name() + "不斷的傻笑。\n", environment());
                return 1;
        }
}

