#include <ansi.h>

inherit NPC;

void create()
{
  set_name(WHT"石巨人"NOR, ({"tall stone-man","man"}) );
  set("long",@LONG
是為了配合古墓迷宮陣所放置的[0;1;36m�[1mA[0m
主要是防衛敵人。
LONG
);
  set("race", "beast");
  set("unit","隻");
  set("age",1000);
  set("level",30); 
  set("evil",1);
  set("attitude","aggressive");
  set_skill("unarmed",80);
  set_skill("dodge",40);
  set_skill("parry",70);   
  setup();
}

