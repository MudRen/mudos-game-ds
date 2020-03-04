#include <ansi2.h>
inherit NPC;
void normal_ai();

mapping *combat_action = ({
        ([  "action":       "$N�Q�X�@�D�p�M����y�A���a�}�ŭ��n��V$n",
                "attact_type":  "tec",
                "damage_type":  "�ٶ�",
        ]),
        ([  "action":       "$N�l�Ӥ@�}�B�r�A�A�H�j�P��y�N�L�ƾU�Q�B�����V$n",
                "attact_type":  "tec",
                "damage_type":  "������",
        ]),
        ([  "action":       "$N�Q�X�@�����Y�Ů�A�p�L�Ϊ����u�����V$n",
                "attact_type":  "bio",
                "damage_type":  "����",
        ]),
});

mapping query_action()
{
  return combat_action[random(sizeof(combat_action))];
}

void create()
{
  set_name(GRN"�K���j�D"RED"�D"HIG"��"NOR,({"orochi green head","green head","head","_GREEN_HEAD_"}) );
  set("long",@LONG
�K�Y�K���A���j���ߦ��p�K�y�s�p�P�K�Ӥs���@�몺���Ƥj�D���W��
���B�̡A������K�y�s���B�s���A�����w�ۨ���C�A�{�b�Ҭݨ쪺��
���O�K���j�D���K���Y���@�A�I����B�����D���C
LONG
);
    set("attack_merits","tec");
        set("race","beast");
  set("unit","��");
  set("age",2000);
  set("attitude", "aggressive");
  set("evil",200);
  set("level",70);
  set("orochi",1);
  set("orochi_beast_3",1);
  set("limbs", ({ "�B��","�|��","����","�Y��"}) ); 
  set("verbs", ({ "bite","crash"}) );     
  set("str",160);
  set("con",143);
  set("int",60);
  set("dex",90);
  set("Merits/bar",9);
  set("Merits/bio",12);
  set("Merits/wit",4);
  set("Merits/tec",13);
  set("Merits/sou",4);
  add("addition_damage",70);
  add("addition_armor",220);
  add("addition_shield",50);
  set_temp("apply/hit",40);
  set("chat_chance", 30);
  set("chat_msg",({
     (: normal_ai() :),
     (: random_move :),
  }) );
  setup();
  set("default_actions", (: call_other, __FILE__, "query_action" :));
  set("actions", (: call_other, __FILE__, "query_action" :));
  set_living_name("_NPC_GREEN_HEAD_");
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
  object ob;
  if(!me) return 0;
  if(me->is_busy()) return 0;
  ob=find_living("_NPC_TORNADO_");
  if( objectp(ob) )
  {
    if(!environment(ob) )
    {
      destruct(ob);
    }
  }
  else
  {
    me->start_busy(2);
    message_vision("\n$N"HIW"�����V�ѡA�b�D���P��v���Φ��@��"HIG"�ۭ�"HIW"�I\n"NOR,me);
    new(__DIR__"mini-tornado")->move(environment(me));
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
    new(__DIR__"obj/obj/green-head")->move(this_object());
new(__DIR__"eq/orochi-leggings")->move(this_object());
  tell_object(ob,HIG"�A�o�� 10 �I�n��C"NOR);

  message("world:world1:vision",
  	HIC"\n\t�i�F��q�j�G"+HIR" �X���s���ǨӾ_�ձ�Ť���G�z�A"HIY+ob->name(1)
  	 +HIR"�٤U�F"+name()+HIR"�����ŤF�C\n\n"NOR,users());
  
	if(random(1000)==978)
		new(__DIR__"eq/orochi-leggings-save")->move(this_object());
  ::die();
  return;
}
