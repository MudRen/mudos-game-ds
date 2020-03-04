#include <ansi.h>
inherit NPC;

void create()
{
  set_name(HIC"������"NOR, ({"water deer","deer"}) );
  set("long",@LONG
�@���������Ū��G���A�e���W����֦p������i�ʡA�i�H�Ϯg�P��
�ƪ��A���ĤH�L�k��{�X�ۤv�C
LONG
);
  set("race", "beast");
  set("unit","��");
  set("age",15);
  set("gender", "����" );
  set("dex",65);
  set("level",32+random(4));
  set("title",HIW"  �_�~ "NOR);
  set("limbs", ({ "�Y��", "����","����","�e�}","��}" }) );
  set("verbs", ({ "bite","crash" }) );
  set("chat_chance", 15);
  set("chat_msg", ({
     (: random_move :),
     }));
  setup();
}

void init()
{        
  ::init();
  switch( random(15) )
  {
    case 0:
         say(HIC"������"NOR"���i���O�����������F�C\n");
         destruct(this_object());
         break;
    case 1..7:
         this_object()->set_temp("hide",1);
         break;
  }
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
    case  0..9: new(__DIR__"eq/deerskin-surcoat")->move(this_object());
          break;
  }
  ::die();
  return;
}
