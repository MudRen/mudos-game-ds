inherit ROOM;

void create()
{
set("short","�p����");
        set("long", @LONG
�o�̪���ԤQ���A�X�حȤp���A���O�۹諸�o�̪��A�`�]���֡C�A�Ʀ�
�ݨ�s�_��H�W�������F�³��A���ͤ@�T�Q���ب몺�e���C
LONG
        );
       set("exits", ([
        "northwest":__DIR__"f00",
        "east":__DIR__"f11",
        "southeast":__DIR__"f20",
]));
        set("objects", ([
        __DIR__"npc/sparrow" :3,
]));

        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

