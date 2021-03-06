#include <ansi.h>
#include <combat.h>     
inherit NPC;

void create()
{
  set_name("浪人", ({"rounin"}));
  set("long",@long
四處流浪的武者，有的是流亡的武士，也有的是四處修藝的劍客，有
的浪人武藝甚至比正式道場的師範還強。
long);      
  set("gender", "男性" );
  set("age",37);
  set("level",37+random(5));
  set("race","human");
  set_skill("blade", 50+random(30));
  set_skill("parry", 40);
  set_skill("dodge", 50);
  set_skill("unarmed", 50);
  set("talk_reply","．．．．．\n");
  add("addition_armor",50);
  setup();
  carry_object(__DIR__"eq/raikiri-katana")->wield();
  add_money("coin",1000+random(500));
}

int special_attack(object me, object target, int hitchance)
{
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(7))
  {
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 4);
    COMBAT_D->report_statue(target);
    return 1;
  }

  if(target->query("level") > me->query("level")) return 0;
  if( (me->query("level")-target->query("level"))>0 && !random(5) )
  {
    message_vision(HIW"\n$N使出二階堂平法最高境界－"HIC"心之一方"HIW"，從眼神中散發強大的殺意\n"
                  +"，$n被殺意震攝突然全身無法動彈。\n\n"NOR, me, target);
    target->add_busy(3);
    return 1;
  }

  return 0;
}
