#include <path.h>
inherit NPC;
inherit SELLMAN;

void create()
{
  set_name("���_�a��", ({ "dig-treasure earth_elf","elf" }) );
  set("race", "beast" );
  set("gender", "����" );
  set("limbs", ({ "����","�ⳡ","�}��","�Y��" }) );
  set("verbs", ({ "bite","claw" }) );
  set("age", "???");
  set("long","�����j���@�إb�����G�H�A�y�W���O�|�ͤΤj�j�p�p���СA���W����m�}�}���ꪺ\n"                   "���O����o�I�F�@�Ӷ��⪺�j���]�A�����D�ˤF�Ǥ���F��H\n");
  set("level",1); 
  set("no_kill",1);     
  set("attitude", "friendly");
  set("sell_list",([
       __DIR__"obj/shield" : 50, 
       __DIR__"obj/ten-sword": 50,
       __DIR__"obj/scroll":50,       
       __DIR__"obj/lbg":50,
     ]) );

  setup();
}
void init()
{        
  object ob,el;
  el = this_object();  
  ::init();   
  if( interactive(ob = this_player()) && !is_fighting() )
  {
    remove_call_out("greeting");
    call_out("greeting", 10+random(30), ob); //1->10+random(30)  by ksj
  }   
  add_action("do_buy","buy");
  add_action("do_list","list");  
}

