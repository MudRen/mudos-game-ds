// dog.c
inherit NPC;

void create()
{
        set_name("鷹獸", ({ "eagle Monster","monster","eagle"}) );
        set("race", "野獸");
        set("age", random(10)+8);
        set("level",random(3)+3);
        set("long", "一隻生的有點像鷹但又肥大的像頭大象。\n");
        set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴","腹","翅膀","爪子"}) );
        set("verbs", ({ "bite", "claw" }) );
        set("chat_chance", 6);
        set("chat_msg", ({
                (: this_object(), "random_move" :),
                "鷹獸舞動著翅膀，一副想飛但右飛不起來的樣子。\n",
                "鷹獸嘆了口氣∼∼∼唉∼∼∼唉∼∼∼又搖了搖頭。\n",
                "鷹獸張牙舞爪露出了兇神惡煞的樣子。\n" }) );           
        setup();
}




