// Room: /open/world1/tmr/dragoncity/caodi7.c

inherit ROOM;

void create()
{
	set("short", "���S���J-��a");
	set("long", @LONG
�o��O���S���J�s���~���j��a�A���_�i�H�樣�֫ӭx
�P��H�K��ڲצ~���Ԫ��D�n�Ԧa�ж��S���J�s���A���M�o
��S���b�I�Ԥ��A���|�g��^�o�O�R�����ݵ±�����C�q�o
�੹��O�@�B�W�s���s�D�A�ө���_�����L�h�A�i����@�B
�j���C
LONG
	);
	set("outdoors", "land");
	set("current_light", 5);
	set("exits", ([ /* sizeof() == 4 */
  "northwest" : __DIR__"caodi9",
  "south" : __DIR__"caodi6",
  "east" : __DIR__"caodi7e",
  "west" : "/open/world1/manto/pudu_mountain/way01",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
