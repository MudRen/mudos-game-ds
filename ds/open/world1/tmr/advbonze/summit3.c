// Room: /open/world1/tmr/advbonze/summit3.c

inherit ROOM;

void create()
{
	set("short", "�ⶳ�p��-���x��_��");
	set("long", @LONG
�A�����b�ⶳ�p���W��_�����@�B���x���A�b�A�e�褣���B�ѩ^�ۤ@
�L�u�j�O����ù�~�۹��v�A�b���e�ƨB�N�O�p�����V��A�a�W�n����`�A
�y�@��í�A�N�|�s�u�a�����L�U�s�h�C
LONG
	);
	set("outdoor", "snow");
	set("no_recall",1);
	set("current_light", 1);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "southeast" : __DIR__"summit1",
]));
	set("outdoors", "snow");

	setup();
	replace_program(ROOM);
}
