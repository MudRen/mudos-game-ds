#include <ansi.h>
inherit NPC;

void create()
{
  set_name(HIW""BLK"�ʥع���"NOR, ({"dream tapir","tapir"}) );
  set("long",@LONG
�ǻ������]���A�M�l���H�����ڡA�e���۪����¦���򪺨����@��
��������l�A�o���������֦��N�y���ʯv�i�J�c�ڪ��ʲ��C
LONG
);
  set("race", "beast");
  set("unit","��");
  set("age",35);
  set("attitude", "aggressive");
  set("gender", "����" );
  set("level",35+random(5));
  set("title",GRN"  ���~ "NOR);
  set("limbs", ({ "�Y��", "����","����","����"}) );
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
}

int special_attack(object me, object target, int hitchance)
{
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(10))
  {
    message_vision("\n$N�������޾�$n�i�J�L�ɪ����ڤ��A$n�@�ɪ��h�W�a�b�ߵۡI\n\n"NOR, this_object(), target);
    target->add_busy(3);
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
  ob->add("popularity",1);
  tell_object(ob,HIG"�A�o�� 1 �I�n��C"NOR);      
  ::die();
  return;
}
