#include <path.h>
inherit NPC;

void create()
{
	set_name("�K���@�k", ({"body protector","body"}) );
	set("race", "�H��");
	set("gender", "�k��");
	set("level",64);
	set("age", 32);
	set("long", "�L���b�O�@�ХD���w��\n");
        set_skill("unarmed", 70);
        set_skill("dodge", 150);
	set_skill("whip", 180);
	setup();

	add_money("coin",500);
	carry_object(SHENGSAN+"voodoo/eq/goldwhip")->wield();
}

void init()
{
  if (this_player()->query_temp("voodoo")==1)
  {
	say("�@���H�v�q�A���ǭ��F�L�ӡM�����B���M��O�Z�\\���z�C\n");
	command("say �ХD, �ݤU�ӿ�, �ݧڱN�o��H�ѨM�A�V�z�иo�T\n");
	kill_ob(this_player());
  }
}
