#include <ansi.h> 
inherit NPC;    

void create()
{
  set_name(HIR"八岐烈燄"NOR, ({"orochi fire","fire"}) );
  set("long","八岐大蛇所吐出的高熱火燄。\n");
  set("unit","團");
  set("level",40); 
  set("orochi",1);
  set("age",0);
  set("limbs", ({"球身"}) ); 
  set("verbs", ({"crash"}) );  
  set("max_hp",30000);
  set_temp("float",1);
  setup(); 
  call_out("dest_fire", 2+random(4));
}

void init()
{
  ::init();
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if(!this_object()->visible(this_player())) return; 
  if(userp(this_player()) ) this_object()->kill_ob(this_player());
  if( this_player()->query("orochi-enemy") ) this_object()->kill_ob(this_player());
}

int special_attack(object me,object target,int hitchance)
{
  int damage,dex_r,block_r,i;
  if(!me || !target) return 0;
  message_vision("\n$N"HIW"疾速朝$n的方向飛過去！\n"NOR,me,target);
  damage = random(100)+300-(target->query_shield())-(target->query_armor()/2);
  if(damage < 0) damage=0;
  dex_r=random(target->query_dex());
  block_r=random(target->query_skill("block"));
  if( dex_r > 50 )
  {
    message_vision(HIG"$N險險閃過八岐烈燄的攻擊。\n"NOR,target);
  }
  else if( block_r > 70 && target->query_temp("armor/shield") )
  {
    message_vision(HIG"$N及時以盾牌硬是擋住八岐烈燄的衝擊。\n"NOR,target);
  }
  else
  {
    message_vision(HIR"$N被八岐烈燄正面擊中，造成 ("+damage+") 點的內傷及灼傷！\n"NOR,target);
    target->receive_damage("hp", damage, me);
    COMBAT_D->report_status(target);
    destruct(me);
  }
  return 1; 
}    

void dest_fire()
{
  destruct(this_object());
}

void die()
{
  message_vision("\n$N消散無蹤。\n",this_object());
  destruct(this_object());
  ::die();
  return;
}
