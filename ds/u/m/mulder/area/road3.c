// Room: /u/m/mulder/area/road3.c

inherit ROOM;

void create()
{
	set("short", "�s���o�� - �s������");
	set("long", @LONG
�o�O�s���o�����s�����ߡA�A�i�H�b�o�ط����@�U�άݬݳo
��}�G�������D�V�F���i�H��o�س̥X�W���ʪ���R�@�ǪZ���A
�άO����A�]�i�b�o�س}��@�f�D�F�䦳�@���Ȧ�D
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"road6",
  "north" : __DIR__"road4",
  "south" : __DIR__"road2",
  "east" : __DIR__"road5",
]));
	set("no_clean_up", 0);
 set("outdoors","land");
set("light",5);
set("objects", ([ /* sizeof() == 1 */
 __DIR__"npc/obj/pot" : 1,
]));

	setup();
	replace_program(ROOM);
}
