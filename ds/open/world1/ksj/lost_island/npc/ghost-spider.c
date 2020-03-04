#include <ansi.h>
inherit NPC;

void create()
{
  set_name(HIW"�^"MAG"�I����"NOR, ({"ghost spider","spider"}) );
  set("long",@LONG
�@�����j���j��A���ۤ@���Ȥl���ڡA�e���I�W�e�{���W�h�����_�A
�P�ɦ��@�ӹ��O���y���զ⯾���A�Y�W�Ʊ����㪺�Ͳ��\�h�F�X����
���C
LONG);
  set("race", "beast");
  set("unit","��");
  set("age",80);
  set("attitude", "aggressive");
  set("gender", "����" );
  set("level",45+random(3));
  set("title",RED"  �]�~ "NOR);
  set("limbs", ({ "�Y��", "����","����","����","�I��" }) );
  set("verbs", ({"bite","claw"}) );
  setup();
        if(random(100)>95) // 5%
                carry_object(__DIR__"eq/treasure-paper1");
        if(random(100)>95) // 5%
                carry_object(__DIR__"eq/treasure-paper2");
        if(random(100)>95) // 5%
                carry_object(__DIR__"eq/treasure-paper3");

}

void init()
{
  ::init();
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if(!this_object()->visible(this_player())) return;
  if(userp(this_player()) )
    this_object()->kill_ob(this_player());
  if(!random(2) )
  {
    message_vision(HIW"\n�^"MAG"�I����"NOR"��ı�즳�ͪ��i�ӡA���t�a��$N�R�X�@�i���ε���I�I\n"NOR,this_player() );
    this_player()->add_busy(random(2)+1);
  }
}

int special_attack(object me, object target, int hitchance)
{
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(6))
  {
    message_vision("$N���|�ȧ��A�r�O��V$n�I\n"NOR, this_object(), target);
    target->receive_damage("hp",random(100),me);
    target->apply_condition("poison", target->query_condition("poison")+(random(5)+5));
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
  ob->add("popularity",2);
  tell_object(ob,HIG"�A�o�� 2 �I�n��C"NOR);      
  switch( random(99) )
  {
    case  0..2: new(__DIR__"eq/primeval-sword")->move(this_object());
          break;
    case 40..99: new(__DIR__"eq/primeval-dagger")->move(this_object());
          break;
  }
  ::die();
  return;
}
