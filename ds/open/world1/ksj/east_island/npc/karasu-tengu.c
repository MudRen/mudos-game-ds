#include <ansi.h>
inherit NPC;

void create()
{
  set_name("�Q�~�Ѫ�", ({"karasu tengu","tengu"}) );
  set("long",@LONG
�Ѫ�����U�A���۹��Q�~�몺�L�ڡA��ۦ�A�⮳�Z���A�]�����ͻH
�A�g�`�|ŧ���H���C
LONG
);
  set("race", "�H��");
  set("unit","��");
  set("age",40);
  set("attitude", "aggressive");
  set("gender", "�k��" );
  set("level",35+random(6));
  set_skill("fork",40+random(15));
  set_skill("dodge",40+random(10));
  set_skill("parry",30+random(10));
  add("addition_armor",30+random(10));
  set("tengu",1);
  set("chat_chance", 10);
  set("chat_msg", ({
     (: random_move :),
     }));
  setup();
  carry_object(__DIR__"eq/fork")->wield();
  carry_object(__DIR__"eq/tengu-cloth")->wear();
}

void init()
{
  ::init();
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if(!this_object()->visible(this_player())) return;
  if( this_player()->query("tengu-enemy") ) this_object()->kill_ob(this_player());
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
    case  0..4: new(__DIR__"eq/iron-cut-dagger")->move(this_object());
          break;
  }
  ::die();
  return;
}
