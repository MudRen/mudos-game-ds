inherit ROOM;

void create()
{
set("short","�p����");
        set("long", @LONG
�o�O�R�����n�䪺���СA�񲴱�h������O�A�Ҩ��ԯѧ@�����G�C�o��
���A�@�O���~�L�𪺡A�b��Եy�L�H�N���V�u�A�o�̤]�|�شӤ@�ǥɸ�����
�����@���C
LONG
        );
        set("exits", ([
        "northeast":__DIR__"al5",
        "east":__DIR__"f01",
        "southeast":__DIR__"f10",
]));
        set("objects", ([
        __DIR__"npc/sparrow" :4,
]));

        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


