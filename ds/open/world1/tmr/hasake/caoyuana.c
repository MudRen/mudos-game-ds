// Room: /open/world1/tmr/hasake/caoyuana.c

inherit ROOM;

void create()
{
	set("short", "�����t");
	set("long", @LONG
�o�̬O�j���M�F�z���[���a�A�C��ѵ}�ܱK�A�V����������ӥh�C
�a�W���X���d�m��L����L�A�ݼˤl�o�̱`�`���Ӷ��ө��C��n��n����
�Ǫ��ϡC
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 1);
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"caoyuan9",
]));

	setup();
	replace_program(ROOM);
}
