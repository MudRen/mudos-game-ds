// This is a npc made by npcmaker.

inherit NPC;

void create()
{
        set_name( "����", ({ "roken" }));
        set("long", "�@����L���C�h, �L�ݰ_�ӤQ���i�r, �@�T����U�d���ˤl�C\n");
        set("age", 34);
        set("level",7);
        set("race", "�H��");
        set("attitude", "peaceful" );
        set_skill("sword",30);
        set_skill("dodge",25);
        set_skill("parry",25);

	setup();
carry_object(__DIR__"wq/guardsword")->wield();}
