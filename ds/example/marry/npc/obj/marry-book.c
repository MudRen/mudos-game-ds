// Obj: /d/ruzhou/npc/obj/marry-book.c ���B����
#include <ansi.h>

inherit ITEM;

void init()
{
        add_action("do_read", "fan");
}

void create()
{
	set_name("�m���B�����n", ({ "jiehun xuzhi", "xuzhi"}));
	set("weight", 600);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 500);
		set("material", "paper");
		set("long", "�o���ѤW�g�ۥ�MUD���B���{�ǡA�A�i�H½�\(fan)���C\n");
	}
	setup();
}

int do_read(string arg)
{
    if (!arg||(arg!="jiehun xuzhi"&&arg!="xuzhi"))
        return notify_fail("�A�S���o���ѡA��½�f�U�z���\�H\n");
    this_player()->start_more(read_file("/doc/help/marry"));
    return 1;
}

