// Room: /open/world1/tmr/gumu/mudao08_e2.c

inherit ROOM;

void create()
{
	set("short", "�ӹD");
	set("long", @LONG
�o���O�j�Ӥ����ӹD�A�|�P�K���z���A�ɵ��٤W���t���O���A�A��
�j�j����X��V�C�٬O�ξ�����C�۬�X�_�Ӫ��A���X�o�ƬO�����A��
�H�q����X�@���_�ءC�O���Ӧb�C�۾��W�A�{�{�ۺѫիժ����I�C
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 2);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"mudao08_e",
  "east" : __DIR__"mudao21",
]));

	setup();
	replace_program(ROOM);
}
