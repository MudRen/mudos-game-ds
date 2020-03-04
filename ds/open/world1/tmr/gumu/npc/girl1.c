#include <ansi.h>
inherit NPC;
void create()
{
        set_name("黃衫女子",({ "yellow-shirt girl","girl" }));
        set("long","這是一位古墓派的女弟子，長的清麗出眾，只是冷淡淡的，沒有什麼特別的表情。\n");
        set("level",20);
        set("gender","女性");
        set("title","古墓派");
        set_skill("unarmed",50);
        set_skill("sword",50);
        set_skill("parry",50);
        set_skill("dodge",50);
        set_skill("girl-sword",50);
        map_skill("sword","girl-sword");
        set("age",19);
        setup();
        add_money("coin",300);
        carry_object("open/world1/wp/longsword.c")->wield();
        carry_object(__DIR__"obj/yellow-shirt")->wear();
        carry_object(__DIR__"../obj/fengmi");
}

