inherit ROOM;
void create()
{
        set("short", "�y�����F��");        
        set("long",@LONG
�o�̬O�y�����s�����F������D�A�A���F�䨫�h�K�O�����[�F�Ať
���̪�������F�Y�ƥ��۫�ۡA�]���o�b��H�����A�]�\����H�̩Ҭy
�Ǫ��Ʀ����A�p�G�Q���D�ԲӪ��ܡA���N���F��h���X�ݬݧa�C
LONG
        );

set("objects", 
   ([__DIR__ "npc/in-chen" : 1,
    ]));
set("exits", ([  
"east" : __DIR__"po17",
"west" : __DIR__"po16",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}







