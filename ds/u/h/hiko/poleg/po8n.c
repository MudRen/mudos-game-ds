inherit ROOM;

void create()
{
set("short", "��i��Q");
set("long", @LONG
�o�̬O�y���������@�a���E�A�J�Ӥ@�ݤ]�Z�¤F�A�ݱo�X�Ӥw�g��
�۷�~�N�Ať���O�g��F�\�h�N�F�A�ӷ�Q�D�H�]�O�D�`���g�����A��
�L�ѩ���椽�D�]���H�̤]�Z�ַN�M�L���ͷN�A��O�y�������@�Ӧѩ�
�F�C
LONG
        );
set("exits", ([ 
    "south" : __DIR__"po8",
]));
set("objects", ([__DIR__ "npc/sellsman" : 1,
    ]));

set("room_type","shop");
set("no_clean_up", 0);
set("light",1);
setup();
}


