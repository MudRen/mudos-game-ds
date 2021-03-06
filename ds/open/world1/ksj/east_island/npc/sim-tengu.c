#include <ansi.h> 
inherit NPC;    

void create()
{
  set_name(HIW"白天狗"NOR, ({"white tengu","tengu"}) );
  set("long",@LONG
能力特強的三色天狗之一，擅於使用幻身術，在天狗中的地位僅在黑
天狗之下。
LONG);
  set("race", "人類");
  set("unit","隻");
  set("age",80);
  set("attitude", "aggressive");
  set("gender", "男性" );
  set("level",30);
  set("title",HIW"三色天狗"NOR); 
  set_skill("fork",100);
  set_skill("dodge",100);
  set_skill("parry",100);
  add("addition_armor",60+random(10));
  setup();
  call_out("dest_tengu", random(10)+20);
}

void init()
{
  ::init();
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if(!this_object()->visible(this_player())) return;
  if( this_player()->query("tengu-enemy") ) this_object()->kill_ob(this_player());
  if(userp(this_player())) this_object()->kill_ob(this_player());
}

void dest_tengu()
{
  message_vision("\n$N化為白煙消失無蹤了。\n",this_object());
  destruct(this_object());
}

void die()
{
  message_vision("\n$N露出一抹奸笑，竟化為白煙消失無蹤了。\n",this_object());
  destruct(this_object());
  ::die();
  return;
}
