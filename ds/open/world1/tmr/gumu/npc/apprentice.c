#include <ansi.h>
inherit NPC;
void create()
{
        set_name("女弟子",({ "apprentice" }));
        set("long","這是一位古墓派的女弟子，正在練習一套華麗的劍法。\n");
        set("level",8);
        set("gender","女性");
        set("title","古墓派");
        set("age",19);
        setup();
        add_money("coin",300);
        carry_object("open/world1/wp/longsword.c")->wield();
}

