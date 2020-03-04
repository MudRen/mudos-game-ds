inherit NPC;

void create()
{
        set_name("錢莊守衛", ({ "guard" }) );
	set("long",
	"一個看來守護錢莊安危的青年，長得虎背熊腰、孔武有力的樣子。\n"
	);
        set("class","fighter");
	set("gender","男性");
        set("age",23);
        set("level",8);
        set_skill("sword", 50);
        set_skill("parry", 50);
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
	setup();
      add_money("silver",20);
	carry_object(__DIR__"wp/sword")->wield();
}
