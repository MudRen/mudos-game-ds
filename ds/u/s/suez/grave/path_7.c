// Room: /u/s/suez/grave/path_7.c

inherit ROOM;

void create()
{
	set("short", "�p�ۤs�q");
	set("long", @LONG
�b�s�q�W�ؤF�X��j�Q�A���F�@�B�D�F�A�F���E���F��T���H���b
�͸ֽ׽�A�Q�U�h�S�O�t�@�f����A�X�Ӧ��򻨫ȧu�s���q�A���M�P�a��
�P�ߡA���O�b�o�p���m�R���p�ۤs�q�W�A�o�O���@�f�M�Ӯ���C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "westdown" : __DIR__"path_6",
  "eastdown" : __DIR__"path_8",
]));
        set("outdoors", "land");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
