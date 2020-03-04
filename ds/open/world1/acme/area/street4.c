// Room: /u/a/acme/area/street4.c
#include <path.h>
inherit ROOM;

void create()
{
        set("short", "��D");
        set("long", @LONG
�o�̬O�ѫ��F�䪺��D�A��������e��Ӥѫ��A����i�ݨ�ѫ���
�j�s���A���F����i�ݨ������C
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
"enter" : ACME_PAST"area2/p.c",
  "west" : __DIR__"street3",
  "east" : __DIR__"street5",
]));
    set("objects",([
       __DIR__"npc/man" : 1,
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

