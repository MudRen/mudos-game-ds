// Room: /u/s/suez/grave/path_9.c

inherit ROOM;

void create()
{
	set("short", "�p�ۤs�U");
	set("long", @LONG
�e���@�Ӥp�C�A�Q�o���񪺤H�٤����p�ۤs�A�s���p�A�u���L��Ѧ�
�A�����h�A�p�����n�O�H�߷R�C���񪺧�������h�b�s�W�|��A���֤]�S
�Q��b�o�����������a�����p�������A���O�]�u���p�����������A�]�~��
�M�s�p�G�A�����ЬV�C
LONG
	);
	set("outdoors", "land");
	set("current_light", 2);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"path_10",
  "westup" : __DIR__"path_8",
]));
        set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
