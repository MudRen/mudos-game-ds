#include <ansi.h>
inherit NPC;

void create()
{
        set_name(WHT"灰鼬王"NOR,({"weasel king", "king" }) );
        set("long",@LONG
    接受了實驗污染而變種的大型生物，已經看不出牠原本是什麼生
物，只知道他現在看起來就是一隻肥大的鼬鼠而已！牠喜歡到處咬東
西回來巢穴中放著，看牠腳下好像壓著什麼？？

LONG
);
        set("title","領袖");
        set("race", "野獸");
        set("limbs", ({
                "頭部", "頸部", "胸口", "後心", "腰間", "腹部", "尖牙","尾巴",
        }) );
        set("age",100+random(19));
        set("level",15);
        set("int",20);
        set("gender","雄性");
        set("attitude","killer");
        set("verbs", ({ "bite","claw" }) );    
        setup();
        carry_object(__DIR__"obj/obj2");
}
