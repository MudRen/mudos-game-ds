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
      set("item_desc",([
      "�_��H":"�o�O�@�Ӵݯ}���_��H�A�W���ٯ��F�X���³�\n",
      ]));
        set("exits", ([
        "west":__DIR__"f02",
        "southeast":__DIR__"f13",
]));
        set("objects", ([
        __DIR__"npc/sparrow" :2,
]));

        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


