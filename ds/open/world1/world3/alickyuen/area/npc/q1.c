#include <ansi.h>
inherit NPC;

void create()
{
	set_name("�L��", ({"lam sze","lam","sze"}) );
	set("long", "�@�Ӳפ�L�Ҩƨƪ��H,���H�M�پK�~�C\n");
            set("nickname",RED"�K�~"NOR);
	set("race", "�H��");
	set("age", 40);
	set("level", 15);
set("max_hp",1000);
	setup();
carry_object(__DIR__"obj/waterb");
carry_object(__DIR__"wp/staff.c")->wield();
}

