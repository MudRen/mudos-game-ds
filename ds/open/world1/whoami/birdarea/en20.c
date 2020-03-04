// Room: /open/world1/whoami/birdarea/en20.c

inherit ROOM;

void create()
{
	set("short", "[1;37m�F�_[0m�A�L");
	set("long", @LONG
�A�{�b�Ө�F�_�A�L���`�B�A�o����S������F��A�u����
�Ǫ����O�A�M���W���X�ڤp��A�e��ݰ_�Ӫh��ܭ��A�i��֨�
�h�A�a�a�F�A�o�����@�����F�詵���U�h�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"en21",
  "west" : __DIR__"en19",
]));
	set("outdoors", "forest");
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
