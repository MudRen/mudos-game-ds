inherit NPC;

void create()
{
	set_name("����",({ "villager" }) );
	set("long","�@�ө~��b�s���������A�ݨӨõL����L�H���B�C\n");
	set("race","�H��");
	set("age",25);
        set("level",3);
	set("attitude","friendly");

	set_skill("dodge",5);
	set_skill("unarmed",5);
      set_skill("bagi_fist",5);
      map_skill("unarmed","bagi_fist");
	setup();
add_money("silver",5);           
}
