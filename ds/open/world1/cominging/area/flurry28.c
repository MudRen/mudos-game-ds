#include <room.h>
inherit ROOM;
inherit DOOR;

void create()
{
	set("short", "���Y��");
	set("long", @LONG
�o�̬O�F��n�_�|�䪺���Y�����A�]�O�����q���_�n���g�����|�A
�g�`���ǤH�q�o�ө��A�o�઺�γ����Ǻ|�}�A�Y�O�U�B�F���|�|���A��
�ӨS���H�ӭײz���ˤl�C
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"flurry32.c",
  "south" : __DIR__"flurry24.c",
  "west" : __DIR__"flurry27.c",
  "east" : __DIR__"flurry29.c",
]));
	create_door("south","���","north",DOOR_CLOSED);
	set("no_clean_up", 0);
	set("light",1);
	setup();
}
