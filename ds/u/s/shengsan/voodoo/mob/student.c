
inherit NPC;

void create()
{
	set_name("�J���s��", ({"student"}) );
	set("race", "�H��");
	set("gender", "�k��");
	set("level",30);
	set("age", 16);
	set("long", "�o�O�@�ӭ�J�����Ю{\n");

        set("chat_chance",50);
	set("chat_msg",({
	   (:command,"east":),
	   (:command,"west":),
	   (:command,"south":),
	   (:command,"north":),
	   (:command,"up":),
	   (:command,"down":)
           }));

	setup();
	
}
