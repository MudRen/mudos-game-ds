#include <ansi.h>
inherit NPC;

void create()
{
  set_name(HIB"�W"HIW"���~"NOR, ({"single monster","monster"}) );
  set("long",@LONG
�@���u���@���������_���Ǫ��C�t�@���������G�O�Q�������C���Q
���u��A���W���_���o�X���c����C
LONG);
  set("race", "beast");
  set("unit","��");
  set("age",70);
  set("attitude", "aggressive");
  set("gender", "����" );
  set("level",45+random(3));
  set("title",HIR"���~"NOR);
  set("limbs", ({ "�Y��", "����","����","����","�I��" }) );
  set("verbs", ({"bite","claw"}) );
        set("chat_chance",10);
        set("chat_msg",({
        (: random_move() :),
        }) );
  setup();
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
    message_vision(HIB"�W"HIW"��"HIB"�~"NOR"�oı���H�a��A�ĤO���@���A����Ӧa���_�ʡI�I\n"NOR,this_player() );
    this_player()->add_busy(random(1)+1);
  }
}

int special_attack(object me, object target, int hitchance)
{
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(6))
  {
    message_vision("$N����a�Τ��l�ƨg�����V$n�A��$n���ݤf�X�{�Ʊ��岪�I�I\n"NOR, this_object(), target);
    target->receive_damage("hp",random(100),me);
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
  ::die();
  return;
}

