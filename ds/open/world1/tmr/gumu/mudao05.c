// Room: /open/world1/tmr/gumu/mudao05.c

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
	set("current_light", 1);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
//    "west" : __DIR__"qianting",
  "east" : __DIR__"mudao05_e",
]));

	setup();
	replace_program(ROOM);
}
