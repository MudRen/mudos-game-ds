#include <ansi.h>
inherit NPC;

void create()
{
        set_name("村民",({ "villager" }) );
        set("long","住在北蠻村的村民，平常喜愛在些上亂逛。\n");
        set("race","人類");
        set("age",30);
        set("level",10);
        set("attitude","friendly");
        set("no_fight", 1);
        set("chat_chance",10);
        set("chat_msg",({
        "村民嘆道：唉..那位老婦人還真可憐...可惜我沒法子幫她。\n",
        "村民說道：這個村子還真祥和..可惜美中不足, 有那個東西阿..\n",
        (:command("stare"):),
        (: random_move() :),
        }) );
        setup();                
}
