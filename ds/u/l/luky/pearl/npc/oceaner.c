//oceaner.c
#include <ansi.h>
inherit NPC;
void create()
{
set_name("�����~��",({"oceaner"}));
set("level",24);
set("age",30);
set("long","�L�O�����~��, ���b�y�����}��C\n");
set("gender", "�k��");
set_skill("tenken",20);
map_skill("unarmed","tenken");
set("coin",300+random(100));
set("chat_chance",15);
set("chat_msg",({
  (:command,"north":),
  (:command,"south":),
}) );
set_temp("apply/armor",100+random(50));
set_temp("apply/damage",random(20));
set_temp("apply/dodge",50+random(30));
        setup();
set_skill("unarmed",160);
set("chat_chance_combat", 25);
set("chat_msg_combat", ({
(: this_object(), "random_move" :),
HIR"\n�����~���j�s: �u�i�c���~�Ӫ̡�T�Y�ڳo�@���T�v\n"NOR,
HIW"\n�����~���Q�k�i�O�Q�d��F...�]����\n"NOR,
     }) );
//carry_object("/u/p/pudon/obj3/ring")->wear();
}
void init()
{
add_action("no_follow","follow");
}

int no_follow(string arg)
{
if(arg=="oceaner")
 {
 message_vision("\n[1;37m�����~����M��$N[1;37m�j�s: �A��ۧڷQ�F��!!?�C[m\n",this_player());
 message_vision("\n[1;33m�����~���ΤO���F$N[1;33m�@��, �׶}�F$N�����ܡC[m\n",this_player());
 return 1;
 }
return 0;
}