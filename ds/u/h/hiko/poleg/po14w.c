inherit ROOM;
void create()
{
        set("short", "�y�������v");        
        set("long",@LONG
�o�̬O�y�������@�����v�A���ۤ@�Ǥ��Y���㪺���D�A�ѩ����
��A�]���`�`�Фl���|����A���L�o�̪�����Ů�o�Q���s�A�A�ӥB�~
�����Q���n�ȡA�p�G���ݭn�i�H�V�L�̭ɩж��A�o�]�O�������@�Ӧ���
���B�C
LONG
        );

set("objects", 
([__DIR__ "npc/bou" : 1,
    ]));
set("exits", ([
  "east" : __DIR__"po14",
]));
        set("light",1);
        set("no_clean_up", 0);
        setup();
}








