// This is a npc made by npcmaker.

inherit NPC;

void create()
{
        set_name( "�ͽ�", ({ "guard" }));
        set("long", "�L�ݰ_�ӤQ���i�r, ���������z�X, �ݰ_�Ӭ۷��n���I���ˤl�C\n");
        set("age", 30);
        set("level",15);
	set("race", "�H��");
        set("title", "��ö�");
        set("attitude", "aggressive" );

	setup();
carry_object(__DIR__"wq/guardsword")->wield();}
