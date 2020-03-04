#include <ansi.h>
inherit NPC;

void create()
{
  set_name(WHT"銀狼"NOR, ({"silver wolf","wolf"}) );
  set("long",@LONG
這種狼在黃沙平原上十分少見，通常都是獨自行動，不像其
他狼有群居性，牠的毛皮十分漂亮，所以常遭到獵人追捕。
LONG
);
  set("race", "beast");
  set("unit","隻");
  set("age",10);
  set("level",20);
  set("limbs", ({ "頭部", "腹部","胸部","爪子","尾巴" }) );
  set("verbs", ({ "bite","claw" }) );
  setup();
  carry_object(__DIR__"eq/eq4")->wear();
}

void init()
{
  object ob = this_object(), me = this_player();
  if(this_player()->name(1) == "迷途旅人")
  {
    message_vision("$N紅著雙眼，開始慢慢接近$n .... \n",ob,me);
    message_vision(HIR"\n看來$N"HIR"想吃掉$n！！\n\n"NOR,ob,me);
    COMBAT_D->do_attack(ob,me,ob->query_temp("weapon"),random(3)+2);
    COMBAT_D->do_attack(ob,me,ob->query_temp("weapon"),random(3)+2);
  }
}
