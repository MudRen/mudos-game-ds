#include <ansi.h>
inherit NPC;
void create()
{
 set_name("天梟守衛",({"guard",}));
 set("long","             你看了一看這一個昔日大教的守衛, 只見他的太陽穴微
             微突起, 顯然所修練的內\功\並\不\深\厚\, 但一雙手掌卻粗
             糙無比, 想來外家\功\夫\不\容\小\覷\."
     );
 set("attitude","peaceful"); 
 set("age",35);
 set("gender","男性");
 set("combat_exp",124753+random(38358));
 set("level",15);
 set_skill("unarmed",50);
 set_skill("force",30);
 set("guild_gifts",({10,4,0,6}));
 set("chat_chance",10);
 set("chat_msg", ({"天梟守衛兩眼盯著你看.... .\n",
}));
 set("chat_chance_combat",200);
                         (:command,"say 難道天梟人人可欺!!  ":),
 setup();
 carry_object(__DIR__"eq/cloth")->wear();
}
