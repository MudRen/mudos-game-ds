inherit ROOM;

void create()
{
set("short", "�ѰO��Q");
set("long", @LONG
�o�O�@���ܤ[�ܤ[�H�e�N�s�b����Q, ��~�L�����{��
������, �N�O�o����Q�H�������ʶm�˪��]��, ���U�F�\�h��
�Ӫ��I��, �p�G�������骺�L��O�]�������骺�ѰO�]�����L
.
LONG
        );
set("exits", ([ "west" : __DIR__"seacoun6",
]));
set("objects", ([__DIR__ "npc/salesman2" : 1,
    ]));

set("room_type","shop");
set("no_clean_up", 0);
set("light",1);
setup();
}