#include <ansi.h>
inherit NPC;
void create()
{
set_name("郭恦", ({"purian"}) );
set("long","這位是秦始皇的愛將之一，在沙場上不知道為秦始皇立下了
多少汗馬功勞，是一位名響戰國的人物。\n");
set("level",41);
     set("title",YEL"左衛"NOR);
set_skill("unarmed",70);
setup();
}
