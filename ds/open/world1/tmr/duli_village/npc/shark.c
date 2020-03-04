#include <npc.h>

void create()
{
        set_name("大白鯊", ({ "big shark","shark" }) );
        set_race("beast");
        set("verbs", ({ "bite" }) );
        set("age", 20);
        set("long", "一隻牙尖嘴利的大白鯊，長約過尺，正惡狠狠地盯著你，似乎要把你吃了。\n");
        set("attitude", "aggressive");
        setup();
        set_level(15);
        carry_object(__DIR__"obj/shark-armor");
}

