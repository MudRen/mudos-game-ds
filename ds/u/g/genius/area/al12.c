 inherit ROOM;

void create()
{
set("short", "�R�����p��");
        set("long", @LONG
�o�̬O�R�����_�䪺�p���A�u�۳o�����L�h�N�i�H���W���䪺�C���C�o
�̦��ۤ��L�a���@��������A����@��A�٪���|�ؤF�@�������c�C
�o�����O�ѹA�٥D�H���k��Ӥߺ��@�g��Ӧ����A���ɦo�]�|�N�ۤv����
�����W��A�������֪��𮧡C
LONG
        );
        set("exits", ([
     "east":__DIR__"al13",
     "west":__DIR__"al11",
     "north":__DIR__"r7",
]));
        set("objects", ([
        __DIR__"npc/sellgirl" : 1,
]));
        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
