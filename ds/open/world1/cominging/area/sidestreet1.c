#include <room.h>
inherit ROOM;
inherit DOOR;
void create()
{
	set("short", "����");
	set("long",@LONG
�A�b�o��ť����b��j��W��ť�쪺�n�[�n�A�A�J��ť�Fť�A�j
���O���䪺�@��H�a�A�A�ݨ쨺�u�O�@�Ӥp�p���T�X�|�A�W���g�ۡu�s
�o��v�A�A�]�ͤ��M�����O����F��A�_��O�������Y�A�ӪF��h�O�~
�򩹰���e�i�C
LONG
	);
	set("exits", ([
  "north" : __DIR__"sidestreet.c",
  "east" : __DIR__"sidestreet2.c",
  "enter" : __DIR__"quarrelhouse.c",
]));
	set("no_clean_up", 0);
	set("outdoors","land");
	setup();
	create_door("enter","��","out",DOOR_CLOSED);
}
