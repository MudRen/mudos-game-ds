inherit NPC;

void create()
{
        set_name("�����u��", ({ "guard" }) );
	set("long",
	"�@�ӬݨӦu�@�����w�M���C�~�A���o��I���y�B�ժZ���O���ˤl�C\n"
	);
        set("class","fighter");
	set("gender","�k��");
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
