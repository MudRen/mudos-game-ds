#include <ansi.h>
inherit NPC;

void create()
{
  set_name(MAG"���L�j��"NOR, ({"huge spider","spider"}) );
  set("long",@LONG
�@�����j���j��A���F���j�����ϸ}�~�A�̥i�Ȫ��O���|ä�L�B�G
���Q�����j�L�A�O���i�Ȫ������̡C
LONG);
  set("race", "beast");
  set("gender", "����");
  set("unit","��");
  set("age",12);
  set("level",26+random(5));
  set("title",HIW"  �_�~ "NOR);
  set("limbs", ({ "�Y��", "����","�e��","���","�I��" }) );
  set("verbs", ({ "bite"}) );
  set("combat_exp", 12000);
  add("addition_armor",20);
  set("chat_chance", 40);
  set("chat_msg", ({
     (: random_move :),
     }));
  setup();
}

void init()
{        
  ::init();
  switch( random(10) )
  {
    case 0:
         say(MAG"���L�j��"NOR"�X�Ӹ��D�A�H�Y��������O���C\n");
         destruct(this_object());
         break;
  }
} 

int special_attack(object me, object target, int hitchance)
{
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(10))
  {
    message_vision(MAG"���L�j��"NOR"�i�}�j�L���V$n�A�r�X�@�ӥֶ}�׺쪺�ˤf�I"NOR, this_object(), target);
    target->recive_damage("hp",random(50)+30,me);
    target->apply_condition("blooding", target->query_condition("blooding")+(random(2)+1));
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
  switch( random(99) )
  {
    case  0..3: new(__DIR__"eq/purple-jade-ring")->move(this_object());
          break;
  }
  ::die();
  return;
}
