// Room: /open/world1/dragoncity/caodi4.c

inherit ROOM;

void create()
{
	set("short", "���S���J-��a");
	set("long", @LONG
�o��O���S���J�s���~���j��a�A���_�i�H�樣�֫ӭx
�P��H�K��ڲצ~���Ԫ��D�n�Ԧa�ж��S���J�s���A���M�o
��S���b�I�Ԥ��A���|�g��^�o�O�R�����ݵ±�����C
LONG
	);
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"northgate2",
  "north" : __DIR__"caodi2",
]));
	set("current_light", 3);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
