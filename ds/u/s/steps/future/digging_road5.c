// Room: /future/area/digging_road5.c

inherit ROOM;

void create()
{
	set("short", "�q�ϼo�K��");
	set("long", @LONG
�A���b�@���q�Ϫ��o�K���W�A�����¥@�ɴݯd�U�Ӫ����X���K���A��
�w���g�n�X�Q�~�A���M���G�p�s�A�w�o�Ӥ��ΡC���趶���K�����U�h�A�|
��F���q�ϡA���n�i�^���q�ϡC
LONG
	);
	set("world", "future");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"digging_road6",
  "south" : __DIR__"digging_road4",
]));
	set("outdoors", "desert");

	setup();
	replace_program(ROOM);
}
