inherit NPC;
void create()
{
        set_name("錟都步兵", ({ "city soldier","soldier" }) );
        set("long","一個身穿戰甲，手拿長劍的士兵。經常在城內組隊巡邏，維持城內治安。\n");
        set("level",30);
        set("age",35);

        set("combat_exp", 20000);
        set("chat_chance", 4);
        
        set("chat_chance_combat", 14);
        set("chat_msg_combat", ({
    "守衛說：兄弟們，把他捕了\n"
}));
        set_skill("sword", 60);
        set_skill("parry", 70);
        set_skill("unarmed", 76);
        set_skill("dodge", 65);

        setup();
        carry_object(__DIR__"obj/fake-armor")->wear();
        carry_object(__DIR__"obj/longsword")->wield();
}

