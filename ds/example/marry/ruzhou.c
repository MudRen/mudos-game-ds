
inherit ROOM;

void create()
{
	set("short", "���{��");
	set("long", @LONG
���{���O�������j���A�ߨӬO�L�a�������a�C�G�{�v�b���n�㭫
�L�A�L�d�n�ӥ_������H�A�}�t�d��������s�W����F�C�Ѥ_�o���O
�_�W�ʫ������g���D�A�x�L�L�d�]�Q���Y��C�q�o���V��X�����A�i
�H�줭���������C�s�F�C
LONG
	);

	set("exits", ([
		"south" : __DIR__"xiaozheng",
      "north" : __DIR__"yidao2",
		"west" : __DIR__"wangxi-lu",
		"east" : __DIR__"hong-damen",
	]));

        set("objects", ([
                "/d/city/npc/wujiang" : 1,
                "/d/city/npc/bing" : 3,
        ]));

	set("outdoors", "ruzhou");
	setup();
	replace_program(ROOM);
}



