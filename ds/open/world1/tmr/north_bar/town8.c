// Room: /open/world1/tmr/north_bar/town8.c

inherit ROOM;

void create()
{
	set("short", "�_�Z��-�۾��D��");
	set("long", @LONG
�o�̫e�����@���J���q���e��A����Ǫ��۾����q�J�ѡA��
�o�o���p���ݰ_�ӤQ�����U���A�ӥB�o�̪���]�}�l�S�������
�H�A�[�W���S�j���j�A�߸̤��T���I��򪺡C
LONG
	);
	set("objects", ([ ]));
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"town7",
  "north" : __DIR__"town9",
]));
	set("no_clean_up", 0);
	set("shrot", "�_�Z��-�۾��D��");
	set("outdoors", "land");
	set("current_light", 2);

	setup();
	replace_program(ROOM);
}
