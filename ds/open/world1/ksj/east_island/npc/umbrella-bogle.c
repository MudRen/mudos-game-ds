#include <ansi.h>
inherit NPC;

void create()
{
  set_name("�B�ʧ���",({"umbrella bogle","bogle"}) );
  set("long",@LONG
�~�ι��@��ȳʪ����ǡA�ʭ��W���@���j�j����������������Y�A��
�⪺�����O�@���k�}�A�@�ۤ@�ۦa�|�B���ʡC
LONG
);
  set("race", "���~");    
  set("unit","��");
  set("age",68);
  set("attitude", "aggressive");
  set("level",28+random(4));
  set("limbs", ({ "�ʭ�", "����","���Y","�k�}"}) ); 
  set("verbs", ({ "bite" }) );     
  set("chat_chance", 10);
  set("chat_msg", ({
      "�B�ʧ��Ǥ@��ϵۦ��Y�A�@��Υk�}���Ӹ��h�C\n",
     }));                                
  setup();
  add_money("coin",500);
}

void init()
{
  ::init();
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if(!this_object()->visible(this_player())) return;
  if(this_player()->query("level") < 26 && userp(this_player()) )
    this_object()->kill_ob(this_player());
}

int special_attack(object me, object target, int hitchance)
{
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(4) && (target->query_int() < 50) )
  {
    message_vision("\n$N����ʭ������۪᯾�A$n�����aı�o�Y�w�دt$n�A�ѱۦa��C\n\n", me, target);
    target->add_busy(2);
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
  switch( random(200) )
  {
    case  0: 
          new(__DIR__"eq/hundred-bogle-necklace")->move(this_object());
          break;
    case  1..30: 
          new(__DIR__"eq/bogle-bead")->move(this_object());
          break;
  }
  ::die();
  return;
}
