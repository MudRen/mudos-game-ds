#include <room.h>
inherit ROOM;
inherit DOOR;

void create()
{
	set("short", "���");
	set("long", @LONG
�b�A�����e���@���j�j������A�W����۳\�\�h�h���ϮסA�C���A
�v�A�Ϯפ������D�B�s���N�����A�����U�観�Ӥp�}�A���G�O�����A��
���e�j�A����������ǳ\�����a�A���L�h�H�Ӧ��a���ˤl�A������
�a�۪��O�C
LONG
	);
	set("exits", ([
  "north" : __DIR__"flurry28.c",
  "southdown" : __DIR__"flurry13.c",
]));
	create_door("north","���","south",DOOR_CLOSED);
	set("no_clean_up", 0);
	set("outdoors","land");
	setup();
}
