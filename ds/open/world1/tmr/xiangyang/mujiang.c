// Room: /d/xiangyang/mujiang.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "��K�Q");
	set("long", @LONG
�o�O�@�a²������K�Q�A�@�Ӥ��~��K���ۦb�a�W�v�F��C
�Ȧ��å@�A��K�̤]�u�n��@�ǤM�j�ҴΤ��򪺥H�i�a�k�f�C
�a�W�M�𨤭�æa���ۤ@�Ǥ�C�A��M�A��Ҥ��򪺡A�٦�
�X�󹳿��l�A�S�l�@������K�u��C
LONG );
	set("exits", ([
		"north" : __DIR__"eastjie3",
	]));
	set("objects", ([
//         __DIR__"npc/mujiang" : 1,
	]));
	set("coor/x", -470);
	set("coor/y", -520);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
