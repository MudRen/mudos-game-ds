#include <ansi.h>
inherit NPC;
void create()
{
        set_name("高級女弟子",({ "apprentice" }));
        set("long","這是一位古墓派的女弟子，正在練習一套華麗的劍法。\n");
        set("level",18);
        set("gender","女性");
        set("title","古墓派");
        set("age",24);
        set_skill("sword",40);
        set_skill("girl-sword",40);
        map_skill("sword","girl-sword");
        setup();
        add_money("coin",300);
        carry_object("open/world1/wp/longsword.c")->wield();
        carry_object("open/world1/eq/cloth.c")->wear();
}

