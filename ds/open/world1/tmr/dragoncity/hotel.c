// Room: /open/world1/tmr/dragoncity/hotel.c

inherit ROOM;

void create()
{
	set("short", "�Y�s�ȴ�");
	set("long", @LONG
�A�@���i�ӡA�N�D��@�ѯ����G�J�ߵʡA�믫�����@�n�C
�X�i�K�P��@�r�ƶ}�A�����F�ȤH�A�ΰ��n�ͽ׾ԧ��A�Υ��Y
���ժ�H�L�ȶդj�C�A�n�Q��ť����A���Ȥ��O�ɭԡC
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"hotel2f",
  "east" : __DIR__"north1",
]));
	set("no_clean_up", 0);
	set("no_fight", 1);
	set("light", 1);
	set("current_light", 2);
	set("valid_startroom", 1);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/waiter" : 1,
   __DIR__"npc/tao-sheng" : 1,
]));

	setup();
	replace_program(ROOM);
}
