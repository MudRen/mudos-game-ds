#include <ansi.h>
inherit NPC;
void create()
{
set_name("狂人", ({"coolman"}) );
set("age",30);
set("long","這是一個喜歡吃人肉，喝血的人類，因為他狂殺的個性，
秦始皇才特別不殺他，讓他在此生活。\n");
set("level",22);
set_skill("unarmed",70);
setup();
}

