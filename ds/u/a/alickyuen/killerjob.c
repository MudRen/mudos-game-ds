#include <ansi.h>

inherit NPC;

string *past = ({ });
string *now = ({ });
string *future = ({ });
string *dream = ({ });

void load();

void create()
{
	set_name(HIW"�ɪŰl����"NOR, ({ "epoch catcher", "catcher" }) );
	set("level", 50);
	set("long", @long
�b�A���e���O�@��˧��j�Ǫ��H�A���W��ۡB�a�۫ܩǲ����F��A��
���o�ӮɪŪ��H�C
��M�L��������L�ӡA�A�~�o�����A��C
long);
	setup();
}

void init()
{
	add_action("do_go", "go");
	add_action("do_go", "north");
}

int do_go(string arg)
{
	if( !arg ) return notify_fail("where you want to go?\n");

	command("say i won't let you go .");

	return 1;
}
