#include <ansi.h>
#include <combat.h>
inherit NPC;

void create()
{
  set_name(HIR"���T"NOR, ({"fire wolf","wolf"}) );
  set("long",@LONG
�髬���@�릨�~�����T�j�W�@���A�������еۦp���V�몺��֡A�b��
�ɴN���O�R���쳥���@�Τ��V�A�ߦn�N�y���l�v�ܵ��h�O�ɡA�A��
����o�S�w�ꪺ��סC
LONG);
  set("race", "beast");
  set("gender", "����");
  set("unit","��");
  set("age",100);
  set("level",34+random(3));
  set("title",HIW"  �_�~ "NOR);
  set("limbs", ({ "�Y��", "����","�ݳ�","���l","����" }) );
  set("verbs", ({ "bite","claw" }) );
  set_skill("dodge", 80);
  set_skill("unarmed", 75);
  set("combat_exp", 33000);
  add("addition_damage",30);
  add("addition_armor",30);
  set("chat_chance", 40);
  set("chat_msg", ({
   HIR"���T"NOR"���W�����⪺��ֳQ���j�عL�A�{�p�����U�N�����V�C\n",
   HIR"���T"NOR"�o�X�@�n���S�A�����K�P�A�����ӹL�A�A�n���D�쨭�W���J����I\n",
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
         say(HIR"���T"NOR"�n���ݨ줰������A��M�[�t�g�b�A���������v�����b����C\n");
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
