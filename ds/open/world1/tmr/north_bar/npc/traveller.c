#include <ansi.h>
inherit NPC;

void create()
{
        set_name("旅人",({ "traveller" }) );
        set("long","這是一位從外地來的旅人，風塵僕僕的，長的還滿健壯的，不畏風寒。\n");
        set("race","人類");
        set("age", 30);
        set("level",10);
        set("attitude","friendly");
        set("chat_chance",10);
        set("chat_msg",({
                (:command("stare"):),
                (:command("sweat"):),
        }) );
        setup();
        carry_object("/open/world1/obj/ts_bag");
}

