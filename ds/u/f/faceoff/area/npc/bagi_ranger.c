#include <ansi.h>
inherit NPC;
void create()
{
 set_name("�L��",({"bagi ranger","ranger"}));
 set("long",@LONG
�@�ӨӨ�Q�U�j�s���s���K�����L��.
LONG
    );
 set("attitude", "peaceful");
 set("title",HIR"�K����"NOR);
 set("age",30);
 set("gender","�k��");
 set("level",20);
 set_skill("bagi_fist",20);
 set_skill("unarmed",20);
 set("chat_chance_combat",200);
 set("chat_msg_combat",({(:command,"exert bagi_fist":),
 }));
 setup();
 carry_object(__DIR__"eq/iron_fist")->wield();
 carry_object(__DIR__"eq/black_suit")->wear();
}
