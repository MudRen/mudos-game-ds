#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"修羅"NOR,({"capricorn"}));
        set("long",
                "    你眼前這個身穿山羊座黃金聖衣的人就是十二宮中對雅典\n"
                "娜最忠心的聖鬥士!他的手刀跟聖劍攻擊可開天殺地，你得要小心\n"
        );
        set("level",50);
        set("str",  65+random(10));
        set("combat_exp",50000);
        set("age",26);
        set("chat_chance",2);
        set("chat_msg",({
  (: command("say 天下無雙的聖劍．．你要試試嗎??") :),
  (: command("say 聖鬥士中沒有人比我對雅典娜忠心") :),
}));
        set("chat_chance_combat",100);
        set("chat_msg_combat",({
                                (:command("exert bagi_fist"):),
  HIW"修羅說：不知所謂，嘗嘗聖劍的厲害吧！！！\n"NOR,
}));
        set("class","fighter");
        set("class1","軍人");
        set("title",HIY"山羊座黃金聖鬥士"NOR);
        set_skill("unarmed",95);
        set_skill("dodge", 100);
        set_skill("parry", 75);
        set_skill("bagi_fist", 70);
        set_skill("combat",100);
        map_skill("unarmed","bagi_fist");
        setup();
        carry_object(__DIR__"eq/capricorn")->wear();
}
