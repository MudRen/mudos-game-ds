// Room: /d/xiangyang/chaguan.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "���]");
	set("long", @LONG
�A�@���i�ӡA�N�D��@�ѯ����G�J�ߵʡA�믫�����@�n�C
�X�i�K�P��@�r�ƶ}�A�����F�ȤH�A�ΰ��n�ͽ׾ԧ��A�Υ��Y
���դ��L�դj�C�A�n�Q��ť����A���Ȥ��O�ɭԡC
LONG );
	set("resource/water", 1);
	set("no_clean_up", 0);
	set("exits", ([
		"west" : __DIR__"northjie",
	]));
	set("coor/x", -500);
	set("coor/y", -460);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}