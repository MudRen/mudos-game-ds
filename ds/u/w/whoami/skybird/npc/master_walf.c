#include <ansi.h>
inherit NPC;
void create()
{
 set_name("楊思琴",({"yang si chin","yang"}));
 set("long",@LONG
趙長孫的配偶, 只見她皮膚雪白猶勝於雪, 身材恰到好處, 
雖然上了年紀, 但美麗絲毫不減!
.........
果然美人是不可以用言語表達的!

LONG
    );
 set("attitude","peaceful"); 
 set("title","掌門夫人"); 
 set("age",40);
 set("gender","女性");
 set("level",20);
 set_skill("sky-dagger",30);
 set_skill("dagger",40);
 set("chat_chance",10);
 set("chat_chance_combat",200);
 set("chat_msg_combat",({(:command,"exert sky-dagger":),
 }));
 setup();
 carry_object(__DIR__"eq/owl_cloth")->wear();
 carry_object(__DIR__"eq/dagger")->wield();
}
