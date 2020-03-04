#include <ansi2.h> 
inherit NPC;    

void create()
{
  set_name(HBK"�����]�y"NOR, ({"gravity ball","ball"}) );
  set("long","�K���j�D���O�Φ������O�y�A�W�j���ޤO�ϤH�ʧ@��w�C\n");
  set("unit","��");
  set("level",40); 
  set("orochi",1);
  set("age",0);
  set("limbs", ({"�y��"}) ); 
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
  message_vision("\n$N"HIW"�o�X�j�j�ޤO�A�y���������O�E�W�I\n"NOR,me);
  for(i=0;i<sizeof(inv);i++)
  {
    if(inv[i] == me) continue;
    if( inv[i]->is_corpse() ) continue;
    if( inv[i]->query("orochi") ) continue;
    if( inv[i]->query_temp("invis")>2 ) continue;
    if(living(inv[i]) )
    {
      message_vision("$N"HIR"�@�ɰʧ@��w�I\n"NOR,inv[i]);
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
  message_vision("\n$N�����b�b�šC\n",this_object());
//   destruct(this_object());
  ::die();
  return;
}
