#include <ansi.h>
inherit NPC;
void create()
{
 set_name("膜拜者",({"prayer",}));
 set("long"," 這是一位天梟的忠誠信徒. \n"
     );
 set("attitude","peaceful");
 set("age",44);
 set("gender","男性");
 set("level",20);
 set_skill("unarmed",50);
 set("chat_chance",15);
 set("chat_msg", ({"膜拜者說: 終於一償我多年的心願!\n",
}));
 set("chat_chance_combat",15);
                         (:command,"say 哇!!  ":),
 setup();
 carry_object(__DIR__"eq/cloth")->wear();
 carry_object(__DIR__"eq/grass_boots")->wear();
}                                                                              

