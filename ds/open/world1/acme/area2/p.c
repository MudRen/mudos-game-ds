// Room: /u/a/acme/area3/p.c
#include <path.h>
inherit ROOM;

void create()
{
	set("short", "�����j��");
	set("long", @LONG
�o�̬O�I�a�j�v�A�b���f�W�観�ӥ��j�¤�СA�W�Y�g�ۡu�I���v
�A�b�����j�����G���U���F�G�Ӯa�B�A�b�j�v�|�P�شӵ۳\�h�a�Q�A�@
���ѤѡC
LONG
	);
        set("light",1);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"p2",
"out" : ACME_PAST"area/street4",
]));
     set("objects",([
        __DIR__"npc/guard" : 2,
     ]));
	set("no_clean_up", 0);

	setup();
}
int valid_leave(object me, string dir)
{
       if( dir=="out" && !userp(me) )
                return notify_fail("���̥u�����a�~��i�h�C\n");
        return ::valid_leave(me, dir);
}
