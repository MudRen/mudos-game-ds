// Room: /open/world1/acme/area/smallway.c
#include <path.h>
inherit ROOM;

void create()
{
	set("short", "�C�j���D");
	set("long", @LONG
�A�����b���������D�W�A���D�O�ѫC�j�Һc���A�Q���O�x���ҳy���D
���A�|�P���������A�@���I�R�A�L���@�j�A�G�ǰ��q����A�����ɭ��C
LONG
	);
	set("world", "past");
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 1 */
  "southeast" : __DIR__"pathway1",
  "enter" : ACME_PAST+"cominging/bigwall.c",
]));
	set("no_clean_up", 0);
     set("outdoors","land");

	setup();
}
int valid_leave(object me, string dir)
{
       if( dir=="enter" && !userp(me) )

                return notify_fail("���̥u�����a�~��i�h�C\n");
        return ::valid_leave(me, dir);
}
