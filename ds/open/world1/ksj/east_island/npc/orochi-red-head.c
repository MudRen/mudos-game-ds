#include <ansi.h>
inherit NPC;
void normal_ai();
void do_combat_attack();

mapping *combat_action = ({
        ([  "action":       "$N�U�N�P�V�p�k�ۯ뼲�V$n�I",
                "attact_type":  "wit",
                "damage_type":  "�N����",
        ]),
        ([  "action":       "$N�i���Q���޿U�q�f���I�X���h��A�Φ���V�������W�N�V$n�I",
                "attact_type":  "wit",
                "damage_type":  "�N��",
        ]),
        ([  "action":       "$N�i�f�R�X�@�ɤj���y�N�V$n�I",
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
  set_name(GRN"�K���j�D"RED"�D"HIR"����"NOR,({"orochi red head","red head","head","_RED_HEAD_"}) );
  set("long",@LONG
�K�Y�K���A���j���ߦ��p�K�y�s�p�P�K�Ӥs���@�몺���Ƥj�D���W��
���B�̡A������K�y�s���B�s���A�����w�ۨ���C�A�{�b�Ҭݨ쪺��
���O�K���j�D���K���Y���@�A�f�R�P�V������D���C
LONG
);
  set("race", "beast");    
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
  set("Merits/bar",11);
  set("Merits/bio",11);
  set("Merits/wit",10);
  set("Merits/tec",3);
  set("Merits/sou",3);
  set_temp("apply/hit",40);
  add("addition_damage",100);
  add("addition_armor",200);
  set("chat_chance", 30);
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
  set_living_name("_NPC_RED_HEAD_");
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
  int i,damage;
  me=this_object();
  inv = all_inventory(environment(me));
  if(!inv) return;
  if(!me) return;
  message_vision("\n�i$N"HIR"���W��g�X�������ޡI�j\n"NOR,me);
  for(i=0;i<sizeof(inv);i++)
  {
    if(inv[i] == me) continue;
    if( inv[i]->is_corpse() ) continue;
    if( inv[i]->query("orochi") ) continue;
    if( inv[i]->query_temp("invis")>2 ) continue;
    if( living(inv[i]) && userp(inv[i]) )
    {
      damage=200+random(100)-inv[i]->query_shield();
      damage=damage/3;
      if(damage < 0)  continue;
      message_vision("$N"HIR"���H���סA�Q�P���Ҩ`�ˡC"HIR"("+damage+")\n"NOR,inv[i]);
      inv[i]->receive_damage("hp", damage, me);
    }
  }
  return;
}

int special_attack(object me, object target, int hitchance)
{
  int fire,j;
  fire=random(4)+2;
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(5)) 
  {
    me->start_busy(2);
    message_vision("\n$N"HIR"��M��դ@�w�A�q�f�R�X "+fire+" �ΤK���P�V�I\n"NOR,me);
    for(j=0;j<fire;j++)
    {
      new(__DIR__"orochi-fire")->move(environment(me));
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
    new(__DIR__"obj/obj/red-head")->move(this_object());
new(__DIR__"eq/orochi-gloves")->move(this_object());
  tell_object(ob,HIG"�A�o�� 10 �I�n��C"NOR);

  message("world:world1:vision",
  	HIC"\n\t�i�F��q�j�G"+HIR" �X���s���ǨӾ_�ձ�Ť���G�z�A"HIY+ob->name(1)
  	 +HIR"�٤U�F"+name()+HIR"�����ŤF�C\n\n"NOR,users());
  
  
  	if(random(1000)==978)
          new(__DIR__"eq/orochi-gloves-save")->move(this_object());
  ::die();
  return;
}

