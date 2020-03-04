// Room: /open/world1/tmr/north_bar/town2.c

inherit ROOM;

void create()
{
	set("short", "�_�Z��-���f");
	set("long", @LONG
��A���}��i�j���ɡA�`�l�@�f��A�믫��M�n�F�_�ӡA�o
�̪��Ů�u�O�s�A�C�A�|�B�i��A�oı�o�̪��H�Q��������n��
�A�ݫȤ]�Q�������A�o��H�̩Ҭ�A���A�]����A�ͥ��Ҩ�����
�����@�ˡC
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"town1",
  "north" : __DIR__"town3",
]));
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
