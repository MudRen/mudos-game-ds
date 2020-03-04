// Room: /open/world1/tmr/north_bar/f20.c

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
  __DIR__"npc/dinosaur1.c" : 5,
  __DIR__"npc/dinosaur2.c" : 5,
  __DIR__"npc/dinosaur3.c" : 5,
  __DIR__"npc/mucus-odd.c" : 5,
]));
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"f19",
]));
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
