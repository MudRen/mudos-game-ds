// Room: /d/gumu/bianhou.c
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIB"�ЦZ"NOR);
	set("long", @LONG
�o���N�O�j�Ӥ�����B���Z�A�º��������\���ݤ��M���C�ФU�۫�
���I������A�@���w���C�������G�٦��@���q�D�C
LONG	);
	set("exits",([
		"down"  : __DIR__"zhongting",
		"enter" : __DIR__"mishi1",
	]));
	set("objects",([
		__DIR__"obj/silverkey" : 1,
	]));
	setup();
	replace_program(ROOM);
}
