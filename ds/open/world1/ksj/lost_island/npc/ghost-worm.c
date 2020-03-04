#include <ansi.h>
inherit NPC;

void create()
{
  set_name("鬼蟲", ({"ghost worm","worm"}) );
  set("long",@LONG
一隻小水桶大小的蟲，它專吃死去動物的屍骨，身上佈滿硬化的骨質
，看起來就像是一團白骨，尤其頭部簡直就是一個骷顱頭。
LONG);
  set("race", "beast");
  set("gender", "雄性");
  set("unit","隻");
  set("age",6);
  set("level",23+random(3));
  set("title",HIW"  奇獸 "NOR);
  set("limbs", ({ "頭部", "身體","背部" }) );
  set("verbs", ({ "bite"}) );
  set("combat_exp", 12000);
  add("addition_armor",30);
  set("chat_chance", 5);
  set("chat_msg", ({
     (: random_move :),
  }));
  setup();
}
