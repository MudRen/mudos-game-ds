// Room: /u/s/slency/area/ugelan/farm2.c

inherit ROOM;

void create()
{
	set("short", "�վB�����~������");
	set("long", 
"�o�̬O�վB�����~���ݪ�����A�ѪŤ������ۥ��O��A�@�����M��\n""�𮧨ϧA���߱��κZ�F���֡A���A�̶ԧ֦a�ѺصۡA�N�n���O�B�b���\n""�����A�۵��ۨ��A�L�~�L�{�C\n"

	);

	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"farm4",
  "west" : __DIR__"farm1",
]));
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
 __DIR__"npc/cow" : 3,
]));
	set("no_clean_up", 0);
	set("outdoors", "land");
	setup();
	replace_program(ROOM);
}
