// updated 26/12
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[1;36mST�DRecycleStation�IRobot[2;37;0m");
	set("long", @LONG
�o�̬O�@�����F���ȿ����F�褧�~�A���򳣷|�^�����^���ΡC�ӳo��
���^������M��L�����O�@�ˡA�ҥH�����|�X�{����W�����D�C�ӳo�̪�
�^���u�@�O�Ѿ���H�t�d�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"dst9",
]));
set("light",1);
	set("world", "future");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/seller.c" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
