// Room: /open/world1/tmr/gumu/mudao09w3.c

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
	set("current_light", 2);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"mudao09w4",
  "east" : __DIR__"mudao09w2",
]));

	setup();
	replace_program(ROOM);
}
