// Room: /u/s/suez/grave/path_8.c

inherit ROOM;

void create()
{
	set("short", "�p�ۤs�|");
	set("long", @LONG

�p�ۤs�W��󭻡A���E�����~�ɶ��A���⭷��}�M�ġA�y�s�@�@��s�^�C
�p�۹M���s�|��A�M���`�زM�H���A���q�ư۫B�]��A�`���ٯ��s���P�C

�o�⭺�O�n�p�ۤs����H�g���A�N��b�s�D�Ǫ��۸O�W�A���ɤF�p�ۤs��
�p���m�R�A�M�s�y�H�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "westup" : __DIR__"path_7",
  "eastdown" : __DIR__"path_9",
]));
        set("outdoors", "land");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
