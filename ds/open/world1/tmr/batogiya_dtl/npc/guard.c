#include <npc.h>

inherit F_FIGHTER;

void create()
{
        set_name("守衛", ({ "guard" }) );
        set("long", "哈哈村的守衛，看起來弱不禁風樣子，這也能當守衛！？\n");
        set_race("human");
        set("age", 24);
        advance_stat("gin",50);
        advance_stat("hp",50);
        set_attr("str",25);
        set("chat_chance", 3);
        set("chat_msg", ({
            "守衛對著天空打了個哈欠...\n",
            "守衛「哈哈哈」地笑著...\n",
        }));

        set("title", "哈哈村");
        setup();
        set_level(3);

        switch( random(5) ) {
            case 0: carry_object(__DIR__"obj/cloth")->wear(); break;
            case 1: carry_object(__DIR__"obj/armor")->wear(); break;
            case 2: carry_object(__DIR__"obj/belt")->wear(); break;
            case 3: carry_object(__DIR__"obj/boots")->wear(); break;
            case 4: carry_object(__DIR__"obj/gloves")->wear(); break;
        }

        switch( random(5) ) {
            case 0: carry_object(__DIR__"obj/blade")->wield(); break;
            case 1: carry_object(__DIR__"obj/dagger")->wield(); break;
            case 2: carry_object(__DIR__"obj/whip")->wield(); break;
            case 3: carry_object(__DIR__"obj/axe")->wield(); break;
            case 4: carry_object(__DIR__"obj/sword")->wield(); break;
        }
    carry_money("coin", 800);
}
