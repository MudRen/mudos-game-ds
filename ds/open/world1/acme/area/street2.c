// Room: /u/a/acme/area/street2.c

inherit ROOM;

void create()
{
	set("short", "��D");
	set("long", @LONG
�o�O�@���ᬰ�e������D�A�H������B�������A�uť�۵�c�s���n
���_�����A�����۹L���H�s���ټM�n�A���T�O�H�ٹĦ��a���c�ءC����i
�X���A�_�䤣���B���@����Q�C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"wynd",
  "west" : __DIR__"wdoor",
  "east" : __DIR__"st",
]));
	set("no_clean_up", 0);
      set("outdoors","land");

	setup();
	replace_program(ROOM);
}
