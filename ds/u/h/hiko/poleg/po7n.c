inherit ROOM;
void create()
{
        set("short", "�y�����S����");        
        set("long",@LONG
�o�̬O�y�������S�����A�ݰ_�ӤQ�����A�\�h�C�ȨӦ������b��
���ʯS���A�]���檺�W�n�]�⤣���A�̭��檺�F��M���~���O�ݩ�y��
�����S���O�a��O�R���쪺�A�]���ͷN�٤����A�����D�H�h�O�@�y����
�A���۩��p���˻��C
LONG
        );
set("exits", ([
  "south" : __DIR__"po7",
]));
set("objects", ([__DIR__ "npc/jang-sha" : 1,
    ]));
        set("light",1);
        set("no_clean_up", 0);
        setup();
}








