#include <ansi.h>
inherit NPC;

void create()
{
  set_name("皇麟", ({"kilin horse","horse"}) );
  set("long",@LONG
一隻鳥頭馬身的奇獸，背上的鬃毛長到快要蓋住整個身體，身體的上
半部長了一些鱗片，性情溫和。
LONG
);
  set("race", "beast");
  set("gender", "雄性");
  set("unit","隻");
  set("age",10);
  set("level",26+random(2));
  set("title",HIW"  奇獸 "NOR);
  set("limbs", ({ "頭部", "身體","前腳","後腳","頸部" }) );
  set("verbs", ({ "poke","crash" }) );
  set("combat_exp", 12000);
  add("addition_armor",5);
  set("chat_chance", 20);
  set("chat_msg", ({
     (: random_move :),
  }));
  setup();
}

void init()
{        
  ::init();
  switch( random(10) )
  {
    case 0:
         say("皇麟衝進樹叢中，失去了蹤影。\n");
         destruct(this_object());
         break;
  }
} 
