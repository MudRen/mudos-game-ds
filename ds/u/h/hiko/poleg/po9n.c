inherit ROOM;
void create()
{
        set("short", "�y����������");        
        set("long",@LONG
�o�̬O�y�������������A�ﭱ�ǨӤ@�}���{���A�\�h�C�ȨӦ�����
�O�]���n�Ӧ����s�A�����j�֦��[�A�]���ͷN�Q�������A�̭��檺����
���O�q���|���ҭ̭�W���K�e�Ӫ��A�ҥH�~��s�A�A�ӥ�O�@�Ӧ�Ź��
�R�Ӫ��a��A���Ť����ݬݡC
LONG
        );

set("objects", 
([__DIR__ "npc/fish-seller" : 1,
    ]));
set("exits", ([
  "south" : __DIR__"po9",
]));
        set("light",1);
        set("no_clean_up", 0);
        setup();
}








