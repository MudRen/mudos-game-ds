#include <ansi.h>
#include <combat.h>
inherit NPC;

void create()
{
  set_name(HIR"火狼"NOR, ({"fire wolf","wolf"}) );
  set("long",@LONG
體型較一般成年的野狼大上一倍，全身披覆著如火燄般的毛皮，奔走
時就像是燎原於原野的一團火燄，喜好將獵物追逐至筋疲力盡，再啃
食其發燙硬實的血肉。
LONG);
  set("race", "beast");
  set("gender", "雄性");
  set("unit","隻");
  set("age",100);
  set("level",34+random(3));
  set("title",HIW"  奇獸 "NOR);
  set("limbs", ({ "頭部", "腹部","胸部","爪子","尾巴" }) );
  set("verbs", ({ "bite","claw" }) );
  set_skill("dodge", 80);
  set_skill("unarmed", 75);
  set("combat_exp", 33000);
  add("addition_damage",30);
  add("addition_armor",30);
  set("chat_chance", 40);
  set("chat_msg", ({
   HIR"火狼"NOR"身上火紅色的毛皮被風吹拂過，宛如熊熊燃燒的火燄。\n",
   HIR"火狼"NOR"發出一聲長嘯，瞬間便與你擦身而過，你好像聞到身上有焦臭味！\n",
     (: random_move :),
     }));
  setup();
}

void init()
{        
  ::init();
  switch( random(8) )
  {
    case 0:
         say(HIR"火狼"NOR"好像看到什麼似的，突然加速狂奔，火紅的身影消失在遠方。\n");
         destruct(this_object());
         break;
  }
} 

int special_attack(object me, object target, int hitchance)
{
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(8))
  {
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 4);
    COMBAT_D->report_statue(target);
    return 1;
  }
  return 0;
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
  switch( random(100) )
  {
    case  0..29: new(__DIR__"eq/fire-wolf-pants")->move(this_object());
          break;
    case  98..99: new(__DIR__"eq/fire-wolf-surcoat")->move(this_object());
          break;
  }
  ::die();
  return;
}
