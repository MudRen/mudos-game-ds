#include <ansi.h>
inherit NPC;

void create()
{
  set_name(HIW"����ù�~"NOR, ({"huge horn monster","monster"}) );
  set("long",@LONG
���������զ���򪺩_�~�A�Y�W���F�@�ڦV���s���������A�e���Y��
�_���ӴN��o�p�h�F�A�ڻ��e�����һs���������o�X���n�T�i�H��s
�L���C
LONG);
  set("race", "beast");
  set("unit","��");
  set("age",125);
  set("gender", "����" );
  set("level",42+random(4));
  set("title",HIW"  �_�~ "NOR);
  set("limbs", ({ "�Y��", "����","����","�e�}","��}" }) );
  set("verbs", ({ "bite","crash","claw"}) );
  add("addition_damage",45+random(10));
  set("chat_chance", 10);
  set("chat_msg", ({
   HIW"����ù�~"NOR"��������M�_�X�H�H�����~�C\n",
   HIW"����ù�~"NOR"�Υ������V�@�Ǫ��p��A��F���n���_�C\n",
     }));
  setup();
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
    case  0..98: new(__DIR__"eq/horn-bugle")->move(this_object());
    break;
  }
  ::die();
  return;
}
