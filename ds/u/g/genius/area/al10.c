inherit ROOM;

void create()
{
set("short", "�R�����p��");
        set("long", @LONG
�o�̦����ø��@��������C���q�h�A����C���]�شӤF���֪����C�a
�A���L��ϱo��Ӥs��o�D�`��աA�O�H���T���j�۵M�ͥͤ������ͩR�P��
�@�ط��ת��_�١C���y��_���L�h�٥i�H�ݨ�@������������A��O���R
�D�`�A�O�H�Q���C
LONG
        );
        set("exits", ([
     "north":__DIR__"al11",
     "south":__DIR__"al9",
     "northwest":__DIR__"m1",
]));

        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

