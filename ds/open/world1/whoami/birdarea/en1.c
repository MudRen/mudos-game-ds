// Room: /open/world1/whoami/birdarea/en1.c

inherit ROOM;

void create()
{
	set("short", "[1;37m�F�_[0m�A�L");
	set("long", @LONG
�A�Ө�F�F�_�A�L���J�f�B�A�F�_�A�L����ԤQ������S��
��A�}�U���d�׽�_���P�P�n�n���A�|�P���������ᬰ���j�A
�\��F�j�����������C���F�_�V���Ӥp���i�H��`�F�_�A�L�̡C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "northeast" : __DIR__"en2",
]));
	set("outdoors", "forest");
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
