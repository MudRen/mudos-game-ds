#include <ansi.h>
inherit NPC;
void create()
{
	set_name(HIG"虛弱"NOR"礦工",({"weak worker","worker"}) );
	set("long", @LONG
    一個生病的礦工，嘴裡不斷的喃喃自語，全身長滿了疙瘩，你不
確定他到底是因疾病還是任何因素才變成今天這個樣子，你直覺還是
不應該太靠近他才好...。
LONG
);
	set("race", "人類");
	set("age", 30);
	set("level", 15);
        set("attitude","killer");
        set("chat_chance", 5);
        set("chat_msg", ({
       (: command("say 水...給我水...") :),
       (: command("say 食物...給我食物...") :),
       (: command("say 身體好癢...好癢...") :),
}));
	setup();
	carry_object(__DIR__"eq/eq.c")->wear();
}
