// Room: /open/world1/tmr/dragoncity/caodi7e.c

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
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"caodi8",
  "west" : __DIR__"caodi7",
]));
	set("current_light", 4);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
