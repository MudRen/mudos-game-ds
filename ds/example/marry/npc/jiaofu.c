// jiaofu.c

inherit NPC;

void create()
{
	set_name("�}��", ({ "jiao fu", "fu" }) );
	set("gender", "�k��" );
	set("age", 20+random(15));
	set("long",
		"�o�O�Ӧѹ�ڥ檺���~�H�A�M�����H�D�F��A���o�H��y��A�@���٦סC\n");
	set("combat_exp", random(10000));
   set("str", 25);
   set("dex", 22);
   set("con", 20);
   set("int", 15);
	set("attitude", "heroism");

	setup();
   carry_object("clone/misc/cloth")->wear();
}