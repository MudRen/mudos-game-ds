// Room: /open/world1/acme/bonze/b11.c

#include <path.h>
inherit ROOM;

void create()
{
	set("short", "�s�D");
	set("long", @LONG
�A���b�ᬰ�}�ª��s�D�W�A�}�U���۪O���n�n�̮̪��غc�b�s��
�����A�ݱo�p���l�l���樫�A�H�����V�L�ܤs�����C����_�誺�s�D
�O�q���ⶳ�p���ߤ@�D���C���F�_��i�q���ⶳ�x�x�q�C
LONG
	);
	set("outdoors", "land");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"b20",
  "northeast" : __DIR__"b12",
  "south" : __DIR__"b10",
 "northwest" :TMR_PAST"advbonze/hill1.c",
]));

	setup();
	replace_program(ROOM);
}
