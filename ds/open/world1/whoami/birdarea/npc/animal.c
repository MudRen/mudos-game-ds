#include <ansi.h>
inherit NPC;
void create()
{
       set_name("不知名的動物",({"noname animal","animal"}));
        set("level",5+random(15));
        set("race", "野獸");
        set("age", 70);
        set("long", "牠是一隻不知名的動物，有關牠的一切全部都是個迷•\n");
        set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾部"}) );
        set("verbs", ({ "bite", "claw", "crash"}) );
        setup();
}

