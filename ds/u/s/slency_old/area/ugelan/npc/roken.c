// This is a npc made by npcmaker.

inherit NPC;

void create()
{
        set_name( "洛肯", ({ "roken" }));
        set("long", "一位路過的劍士, 他看起來十分勇猛, 一幅豪氣萬千的樣子。\n");
        set("age", 34);
        set("level",7);
        set("race", "人類");
        set("attitude", "peaceful" );
        set_skill("sword",30);
        set_skill("dodge",25);
        set_skill("parry",25);

	setup();
carry_object(__DIR__"wq/guardsword")->wield();}
