// /d/ruzhou/ximen.c ���{���
inherit ROOM;

void create()
{
	set("short", "���{���");
	set("long", @LONG
�o���O���{���諰���C�q�o���O�q�V���h�����g�n�D�A�@����
�j�׵o�ͩάO�Ԩư_�ӡA�ߧY�|�b���]�d�L�d�A���ɡA�x�L�]�i�o�L
�Ӧh�ơA�����U�@���ӥ����@���H�C
LONG
	);

	set("exits", ([
		"west" : __DIR__"xi-yidao1",
                "east" : __DIR__"wangxi-lu",
	]));

        set("objects", ([
//                "/d/city/npc/wujiang" : 1,
//                "/d/city/npc/bing" : 3,
        ]));

	set("outdoors", "ruzhou");
	setup();
	replace_program(ROOM);
}



