// Room: /u/s/sub/area/village/vi05.c

inherit ROOM;

void create()
{
	set("short", "�H�ۤp��");
	set("long", @LONG
�o�O�@���e��p�������n�_�V�D���C�ⰼ���ɦa�ǨӺV�����ݪ�����
�n�A�Ϲ��R����D�W�h�F�ǳ\���پx�C���T���H�P��n�_�A���D�o���R��
�p�����ٻݭn�˳ơH����O�@���Z�����A�F��O�@�����㩱�C
LONG
	);
	set("world", "undefine");
	set("no_clean_up", 0);
	set("outdoors", "land");
	set("current_light", 2);
	set("exits", ([ /* sizeof() == 4 */
"east" : __DIR__"vi09",
  "north" : __DIR__"vi06",
  "west" : __DIR__"wproom",
  "south" : __DIR__"vi04",
]));

	setup();
	replace_program(ROOM);
}
