
inherit NPC;

void create()
{
	set_name("�Ҥ��N�h", ({"alchemist"}) );
	set("race", "�H��");
	set("gender", "�k��");
	set("level",60);
	set("age", 40);
	set("evil",20+random(10));
	set("long", "�L�O�@��D���P�����Ҥ��N�h\n");
	set("attitude", "heroism");
        set_skill("unarmed", 60);
        set_skill("fireball", 100);
        set_skill("dodge", 140);
	set("env/spellpower",7);
        set("chat_chance_combat",50);
        set("chat_msg_combat", ({
        (: cast_spell2, "fireball" :),
                   }) );
	setup();
	
}
