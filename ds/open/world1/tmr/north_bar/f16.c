// Room: /open/world1/tmr/north_bar/f16.c

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
  __DIR__"npc/dinosaur1.c" : 2,
  __DIR__"npc/dinosaur2.c" : 2,
  __DIR__"npc/mucus-odd.c" : 2,
]));
	set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"f5",
  "east" : __DIR__"f17",
  "southeast" : __DIR__"f13",
  "west" : __DIR__"f15",
]));
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
