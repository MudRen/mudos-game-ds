#include <ansi.h>
inherit NPC;
void normal_ai();

mapping *combat_action = ({
        ([  "action":       "$N�q���⪺�������o�X�@�D���~�A�g�V$n��$l",
                "attact_type":  "wit",
                "damage_type":  "�N��",
        ]),
        ([  "action":       "$N�o���R�R�s�n�A�q���⪺�������E�g�X���~�A�������V$n��$l",
                "attact_type":  "wit",
                "damage_type":  "�N��",
        ]),
});

mapping query_action()
{
  return combat_action[random(sizeof(combat_action))];
}

void create()
{
  set_name(GRN"�K���j�D"RED"�D"HIY"����"NOR,({"orochi gold head","gold head","head","_GOLD_HEAD_"}) );
  set("long",@LONG
�K�Y�K���A���j���ߦ��p�K�y�s�p�P�K�Ӥs���@�몺���Ƥj�D���W��
���B�̡A������K�y�s���B�s���A�����w�ۨ���C�A�{�b�Ҭݨ쪺��
���O�K���j�D���K���Y���@�A���o����������D���C
LONG
);
        set("race","beast");
    set("attack_merits","wit");
  set("unit","��");
  set("age",2000);
  set("attitude", "aggressive");
  set("evil",200);
  set("level",70);
  set("orochi",1);
  set("orochi_beast_3",1);
  set("limbs", ({ "�B��","�|��","����","�Y��"}) ); 
  set("verbs", ({ "bite","crash"}) );     
  set("Merits/bar",9);
  set("Merits/bio",7);
  set("Merits/wit",14);
  set("Merits/tec",8);
  set("Merits/sou",7);
  add("addition_damage",90);
  add("addition_armor",250);
  add("addition_shield",200);
  set_temp("apply/hit",40);
  set("chat_chance", 30);
  set("chat_msg",({
     (: normal_ai() :),
     (: random_move :),
  }) );
  setup();
  set("default_actions", (: call_other, __FILE__, "query_action" :));
  set("actions", (: call_other, __FILE__, "query_action" :));
  set_living_name("_NPC_GOLD_HEAD_");
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

int special_attack(object me, object target, int hitchance)
{
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(4))
  {
    me->start_busy(1);
    target->add_busy(2);
    message_vision("\n$N"HIW"�ʧ@�y�w�A�q���j������D����g�X�j�P���i"HIY"�K������"HIW"�j�I�I\n"NOR,me);
    call_out("do_super",2,me);
    return 1;
  }
  return 0;
}

void do_super(object me)
{
  object *inv;
  int i, damage;
  inv = all_inventory(environment(me));
  if(!inv) return;
  if(!me) return;

  message_vision(HIY"\n���j�j�P��������W�A�V�|�P���g�I�I\n"NOR,me);
  for(i=0;i<sizeof(inv);i++)
  {
    if(inv[i] == me) continue;
    if(living(inv[i]) )
    {
      if( inv[i]->is_corpse() ) continue;
      if( inv[i]->query("orochi") ) continue;
      if( inv[i]->query_temp("invis")>2 ) continue;
      damage = random(300)+300-(inv[i]->query_shield());
      if(damage <0) damage=0;
      message_vision(HIR"$N�Q���W���������������ۤ��J��.... "HIR"("+damage+")\n"NOR,inv[i]);
      inv[i]->receive_damage("hp", damage, me);
      inv[i]->add_busy(1);
      COMBAT_D->report_status(inv[i]);
    }
    else
    {
      message_vision(HIR"\n$N�b�@�����N�����u .... \n\n"NOR,inv[i]);
      destruct(inv[i]);
    }
  }
  me->start_busy(2);
  return;
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
    new(__DIR__"obj/obj/gold-head")->move(this_object());
new(__DIR__"eq/kusanagi-sword")->move(this_object());
new(__DIR__"eq/orochi-armor2")->move(this_object());
  tell_object(ob,HIG"�A�o�� 10 �I�n��C"NOR);

  message("world:world1:vision",
  HIC"\n\t�i�F��q�j�G"+HIR" �X���s���ǨӾ_�ձ�Ť���G�z�A"HIY+ob->name(1)
  	 +HIR"�٤U�F"+name()+HIR"�����ŤF�C\n\n"NOR,users());
  
	if(random(1000)==978)
		new(__DIR__"eq/orochi-armor2-save")->move(this_object());
	
  ::die();
  return;
}
