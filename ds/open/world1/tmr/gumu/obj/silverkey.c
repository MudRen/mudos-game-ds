// Room: /d/gumu/obj/silverkey.c
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>;
inherit ITEM;

void create()
{
	set_name(HIW"���_��"NOR, ({"silver key","key"}));
	set_weight(10);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit","��");
		set("long","�o�O�@��ջȥ���_�͡A�W�ѥj�Ӧr�ˡA���G�M�j�Ӫ��Y�ǯ��K�����C\n");
		set("value", 400);
		setup();
	}
}

