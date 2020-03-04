// Room: /open/world1/acme/area/f3.c

inherit ROOM;

void create()
{
	set("short", "���L");
	set("long", @LONG
�o�O���L���t�@�B�A�˪L���˦��@�f�s��H�A�j��M���˶��j�L
�ߡA���˲ʤj�A���짻���A����o�ۨ������p�A�b�G���������L�a�W
���M�o�{�ƭӸ}�L�A���O���~�A�ӬO�H���}�L�A�A�߸̤��T�Q�A�b�o
�ئa��A���|�X�{�H���}�L�A�G���ѦۥD������ĵı�C
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"f2",
  "west" : __DIR__"f4",
]));
     set("outdoors","land");

	setup();
	replace_program(ROOM);
}
