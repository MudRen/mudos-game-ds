#include <npc.h>

inherit F_FIGHTER;

void create()
{
        set_name("哈熱狗拉絲", ({ "ha hot dog lasi", "lasi" }) );
        set("long", "哈哈村的武士之一，號稱「神射手」但卻不拿弓，實在有點怪異。\n");
        set_race("human");
        set("age", 24);

        set_attr("str",25);

        setup();

        advance_stat("gin",100);
        advance_stat("hp",100);

        carry_object(__DIR__"obj/belt")->wear();
        carry_object(__DIR__"obj/boots")->wear();
        carry_object(__DIR__"obj/gloves")->wear();
        carry_object(__DIR__"obj/dagger")->wield();

        carry_money("gold", 1);
        set_level(15);
}
