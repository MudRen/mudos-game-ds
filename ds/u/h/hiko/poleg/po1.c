inherit ROOM;
void create()
{
        set("short", "�y�����n��");
        set("long",@LONG
�o�̤w�g�O�y�������F�A���̪��C�ӤH���H���Pı���Q�������O�A
�b�y�������ǰݩM���D�����S���Y�A���O��O�O���n���A�y�������C��
�H�q�p�N�n�ǲ߮����A�]���C�ӤH���O���W�����ҡA���ެO����λ��v
���������Q���״I�A�]��O�o�̪��W�����@�A�Ӯ����j�өҧ��a���Ш�
�����H�Pı����䭷���C
LONG
        );
        set("exits", ([
    "north" : __DIR__"po2",
    "south" : __DIR__"po0",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}


