// Room: /u/s/suez/grave/path_1.c

inherit ROOM;

void create()
{
	set("short", "���F��");
	set("long", @LONG
��Ǿ𽮧߲��A�M���j���A�n�@�ӲM�R�h�B�C�����B���G���ӳ��F�A
�F�l�ߩ�s�V��A�~���{�U�A�����D�O���Ӱ��H�h�h���~���ҫءA��
���_���ʡA��v�C�P�ɡA�o�ӳ��F�u�p��ѦӰ_�A�O�H�����ѤW�H���C
LONG
	);
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"path_0",
  "east" : __DIR__"path_2",
  "northup" : __DIR__"kiosk",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
