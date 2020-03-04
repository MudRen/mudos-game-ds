#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"教皇"NOR,({"gemini"}));
        set("long",
                "    這個人就是當今受人景仰的教皇\n"
                "相傳他是黃金聖鬥士其中一位!!\n"
        );
        set("level",60);
        set("str",  80+random(10));
        set("combat_exp",60000);
        set("age",30);
        set("chat_chance",3);
        set("chat_msg",({
  (: command("say 想不到你能來到這地") :),
  (: command("say 真是不可思意!!") :),
  (: command("say 你準備受死吧!!!") :),
}));
        set("chat_chance_combat",120);
        set("chat_msg_combat",({
                                (:command("exert bagi_fist"):),
  HIW"教皇說：嘿嘿！！又有人來找死！！\n"NOR,
  HIW"教皇說：嘿嘿！！叫人來等你收屍吧！！\n"NOR,
}));
        set("class","fighter");
        set("class1","軍人");
        set("title",HIY"聖域主人"NOR);
        set_skill("unarmed",100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("bagi_fist", 100);
        set_skill("combat",100);
        map_skill("unarmed","bagi_fist");
        setup();
        carry_object(__DIR__"eq/gemini")->wear();
}
