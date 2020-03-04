// Room: /u/k/king/area/r6.c

inherit ROOM;

void create()
{
	set("short", "[1;31m�԰�[1;33m�ӳ�[2;37;0m-���k�߸�");
	set("long", @LONG
���F����[�A���F����h�L�͡A���O���o�@���S�����Y�A�|�P������
�S�O���򪺩��t�A���W���]���]���S���F�����������F�C�����ݥh�n����
�@�y���A�٬O�ֹ֧L�h�a�C

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"r7",
  "north" : __DIR__"r5",
]));
	set("world", "undefine");
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/child" : 2,
  __DIR__"npc/corpse" : 2,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
