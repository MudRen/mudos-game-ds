#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("���Y", ({ "wood" }) );
	set_weight(100);
	set("long", "�@�ڤS�j��W���U�Ӫ����Y�A���p����"+query_weight()+"�J�C\n");
	set("value", 0);
	set("unit", "��");

	setup();
}

void init()
{
	set("long", "�@�ڤS�j��W���U�Ӫ����Y�A���p����"+query_weight()+"�J�C\n");
}