// Room: /open/world1/tmr/gumu/mudao21_s4.c

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
	set("no_clean_up", 0);
	set("current_light", 6);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"mudao21_s3.c",
  "south" : __DIR__"mudao12",
]));

	setup();
	replace_program(ROOM);
}
