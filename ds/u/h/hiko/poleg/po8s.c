inherit ROOM;
void create()
{
        set("short", "�y�����K�K�E");        
set("long",@LONG
�o�̬O�y�������K�K�E�A��W�������O���K�������A�Ӥ]���H���I
�e���Pı�A�J�Ӥ@�ݭ�ӬO���K�����l���b�����N�ۡA�ӨI�������K�n
�]�����㪺�j���ۡA�]�i�H�Pı�X�Ӯv�Ū��O�q�ܨ��A���H�@�ثD�`
�M�~���Pı�C
LONG
        );
        set("exits", ([
  "north" : __DIR__"po8",
    "west" : __DIR__"po8s-w",
]));
set("objects", 
([__DIR__"npc/trainer" : 1,
        ]));
set("light",1);        
set("no_clean_up", 0);
        setup();
}






