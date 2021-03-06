#include <ansi2.h> 
inherit NPC;    

void create()
{
  set_name(HBK"異界魔球"NOR, ({"gravity ball","ball"}) );
  set("long","八岐大蛇邪力形成的重力球，超強的引力使人動作遲緩。\n");
  set("unit","團");
  set("level",40); 
  set("orochi",1);
  set("age",0);
  set("limbs", ({"球身"}) ); 
  set("verbs", ({"crash"}) );     
  set("max_hp",3000);
  set_temp("float",1);
  setup();
  set_living_name("_NPC_GRAVITY_BALL_");
  call_out("dest_ball", 40);
}

void init()
{
  ::init();
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if(!this_object()->visible(this_player())) return; 
  if( userp(this_player()) ) this_object()->kill_ob(this_player());
  if( this_player()->query("orochi-enemy") ) this_object()->kill_ob(this_player());
}

int special_attack(object me,object target,int hitchance)
{
  object *inv;
  int i;
  inv = all_inventory(environment(me));
  if(!me || !inv) return 0;
  if( me->query_temp("delay") ) return 0;
  message_vision("\n$N"HIW"發出強大引力，造成局部重力激增！\n"NOR,me);
  for(i=0;i<sizeof(inv);i++)
  {
    if(inv[i] == me) continue;
    if( inv[i]->is_corpse() ) continue;
    if( inv[i]->query("orochi") ) continue;
    if( inv[i]->query_temp("invis")>2 ) continue;
    if(living(inv[i]) )
    {
      message_vision("$N"HIR"一時動作遲緩！\n"NOR,inv[i]);
        inv[i]->add_busy(3);
      me->set_temp("delay",1);
      me->start_busy(5);
      call_out("wait",5,me);
    }
  }
  return 1; 
}    

void wait(object me)
{
  me->delete_temp("delay");
}

void dest_ball()
{
  destruct(this_object());
}

void die()
{
  message_vision("\n$N消失在半空。\n",this_object());
//   destruct(this_object());
  ::die();
  return;
}
