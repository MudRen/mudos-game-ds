// Room: /open/world1/tmr/gumu/mudao21_s3.c

inherit ROOM;

void create()
{
	set("short", "[1;32m�ӹD[0m");
	set("long", @LONG
�o���O�j�Ӥ����ӹD�A�|�P�K���z���A�ɵ��٤W���t���O���A�A��
�j�j����X��V�C�٬O�ξ�����C�۬�X�_�Ӫ��A���X�o�ƬO�����A��
�H�q����X�@���_�ءC�O���Ӧb�C�۾��W�A�{�{�ۺѫիժ����I�C
LONG
	);
	set("current_light", 5);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"mudao21_s4",
  "north" : __DIR__"mudao21_s2",
]));

	setup();
	replace_program(ROOM);
}
