// Room: /open/world1/tmr/north_bar/f10.c

inherit ROOM;

void create()
{
	set("short", "�d�~�j�}-�}��");
	set("long", @LONG
�b�o�̡A���~���q�s�n�ǹM�|�P�A�A�Pı�n���w�g�Q���~�]
��_�ӤF�C�|�P���M�·t�A���n�����ƹ���⪺�����o�b�c����
�������ۧA�A���A���T�}�l��򪺡C
LONG
	);
	set("objects", ([ ]));
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"f9",
  "southeast" : __DIR__"f12",
]));
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
