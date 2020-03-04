inherit NPC;

void create()
{
  set_name("守衛民兵", ({ "villager guard","guard" }) );
  set("gender", "男性" );
  set("long",@long
一位健壯的村民，擔任守衛村莊的任務。
long
);      
  set("age",20+random(20));
  set("level",20+random(5));
  set("race","human");
  set("talk_reply","村莊外有許\多妖怪，沒事最好待在村子裡。\n");
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
