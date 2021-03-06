#include <npc.h>

inherit F_FIGHTER;

void create()
{
        set_name("哈拉剛", ({ "ha la gang", "gang" }) );
        set("long", "哈哈村的武士之一，大家都稱他為「哈王」，似乎很厲害的樣子。\n");
        set_race("human");
        set("age", 24);

        set_attr("str",25);

        setup();

        advance_stat("gin",100);
        advance_stat("hp",100);

        carry_object(__DIR__"obj/cloth")->wear();
        carry_object(__DIR__"obj/armor")->wear();
        carry_object(__DIR__"obj/sword")->wield();

        carry_money("gold", 1);
        set_level(15);
}
