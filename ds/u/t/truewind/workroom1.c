// Room: /u/t/truewind/workroom1.c

inherit ROOM;

void create()
{
	set("short", "[1;37m��L�V[0m");
	set("long", @LONG
���B�O�_�V�n�誺�@���Ŧa�AĲ�ةҤκɬO�սJ�J�����H�A�P��
�Q�s������A���ӷ|�����Ͱʪ��g�L�C�b�d��U�����p�D�W�̵}�i�H
�ݨ�@�Ǥj�j�p�p���}�L�M�_�����Q��K�C
LONG
	);
	set("outdoors", "land");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"workroom",
  "south" : "/u/t/truewind/Minetown/area/minetown",
]));
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}
