#include <ansi.h> 
inherit NPC;    

mapping *combat_action = ({
        ([  "action":       "$N���_�ШF���t�A�p�ɫB�����V$n",
                "attact_type":  "tec",
                "damage_type":  "������",
        ]),
});

mapping query_action()
{
  return combat_action[random(sizeof(combat_action))];
}

void create()
{
  set_name(HIG"�p������"NOR, ({"mini tornado","tornado"}) );
  set("long","�K���j�D���O�ҧΦ������ɡC\n");
  set("unit","��");
  set("level",30); 
    set("attack_merits","tec");
  set("orochi",1);
  set("orochi_beast_3",1);
  set("age",0);
  set("limbs", ({"�֤�"}) ); 
  set("verbs", ({"crash"}) );  
  set("max_hp",6000);
  set("chat_chance", 7);
  set("chat_msg", ({
     (: random_move :),
     }));
  set("chat_chance_combat", 7 );
  set("chat_msg_combat", ({
     (: random_move :),
     }) );
  setup(); 
  set_living_name("_NPC_TORNADO_");
  set("default_actions", (: call_other, __FILE__, "query_action" :));
  set("actions", (: call_other, __FILE__, "query_action" :));
  call_out("dest_tornado", 60);
}

void init()
{
  ::init();
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if( this_player()->query_temp("invis")>2 ) return;
  if(userp(this_player()) ) this_object()->kill_ob(this_player());
  if( this_player()->query("orochi-enemy") ) this_object()->kill_ob(this_player());
}

int special_attack(object me,object target,int hitchance)
{
  object *inv;
  int i,damage;
  inv = all_inventory(environment(me));
  if(!me || !inv) return 0;
  if( me->query_temp("delay") ) return 0;
  message_vision("\n$N"HIW"���ճv���W�j�A�j�j�����ճy�����F���ۡI\n"NOR,me);
  for(i=0;i<sizeof(inv);i++)
  {
    if(inv[i] == me) continue;
    if( inv[i]->is_corpse() ) continue;
    if( inv[i]->query("orochi") ) continue;
    if( inv[i]->query_temp("invis")>2 ) continue;
    if(living(inv[i]) )
    {
      if( random(inv[i]->query_dex()) <5 )
      {
        message_vision("$N"HIR"�Q�g���j�o������}�I\n"NOR,inv[i]);
        inv[i]->start_busy(1);
      }
    }
    if( !random(6) )
    {
      damage=400-(inv[i]->query_armor());
      if(damage<0) damage=0;
      damage=damage/5;
      message_vision("$N"HIR"�Q���_���F�������F����I("+damage+")\n"NOR,inv[i]);
      inv[i]->receive_damage("hp", damage, me);
    }
    me->set_temp("delay",1);
    me->start_busy(5);
    call_out("wait",5,me);
  }
  return 1; 
}    

void wait(object me)
{
  me->delete_temp("delay");
}

void dest_tornado()
{
  message_vision(HIW"\n\t�i�p�����ɭ��լ�M�[�j�A�Φ��j�P���ɡj\n\n"NOR,this_object());
  new(__DIR__"large-tornado")->move(environment(this_object()));
  destruct(this_object());
}

void die()
{
  message_vision("\n$N�����c�˸ѡA�����L�ܡC\n",this_object());
  destruct(this_object());
//  ::die();
  return;
}

