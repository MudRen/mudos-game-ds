inherit ROOM;
void create()
{
        set("short", "�y������D");        
        set("long",@LONG
�o�̬O�y�����s���n������D�A�ӥ|�P���O�@�ǥ��v�A�ݰ_�Ӧ��G
�S������_�����B�A���L���ɥ��R�]�O�t�åȾ����Ať���H���o�̪���
�`�`�ߤW���ۤ@�ǩ_�Ǫ��n���A�Pı�_�ӳz�S�����C
LONG
        );
        set("exits", ([  
"south" : __DIR__"po13-1",
"north" : __DIR__"po10",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}








