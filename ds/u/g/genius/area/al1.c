inherit ROOM;

void create()
{
set("short", "�R�����f");
        set("long", @LONG
�o�O�R�������J�f�A�b�A�������䦳�@����a�A�W���G���F�h���h����
�A��A�k����h�O�@�y���m�ʪ��A���A�j�������h�Ӱ��A�Ψӭ����o����
�˪L���ʺA�C�@�ǧ��h�ǳƨ��X���~�Ķ���ۣ�A�g�L�A�����ǡA��A�ˤ��a
�L���C�A�Pı��@���H�������𮧡C

LONG
        );
        set("exits", ([
     "east":__DIR__"al0",
     "southwest":__DIR__"al2",
]));

        set("objects", ([
        __DIR__"npc/girl" : 2,

]));
        set("outdoors","forest");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

