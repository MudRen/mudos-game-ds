#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIC "���N" NOR ,({"shrimp"}) );
        set("long",@LONG
�հ��|�դ����դ�����U���@�C
LONG
);
        set("age",100);
        set("race","�H��");
        set("title",HIC"�����|�N"NOR);
        set("level",35);
        set("attitude", "peaceful");
        set("gender", "�k��" );
        set("chat_chance_combat",10);
        set_skill("parry",100);
        set_skill("dodge",100);
        set_skill("unarmed",100);
        set_skill("sword",100);
setup();
     carry_object(__DIR__"wp/blade")->wield(); 
}
void die()
{
  object ob,eqp;
  if( !ob = query_temp("last_damage_from") )
    ob = this_player(1);
  if( !ob ) 
  {
    ::die();
    return;
  }
  if( random(500) )
    eqp=new(__DIR__"wp/blade");
  else
    eqp=new(__DIR__"eq/shrimp-er");
  eqp->move(this_object());
  ::die();
  return;
}

