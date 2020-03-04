// Room: /u/m/matlab/workroom.c

inherit ROOM;

void create()
{
	set("short", "[1;36m�ѯ�C�c[2;37;0m");
	set("long", @LONG
�o�O�ѯ�|���m�C�H�䪺�a��A�@���O�p���a���R�w�ԡA�u��b�o�˪��^����
�A�Pı�줭�x���P���ƥH���p�a�F�Ӱ_�ӡA�|�P���\�]�Q���a²�����A�u�O��W
�β`�βL���C���o�ϧA�j���_��A�C�������z�۵��C�⪺�C��[�[�����A���A�y��
�ٷV�R�q���ߡC
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/1.c" : 1,
]));
	set("no_magic", 1);
	set("no_fingt", 0);
	set("connect", "/open/world1/tmr/area/hotel.c");
	set("exits", ([ /* sizeof() == 3 */
  "meet" : "/d/wiz/entrance",
  "pass" : "/open/world1/tmr/area/hotel.c",
  "area" : __DIR__"area/entrance.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
