#include <room.h>
inherit DOOR;
inherit ROOM;

void create()
{
        set("short", "�T�s��j��");
        set("long", @LONG
�T�s��o�W�O�]���o�y��l�ئb�@�y�p�s�Y�W�A�P�仡�O�p
�s�A���p���O�@�y���ۥC���A�ӥB��l�ح����@�����q���j���u
���A���ۤs�լy�U�C
LONG);
        set("exits", ([ /* sizeof() == 3 */
  "out" : __DIR__"camp002",
  "north" : __DIR__"camp004",
  "south" : __DIR__"camp005",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"mob/camp_guard" : random(2)+1,
  ]));
        set("light",1);
        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
        create_door("out","���","enter",DOOR_CLOSED);
}

int valid_leave(object me, string dir)
{
       ::valid_leave();
       if( dir=="out" && !userp(me) )
           return notify_fail("���̥u�����a�~��i�h�C\n");
       return ::valid_leave(me, dir);
}

