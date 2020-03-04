// Room: /u/a/alickyuen/area/dr16.c
// ��long
inherit ROOM;

void create()
{
	set("short", "ST�CHospital�ICorridor");
	set("long", @LONG
�A�Ө�F��|�T�Ӫ����ߡA�o�ئ��X�����i��C���F�O�@�Ưf�Ъ���
�b�a�A���O�q���оǫǡA�β{�ɳ̷s����ިӱоɤH�̤@�Ǫ��ѡA�ӷQ
����ͩΤ@�Ǥu�@�H�����n�h�n�䪺�u�@�ǡC
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/nurse" : 1,
]));
	set("world", "future");
	set("light", 1);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"dr27",
  "north" : __DIR__"dr15",
  "west" : __DIR__"dr25",
  "east" : __DIR__"dr17",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
