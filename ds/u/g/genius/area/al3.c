inherit ROOM;

void create()
{
set("short", "�R�����p��");
        set("long", @LONG
�o�O�@���d�g���A�A���䳣�O�A�١A�X�G���O�ά��j�˰t�W�Ǫd�ػ\��
���C�o�̪��Ǫd�D�`�W�S�A�O�ΨF�l�V�W���z�B�����M���i���A���F����K
�����۷��w���Ǫd�A�ӥB�����䩵�i�ʡC���B�F�n�䨺���A�٫K�O������
��ΡA�]�\�i�H�e�h��ť�����C
LONG
        );
        set("exits", ([
     "north":__DIR__"al2",
     "south":__DIR__"al4",
     "east":__DIR__"r1",
]));
        set("objects", ([
        __DIR__"npc/dog" : 1,
]));


        set("outdoors","land"); 
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
