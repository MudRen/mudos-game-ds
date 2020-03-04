// ovelia.c
#include <ansi.h>
inherit NPC;
void create()
{
set_name("�A�涤����",({"tower leader","leader"}));
set("long","�@��g���״I���A�涤����, �L���������n�ۧA���@�|�@�ʡC\n");
set("title","���Ԥ�");
set("level",65);
set("age",38);
set("gander","�k��");
set("class","fighter");
set_skill("rapid",400);
//set_temp("apply/armor",420);
//set("max_mp",700000);
set_temp("apply/dodge",60+random(30));
set("coin",random(2400)+1000);
set("chat_chance_combat",9);
set("chat_msg_combat",({
  (:command,"angry":),
  (:command,"rapid":),
}));
set_heart_beat(1);
setup();
carry_object(__DIR__"eq/towercloth")->wear();
carry_object(__DIR__"eq/towerhelm")->wear();
carry_object(__DIR__"eq/towerboots")->wear();
carry_object(__DIR__"wp/towersword")->wield();
carry_object(__DIR__"item/greenp");
carry_object(__DIR__"item/greenp");
carry_object(__DIR__"item/greenp");
carry_object(__DIR__"item/greenp");
carry_object(__DIR__"item/greenp");
carry_object(__DIR__"item/cacap");
carry_object(__DIR__"item/cacap");
carry_object(__DIR__"item/cacap");
carry_object(__DIR__"item/cacap");
carry_object(__DIR__"item/cacap");
}

void heart_beat()
{
 object me;
 me = this_player();
 if(!me) return;
 if ( query("hp")<30000 && (random(5)>2))
 {
  command("drink potion");
 }
 ::heart_beat();
 if(me)
 {
  if (me->query("hp") < 0)
  me->die();
 }
}

void die()
{
::die();
//destruct(this_object());
}