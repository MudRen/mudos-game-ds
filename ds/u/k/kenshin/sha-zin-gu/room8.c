// Room: /u/k/kenshin/sha-zin-gu/room8.c

inherit ROOM;

void create()
{
	set("short", "[1;32m�����s��[0m");
	set("long", @LONG
���줤���s����A�o�N�O�v�騦���~����`���y�ʩҦb�B�A�Pı
��~���������A���Hı�o���P�Ө즹�a�C���F���ݨ�\�h���a�p�G
�n�D������A�i�����䨫�h�C�����V�e���ܡA��ݨ�e�Z�L�֫L���
�M�b�����Z�ǰ^�m�Ať��a�~���ҥܡA�b���[���e����M�b��a�P
�}�F�@�����D�]�A�W���y�Z�Ǥ��a�z�A�����N���оɷ�a�Q�ߪZ�Ǥ�
�H�A�o�ص��ߡA�ѤU���u�O����ڡI
LONG
	);
	set("outdoors", "land");
	set("current_light", 2);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"room10",
  "east" : __DIR__"room9",
  "north" : __DIR__"room11",
  "south" : __DIR__"room7",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
