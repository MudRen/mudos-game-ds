inherit NPC;

void create()
{
  set_name("�u�å��L", ({ "villager guard","guard" }) );
  set("gender", "�k��" );
  set("long",@long
�@�찷���������A����u�ç��������ȡC
long
);      
  set("age",20+random(20));
  set("level",20+random(5));
  set("race","human");
  set("talk_reply","�����~���\\�h���ǡA�S�Ƴ̦n�ݦb���l�̡C\n");
  setup();
  carry_object(__DIR__"eq/halbert")->wield();
  add_money("coin",500+random(100));
}

void init()
{
  ::init();
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if(!this_object()->visible(this_player())) return;
  if( this_player()->query("apeman") ) this_object()->kill_ob(this_player());
}
