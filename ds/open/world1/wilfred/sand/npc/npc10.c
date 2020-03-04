#include <ansi.h>
inherit NPC;

void create()
{
  set_name(RED"紅山豬"NOR, ({"red pig","pig"}) );
  set("long",@LONG
一種生長在山裡或乾旱地帶的野豬，生性相當機警，稍有風吹
草動便逃之夭夭，聽說此豬的肉呈鮮紅色，肉質鮮美，是為上
級料理的材料，因捕獲極為不易，身價跟著水漲船高。
LONG
);
  set("race", "beast");
  set("unit","隻");
  set("age",1);
  set("level",1);
  set("limbs", ({ "身體" }) );
  set("verbs", ({ "bite" }) );
  setup();
}

void init()
{
  object ob = this_object(), me = this_player();
  if(!ob->visible(me)) return;
  message_vision(HIR"$N"HIR"警覺到有人靠近，一溜煙的逃之無蹤了。\n"NOR,ob);
  destruct(ob);
}

