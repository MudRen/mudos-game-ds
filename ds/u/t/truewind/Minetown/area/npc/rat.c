#include <ansi.h>
inherit NPC;

void create()
{
        set_name("輻射鼠",({"Radiated rat", "rat" }) );
        set("long",@LONG
一隻深綠色的巨大老鼠，身上有幾個破爛的傷口，因為受到地底
下污染的水源影響而變得粗暴而具有攻擊性。

LONG
);
        set("title","地底生物");
        set("race", "野獸");
        set("limbs", ({
                "頭部", "頸部", "胸口", "後心", "腰間", "腹部", "尖牙","尾巴",
        }) );
        set("age",3+random(3));
        set("level",5);
        set("int",3);
        set("attitude","killer");
        set("gender","雄性");
        set("verbs", ({ "bite","claw" }) );
        set("chat_chance", 9);
        set("chat_msg",({
                (:random_move :),
                (:random_move():),
        })      );
        setup();
}

