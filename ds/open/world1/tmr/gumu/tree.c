// Room: /d/gumu/tree.c
// Last Modifyed by Winder on Jan. 14 2002
 
#include <ansi.h> 
inherit ROOM;

void create()
{
	set("short", HIG"��W"NOR);
	set("long", @LONG 
�o���O��W�A�A��M�o�{�𸭤����ǰ��R�A�z�C�C�C�C�C�C�I�I�I
�򰩮��M�I�@���J�f�ʲӪ��������a�b��z�W�A�i�}�j�f�A���n�V�A��
�ӡI
LONG	);
	set("outdoors", "forest");
	set("objects",([
		__DIR__"npc/dumang" : 1,
	]));
	set("exits", ([ 
		"down" : __DIR__"xuanya",
	]));

	setup();
	replace_program(ROOM);
}

