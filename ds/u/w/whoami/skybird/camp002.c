#include <room.h>
inherit ROOM;
inherit DOOR;
void create()
{
        set("short", "�T�s��j��");
        set("long", @LONG
�T�s��o�W�O�]���o�y��l�ئb�@�y�p�s�Y�W�A�P�仡�O�p
�s�A���p���O�@�y���ۥC���A�ӥB��l�ح����@�����q���j���u
���A���ۤs�լy�U�C
LONG);
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"camp001",
  "enter" : __DIR__"camp003",
]));
        set("light",1);
        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
        create_door("enter","���","out",DOOR_CLOSED,"nokey");
}

