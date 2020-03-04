#include <ansi.h>
inherit NPC;
void normal_ai();
void do_combat_attack();

mapping *combat_action = ({
        ([  "action":       "$N��$n�Q�X�@�ο@�@������",
                "attact_type":  "bio",
                "damage_type":  "�G�k",
        ]),
});

mapping query_action()
{
  return combat_action[random(sizeof(combat_action))];
}

void create()
{
  set_name(GRN"�K���j�D"RED"�D"MAG"����"NOR,({"orochi purple head","purple head","head","_PURPLE_HEAD_"}) );
  set("long",@LONG
�K�Y�K���A���j���ߦ��p�K�y�s�p�P�K�Ӥs���@�몺���Ƥj�D���W��
���B�̡A������K�y�s���B�s���A�����w�ۨ���C�A�{�b�Ҭݨ쪺��
���O�K���j�D���K���Y���@�A���o�r�𪺵���D���C
LONG
);
  set("race", "���~");    
  set("unit","��");
  set("age",2000);
  set("attitude", "aggressive");
  set("evil",200);
  set("level",70);
  set("orochi",1);
  set("orochi_beast_3",1);
  set("limbs", ({ "�B��","�|��","����","�Y��"}) ); 
  set("verbs", ({ "bite","crash"}) );     
  set("Merits/bar",10);
  set("Merits/bio",14);
  set("Merits/wit",7);
  set("Merits/tec",3);
  set("Merits/sou",6);
  add("addition_damage",30);
  add("addition_armor",150);
  add("addition_shield",200);
  set_temp("apply/hit",20);
  set("chat_chance", 40);
  set("chat_msg",({
     (: normal_ai() :),
     (: random_move :),
  }) );
  set("chat_chance_combat",40);
  set("chat_msg_combat", ({
     (:do_combat_attack():),
     }) );
  setup();
  set("default_actions", (: call_other, __FILE__, "query_action" :));
  set("actions", (: call_other, __FILE__, "query_action" :));
  set_living_name("_NPC_PURPLE_HEAD_");
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

void normal_ai()
{
  object me,target;
  me = this_object();
  target = this_player();
  if(me->is_busy()) return;
  if( me->query("hp") + 1000 < me->query("max_hp") )
  {
    message_vision("\n$N"HIG"�Ⲵ�L���A�a�b�����ǥ𮧡I\n\n"NOR,me);
    me->receive_heal("hp",1000);
    me->start_busy(1);
  }
  switch( random(30) )
  {
    case  0: message_vision("$N�@�����j���D�����n�ۧA�@�D�D�D\n",me);
          break;
    case  1: message_vision("$N�R�X�@�D�p�p�T���𮧡C\n",me);
          break;
    case  2: message_vision("$N�@�����j�����������|�P�A�M���y���C\n",me);
          break;
  }
  return;
}

void do_combat_attack()
{
 object *inv,me;
 int i;
  me=this_object();
  inv = all_inventory(environment(me));
  if(!inv) return;
  if(!me) return;
  message_vision("\n�i$N"MAG"���o�X�r���ƦV�|�P�I�j\n"NOR,me);
  for(i=0;i<sizeof(inv);i++)
  {
    if(inv[i] == me) continue;
    if( inv[i]->is_corpse() ) continue;
    if( inv[i]->query("orochi") ) continue;
    if( inv[i]->query_temp("invis")>2 ) continue;
    if( living(inv[i]) && userp(inv[i]) )
    {
      message_vision("$N"HIR"�l�J�r����y��@�¡C\n"NOR,inv[i]);
      inv[i]->apply_condition("poison", inv[i]->query_condition("poison")+10);
    }
  }
  return;
}

int special_attack(object me, object target, int hitchance)
{
  int i,dur,damage;
  object *inv,weapon;
  inv = all_inventory(environment(me));
  if(!me || !target) return 0;
  if(me->is_busy()) return 0;
  if( !me->query_temp("weapon") )

  if(!random(4))
  {
    me->start_busy(1);
    damage = random(150)+300-(target->query_shield())-(target->query_armor()/2);
    if(damage < 0) damage=0;
    message_vision("\n$N"HIW"��M��$n�R�X�i"MAG"�k���j��"HIW"�j�I�I\n"
                  +HIR"�y��("+damage+")�I���G�k\n"NOR,me,target);
    target->receive_damage("hp", damage, me);
    target->add_busy(1);
    if( me->query_temp("weapon") )
    {
      weapon=target->query_temp("weapon");      
      dur=weapon->query_durable();
      tell_object(target,HIW"�j�Īg��A�Ү���"+weapon->query("name")+"�y���@�Ƿ��l�C\n"NOR);
      weapon->set_durable(dur-random(18));
    }
    return 1;
  }
  else if(!random(4))
  {
    me->start_busy(1);
    message_vision("\n$N"HIW"��M�ªŤ��Q�X�j�q�i"MAG"�k���j��"HIW"�j�I�I\n\n"NOR,me);
    for(i=0;i<sizeof(inv);i++)
    {
      if(inv[i] == me) continue;
      if( inv[i]->is_corpse() ) continue;
      if( inv[i]->query("orochi") ) continue;
      if(living(inv[i]) )
      {
        if( random(inv[i]->query_dex()) < 20 )
        {
          message_vision("$N"HIR"�{�����ΡA�Q�ĲG�g���F����I\n"NOR,inv[i]);
          new(__DIR__"eq/orochi-acid")->move(inv[i]);
        }
      }
    }
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
  ob->add("popularity",10);      
    new(__DIR__"obj/obj/purple-head")->move(this_object());
new(__DIR__"eq/orochi-cloak")->move(this_object());
  tell_object(ob,HIG"�A�o�� 10 �I�n��C"NOR);

  message("world:world1:vision",
	HIC"\n\t�i�F��q�j�G"+HIR" �X���s���ǨӾ_�ձ�Ť���G�z�A"HIY+ob->name(1)
  	 +HIR"�٤U�F"+name()+HIR"�����ŤF�C\n\n"NOR,users());
  

	if(random(1000)==978)
          new(__DIR__"eq/orochi-cloak-save")->move(this_object());
  ::die();
  return;
}
