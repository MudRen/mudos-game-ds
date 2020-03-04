// Room: /open/world1/tmr/advbonze/summit5.c

inherit ROOM;

void create()
{
	set("short", "�ⶳ�p��-���x��n��");
	set("long", @LONG
�A�����b�ⶳ�p���W��n�����@�B���x���A�b�A�e�褣���B�ѩ^�ۤ@
�L�u��N����ù�~�۹��v�A�b���e�ƨB�N�O�p�����V��A�a�W�n����`�A
�y�@��í�A�N�|�s�u�a�����L�U�s�h�C
LONG
	);
	set("current_light", 1);

	set("no_clean_up", 0);
	set("outdoors", "snow");
	set("exits", ([ /* sizeof() == 1 */
  "northeast" : __DIR__"summit1",
]));

	setup();
	replace_program(ROOM);
}
