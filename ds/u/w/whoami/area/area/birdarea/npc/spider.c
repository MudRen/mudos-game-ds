#include <ansi.h>
inherit NPC;

void create()
{
  set_name(HIR"����"NOR+MAG"�j��"NOR, ({"blooding spider","spider"}) );
  set("long",@LONG
�o�Ӿ���j��O�E�����������U�A���E��������u�Ĥ@���E
LONG);
  set("race", "beast");
  set("gender", "����");
  set("unit","��");
  set("age",12); 
  set("max_hp",30000);  set("level",36+random(5));
  set("title",HIW"�u�@��"NOR);
  set("limbs", ({ "�Y��", "����","�e��","���","�I��" }) );
  set("verbs", ({ "bite"}) );
  set("combat_exp", 12000);
  add("addition_armor",20); 
  setup();
}

void die()
{
        object me=this_object();
        object ob,obj;

        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        { 
                ::die();
                return;
        }
        message_vision("\n�]��$N�����`�A�o�өж����G�S�h�F���q���F�I\n",me);
        "/open/world1/whoami/birdarea/fox18.c"->add("exits", 
([ "enter" :  "/open/world1/whoami/birdarea/fox19.c"]));
           ::die();
           return;
}        


