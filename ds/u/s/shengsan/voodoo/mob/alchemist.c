
inherit NPC;

void create()
{
	set_name("煉丹術士", ({"alchemist"}) );
	set("race", "人類");
	set("gender", "男性");
	set("level",60);
	set("age", 40);
	set("evil",20+random(10));
	set("long", "他是一位道風仙骨的煉丹術士\n");
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
