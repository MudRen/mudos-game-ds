#include <ansi.h>
inherit NPC;

void create()
{
  set_name("征東牯牛",({"east cow","cow"}) );
  set("long","發狂中的牯牛，雙眼血紅，一付隨時會衝過的樣子，今人望之生懼。\n");
  set("race", "beast");
  set("unit","頭");
	set("title",HIG"牯牛草原"NOR);
  set("age",6);
  set("level",20);
  set("con",query("level")*3/2);
  set("attitude", "aggressive");
  set("limbs", ({ "頭部", "腹部","胸部","背部" }) );
  set("verbs", ({ "bite","claw" }) );
  set("chat_chance",30);
  set("chat_msg", ({
(: random_move :),
}) );

  setup();
  set_living_name("cow_war");
  carry_object(__DIR__"obj/meat");

}
