//Room: /d/ruzhou/wangxi-lu.c
// llm /99/07/

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����W����k�A�ۦ��X���{���諰���A�K�O��W��h�~���A��
����_���j���F�C�_���N�O���{���������Ū��A���M���g���\��µ�A
���O�����������������o��{�X�@�f��[���Y�¿p���Pı�C�F�h�O
���{�����ߡA�o���]�S�����\���Q�C
LONG
	);

	set("exits", ([
      "north" : __DIR__"yamen-damen",
		"west" : __DIR__"ximen",
		"east" : __DIR__"ruzhou",
	]));

        set("objects", ([
        ]));

	set("outdoors", "ruzhou");
	setup();
	replace_program(ROOM);
}



