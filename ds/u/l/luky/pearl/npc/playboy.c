//oceaner.c
#include <ansi.h>
inherit NPC;
void create()
{
set_name("�j�Ǩk��",({"play boy","boy"}));
set("level",25);
set("age",21);
set("long","�@�ӵL�ҨƬO���C�~�H, �@��鲴���_���˵۸��L���}�G���ܡC\n");
set("gender", "�k��");
set_skill("tenken",20);
map_skill("unarmed","tenken");
set("coin",300+random(280));
set("chat_chance",5);
set("chat_msg",({
  (:command,"drool":),
}) );
set_temp("apply/armor",100+random(50));
set_temp("apply/damage",random(20));
set_temp("apply/dodge",50+random(30));
        setup();
set_skill("unarmed",160);
set("chat_chance_combat", 25);
set("chat_msg_combat", ({
(: this_object(), "random_move" :),
HIR"\n�~���H�j�s: �u���شN���n�]��T���ڪB�ͨӧA�N���F�T�v\n"NOR,
HIW"\n�~���H�Q�k�i�O�Q�d��F...�]����\n"NOR,
     }) );
//carry_object(__DIR__"item/glasses")->wear();
}
