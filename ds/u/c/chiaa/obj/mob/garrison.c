inherit NPC;
void create()

{
        set_name("守城官兵", ({ "garrison" }) );
        set("class","soldier");
        set("age",25);
        set("level",20);
        set_skill("sword", 60);
        set_skill("parry", 60);
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set("long","一個守護城門的官兵，看起來精神奕奕。\n");
        setup();
        
}

