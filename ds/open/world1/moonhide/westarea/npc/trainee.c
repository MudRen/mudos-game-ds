#include <ansi.h>
inherit NPC;
void create()
{
        set_name("逐日者新兵", ({ "sun-follow trainee", "trainee"}) );
        set("level", 15);
        set("long" ,"這是一位剛加入「逐日者」的新兵，長的高大威武。\n");
        set("age", 30);
        setup();
}

