#include <ansi.h>

inherit NPC;

void create()
{
        set_name("餓死鬼", ({ "hungry ghost","ghost" }) );
        set("race","human");
        set("gender", "男性");
        set("level",18);
        set("age",500);
        set("evil",5);
        set("attitude","aggressive");
        set("long",@LONG
在戰亂中餓死的鬼魂，在人間經受了太多痛苦卻又執念於食
物，因而不得轉入輪迴。
LONG
);
        set("chat_chance",10); 
        set("chat_msg",({
                "餓死鬼中空的身體不斷掉出剛剛吃下去的東西。\n",
        }) );
        setup();
}

