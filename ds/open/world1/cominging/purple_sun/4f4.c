// �����s�ĥ|�h

inherit ROOM;

void create()
{
	set("short", "�p�Ŧa�W");
	set("long", @LONG
�o�O�@�Ӥp�Ŧa�A�b�o�̦��ǰʪ��b�樫�A�b�A���|�P�O���p�Ŧa
�A�n�p�ߤ@�I�A���M�N�|�L�U�s�U�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"4f2.c",
]));
	set("world", "past");
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}
