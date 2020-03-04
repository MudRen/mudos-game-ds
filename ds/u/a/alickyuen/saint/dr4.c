// Room: /u/a/alickyuen/area/dr4.c

inherit ROOM;

void create()
{
	set("short", "ST�CHospital�IHall");
	set("long", @LONG
�o�̬O��|���j��A�C�ѤH�ӤH���A�y�q�ܰ��C�A�ݨ��o�̦��ܦh�H
���b�@�Ʊƪ��y��W���ԿˤH�άO���ԥs�W�J���D��C���_�O�n�O�B�A��
����h�O��g�ǡC
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/mnurse" : 1,
]));
	set("world", "future");
	set("light", 1);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"dr23",
  "south" : __DIR__"dr3",
  "north" : __DIR__"dr5",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
