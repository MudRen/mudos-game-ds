// Room: /open/world1/tmr/north_bar/f9.c

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
	set("objects", ([ /* sizeof() == 1 */
    __DIR__"npc/dinosaur1.c" : 4,
  __DIR__"npc/dinosaur2.c" : 1,
  __DIR__"npc/dinosaur3.c" : 1,
]));
	set("exits", ([ /* sizeof() == 5 */
  "northeast" : __DIR__"f14",
  "southwest" : __DIR__"f10",
  "north" : __DIR__"f8",
  "southeast" : __DIR__"f11",
  "northwest" : __DIR__"f13",
]));
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
