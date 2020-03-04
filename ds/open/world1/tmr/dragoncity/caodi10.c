// Room: /open/world1/tmr/dragoncity/caodi10.c

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
	set("current_light", 5);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"caodi11",
  "southeast" : __DIR__"caodi9",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
