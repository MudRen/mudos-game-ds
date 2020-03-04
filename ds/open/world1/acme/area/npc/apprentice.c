#include <ansi.h>
inherit NPC;
void create()
{
        set_name("神武第三代弟子" , ({ "apprentice" }) );
        set("level",10);
        set("race","人類");
        set("gender","男性");
        set("age",18);
        set("int",19);
        set("str",5);
        set_skill("sword",10);
        set_skill("godsword",10);
        set_spell("god-fire",25);
        set_skill("parry",5);
        set_skill("dodge",10);
        set("long","他是神武教第三代第子，正在這裡勤練武功\。\n");
        set("chat_chance", 3);
        set("chat_msg",({
            "神武第三代弟子喝道：殺∼∼\n",
            "神武第三代弟子手中真火直燒向木人。\n",
        }) );
        set("chat_chance_combat",100);
        set("chat_msg_combat",({
            (:command("exert godsword"):),
            (:command("cast god-fire"):),
            "神武第三代弟子喝道：兄弟們！把這傢伙給宰了！\n",
        }) );
        setup();
        carry_object(__DIR__"wp/sword2.c")->wield();
}
