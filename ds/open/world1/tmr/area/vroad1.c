// Room: /u/t/tmr/area/vroad1.c
#include <room.h>

inherit ROOM;
inherit DOOR;

void create()
{
	set("short", "�s����D");
	set("long", @LONG
�A�����b�s������D�A�u���Ϊ��k�M�A�������A�P���o�X�өs����
�޲z���������C���F���X�s�����D���A����i�ݨ�@�Ӥp�s���A�n�䦳��
�p�ΡA�u����Ϊ��W�e�ۤC��붮���������C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"menghouse",
  "west" : __DIR__"vroad2",
  "east" : __DIR__"ms4",
]));
	set("outdoors","land");
	set("no_clean_up", 0);

	setup();
create_door("south","��O��","north",DOOR_CLOSED);
}
