#include <ansi.h>
inherit NPC;

void create()
{
  set_name("無臉妖怪",({"no-face bogle","bogle"}) );
  set("long",@LONG
臉上沒有五官，只有慘白一張臉的妖怪，會攻擊路人然後剝去臉皮貼
在自己的臉上。
LONG
);
  set("race","monster");
  set("unit","隻");
  set("age",64);
  set("attitude", "aggressive");
  set("level",27+random(4));
  set("limbs", ({ "頭部","身體","手部","腳部"}) ); 
  set("verbs", ({ "bite","claw" }) );     
  set("chat_chance", 10);
  set("chat_msg", ({
      "無臉妖怪的臉皮被風掀了開來，露出沒有五官的一張白臉。\n",
     }));                                
  setup();
  add_money("coin",500);
}

void init()
{
  ::init();
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if(!this_object()->visible(this_player())) return;
  if(this_player()->query("level") < 26 && userp(this_player()) )
     this_object()->kill_ob(this_player());
}

int special_attack(object me, object target, int hitchance)
{
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(4) && (target->query_dex() < 50) )
  {
    message_vision("\n$N丟出一張臉皮，不偏不倚黏在$n的臉上，$n一時間慌了手腳。\n\n", me, target);
    target->add_busy(2);
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
     case  0: 
           new(__DIR__"eq/hundred-bogle-necklace")->move(this_object());
           break;
     case  1..30: 
           new(__DIR__"eq/bogle-bead")->move(this_object());
           break;
  }
   ::die();
   return;
}
