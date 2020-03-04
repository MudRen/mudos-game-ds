// Room: /future/area/digging_road4.c

inherit ROOM;

void create()
{
	set("short", "�q�ϹD��");
	set("long", @LONG
�A�����b�q�Ϫ��@���D���A�D���G�ǺɬO�o���K��B�J�ѡA��o��
©��ż�A�Ů�]�j���ۤ@�Ѫ��ݪ����D�A���n�����B�����s�]�A���_����
�F���V���o���K���A�i�����K����F���q�ϡC
LONG
	);
	set("world", "future");
	set("no_clean_up", 0);
	set("outdoors", "desert");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"digging_road5",
  "south" : __DIR__"digging_road1",
]));

	setup();
	replace_program(ROOM);
}
