#include <ansi.h>
inherit NPC;
void create()
{
 set_name("������",({"prayer",}));
 set("long"," �o�O�@��ѱ������۫H�{. \n"
     );
 set("attitude","peaceful");
 set("age",44);
 set("gender","�k��");
set("level",18);
 set_skill("unarmed",50);
 set("chat_chance",5);
 set("chat_msg", ({"�����̻�: �ש�@�v�ڦh�~�����@!\n",
}));
 set("chat_chance_combat",15);
                         (:command,"say �z!!  ":),
 setup();
 carry_object(__DIR__"eq/cloth")->wear();
 carry_object(__DIR__"eq/grass_boots")->wear();
}                                                                              
