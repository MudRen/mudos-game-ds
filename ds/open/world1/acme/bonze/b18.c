// Room: /open/world1/acme/bonze/b18.c

inherit ROOM;

void create()
{
	set("short", "�s��");
	set("long", @LONG
�A���B�b�s�������A���e���s���I�m�A�p���F�_�A�a�\�t���A�|
�P�����W���p���A���դ���A�v���ڡA���O�@�B�s���u�����H
���P�ҡC
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"b19",
  "south" : __DIR__"b4",
]));
        set("outdoors","land");

	setup();
	replace_program(ROOM);
}
