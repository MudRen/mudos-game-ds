#include <ansi.h>
inherit NPC;

void do_dest() 
{
         say(CYN"�K����"NOR"��M�ਭ�g�b�A�����b�@�Ӧa�}���C\n");
         destruct(this_object());
}

void create()
{
  set_name(CYN"�K����"NOR, ({"iron beetle","beetle"}) );
  set("long",@LONG
�@�����j�����ΡA���l�w�g�h�ƦӵL�k�����A���K�몺�ҴߤW���F�@
�K���j���y���A�ݰ_�ӫܨ�¯٩ʡA���e���O�Y�����C
LONG
);
  set("race", "beast");
  set("gender", "����");
  set("unit","��");
  set("age",10);
  set("level",26+random(2));
  set("title",HIW"  �_�~ "NOR);
  set("limbs", ({ "�Y��", "����","�e��","���","�I��" }) );
  set("verbs", ({ "bite","crash" }) );
  set("combat_exp", 12000);
  add("addition_armor",70);
  set("chat_chance", 20);
  set("chat_msg", ({
     (: random_move :),
     (: random_move :),
     (: do_dest :),
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
  if( random(100) < 10 ) {
        new(__DIR__"eq/iron-beetle-shield")->move(this_object());
  }

  ::die();
  return;
}

