#include <ansi.h>
inherit NPC;
void create()
{
  set_name("城門守衛", ({ "gate guard","guard" }) );
  set("long","守衛磐龍城門口的人，平常負責檢查出入城門的商隊。\n");
  set("title",HIR"少帥軍"NOR);
  set("level",20);
  set("age",40);

   set("chat_chance", 3);
  set("chat_msg", ({
        (: command("say 歡迎光臨磐龍城，有空可以見見天下第一統帥「少帥冠仲」。") :),
        (: command("bow") :),
        }));
  set("chat_chance_combat", 14);
  set("chat_msg_combat", ({
        HIW"守衛說：反了反了，光天化日之下竟敢群眾打架\n"NOR,
        "守衛說：兄弟們，把他捕了\n"NOR
        }));
  set_skill("blade", 60);
  set_skill("parry", 70);
  set_skill("unarmed", 76);
  set_skill("dodge", 65);
  setup();
  add_money("coin",600);
  carry_object(__DIR__"wp/blade")->wield();
}


