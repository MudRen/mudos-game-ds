#include <ansi.h> 
inherit NPC;    

void create()
{
  set_name(HIW"�դѪ�"NOR, ({"white tengu","tengu"}) );
  set("long",@LONG
��O�S�j���T��Ѫ����@�A�թ�ϥΤۨ��N�A�b�Ѫ������a��Ȧb��
�Ѫ����U�C
LONG);
  set("race", "�H��");
  set("unit","��");
  set("age",80);
  set("attitude", "aggressive");
  set("gender", "�k��" );
  set("level",30);
  set("title",HIW"�T��Ѫ�"NOR); 
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
  message_vision("\n$N�Ƭ��շϮ����L�ܤF�C\n",this_object());
  destruct(this_object());
}

void die()
{
  message_vision("\n$N�S�X�@�٦l���A���Ƭ��շϮ����L�ܤF�C\n",this_object());
  destruct(this_object());
  ::die();
  return;
}
