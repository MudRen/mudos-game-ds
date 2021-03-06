#include <ansi.h>
inherit NPC;

void do_dest() 
{
         say(CYN"鐵甲蟲"NOR"突然轉身狂奔，消失在一個地洞中。\n");
         destruct(this_object());
}

void create()
{
  set_name(CYN"鐵甲蟲"NOR, ({"iron beetle","beetle"}) );
  set("long",@LONG
一隻巨大的甲蟲，翅翼已經退化而無法飛翔，鋼鐵般的甲殼上長了一
枝巨大的尖角，看起來很具威脅性，但牠其實是吃素的。
LONG
);
  set("race", "beast");
  set("gender", "雄性");
  set("unit","隻");
  set("age",10);
  set("level",26+random(2));
  set("title",HIW"  奇獸 "NOR);
  set("limbs", ({ "頭部", "身體","前肢","後肢","背部" }) );
  set("verbs", ({ "bite","crash" }) );
  set("combat_exp", 12000);
  add("addition_armor",70);
  set("chat_chance", 20);
  set("chat_msg", ({
     (: random_move :),
     (: random_move :),
     (: do_dest :),
     }));
  setup();
}

void die()
{
  object ob;
  if( !ob = query_temp("last_damage_from") )
    ob = this_player(1);
  if( !ob ) 
  {
    ::die();
    return;
  }
  if( random(100) < 10 ) {
        new(__DIR__"eq/iron-beetle-shield")->move(this_object());
  }

  ::die();
  return;
}

