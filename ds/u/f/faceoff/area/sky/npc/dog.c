inherit NPC;

void create()
{
        set_name("黑狗", ({ "dog" }) );
        set("race", "野獸");
        set("age", 5);
       set("level",4);
        set("long", "一隻黑狗, 獨自在這流浪....。\n");
        set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("chat_chance", 6);


        setup();
}

