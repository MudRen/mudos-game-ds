#include <ansi.h>
inherit NPC;
void create()
{
 set_name("����",({"woodcutter","cutter"}));
 set("long","�o�O�@�ӥ��b��쪺���ҡC\n");
 set("attitude","peaceful"); 
 set("age",45);
 set("gender","�k��");
 set("level",20);
 set("guild_gifts",({10,10,0,0}));
 set_skill("axe",60);
 set_skill("parry",50);
 set_skill("dodge",50);
 set("chat_chance",20);
 set("chat_msg", ({"���Ү��_�⤤�����Y, ����W��h.\n",
                   (:command("sweat"):),
 }));
 set("chat_chance_combat",200);
 set("chat_msg_combat",({                         
                         (:command,"say �A���n�ݤ��_����!!":),
 }));
 setup();
 carry_object(__DIR__"eq/axe")->wield();
 
}

