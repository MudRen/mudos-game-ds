#include <ansi.h>
inherit NPC;
void create()
{
 set_name("�L��",({"wind ranger","ranger"}));
 set("long",@LONG
�@�ӨӨ�Q�U�j�s���s���e�����L��.
LONG);
 set("title",HIY"�e����"NOR);
 set("age",30);
 set("gender","�k��");
 set("level",20);
 set_skill("sorgi_sword",20);
 set_skill("sword",20);
 set("chat_chance_combat",200);
 set("chat_msg_combat",({
    (:command,"exert sorgi_sword":),
 }));
 setup();
}

