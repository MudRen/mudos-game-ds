inherit ROOM;

void create()
{
	set("short", "�s�}�U");
	set("long", @LONG
�A�{�b�b�����s���s�}�U���A�b�o�̦��Ǫ��A�n�����ǥi�H����
���{����A���L�A�o�����{�o�A�A�{�b�٦b��¶�s���˪L�����A���L
�b�A���e���o�O�@�y�~�k���s�C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"psin3.c",
  "west" : __DIR__"psin5.c",
  "east" : __DIR__"psin2.c",
]));
	set("objects", ([
  __DIR__"npc/passenger.c" : 1
]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	set("item_desc", ([
  "���" : "�@�ǳ��ͪ����, ���b���䪺����W. \n",
]));
	setup();
	replace_program(ROOM);
}