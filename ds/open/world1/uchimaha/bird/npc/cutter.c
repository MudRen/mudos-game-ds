#include <ansi.h>
inherit NPC;
void create()
{
 set_name("樵夫",({"woodcutter","cutter"}));
 set("long","這是一個正在伐木的樵夫。\n");
 set("attitude","peaceful"); 
 set("age",45);
 set("gender","男性");
 set("level",20);
 set("guild_gifts",({10,10,0,0}));
 set_skill("axe",60);
 set_skill("parry",50);
 set_skill("dodge",50);
 set("chat_chance",20);
 set("chat_msg", ({"樵夫拿起手中的斧頭, 往樹上砍去.\n",
                   (:command("sweat"):),
 }));
 set("chat_chance_combat",200);
 set("chat_msg_combat",({                         
                         (:command,"say 你不要看不起樵夫!!":),
 }));
 setup();
 carry_object(__DIR__"eq/axe")->wield();
 
}

