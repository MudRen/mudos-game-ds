// Room: /u/s/slency/area/ugelan/church7.c

inherit ROOM;

void create()
{
	set("short", "�@���e�`�p�|");
	set("long", @LONG
�o�̬O�@�������@���e�e�`���p�|�A�o�̪����������O�͡A�ݨӤw
�A���ȫȷ|�즹�C���A�~�򩹪F�_���h�O�@�y�˪L�A���n�q�����h�H�s
���B�D�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"church8",
  "south" : __DIR__"church6",
]));
	set("no_clean_up", 0);
	set("outdoors", "forest");

	setup();
	replace_program(ROOM);
}
