#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"阿波羅迪"NOR,({"pisces"}));
        set("long",
                "    你眼前這個身穿雙魚座黃金聖衣的人就是十二宮中最後一位黃金\n"
                "聖鬥士!他的玫瑰攻擊可說是舉世無雙，你要小心應付\n"
        );
        set("level",50);
        set("str",  65+random(10));
        set("combat_exp",50000);
        set("age",27);
         set("chat_chance",1);
        set("chat_msg",({
  (: command("say 想見教皇？先問過老子吧") :),
}));
        set("chat_chance_combat",100);
        set("chat_msg_combat",({
                                (:command("exert bagi_fist"):),
  HIW"阿波羅迪說：找死，敢找老子麻煩，不知死活\n"NOR,
}));
        set("class","fighter");
        set("class1","軍人");
        set("title",HIY"雙魚座黃金聖鬥士"NOR);
        set_skill("unarmed",90);
        set_skill("dodge", 100);
        set_skill("parry", 80);
        set_skill("bagi_fist", 70);
        set_skill("combat",100);
        map_skill("unarmed","bagi_fist");
        setup();
        carry_object(__DIR__"eq/pisces")->wear();
}
