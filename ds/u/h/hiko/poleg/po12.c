inherit ROOM;
void create()
{
        set("short", "�y��������");        
        set("long",@LONG
�o�̬O�y�����s���_���A�ѩ��ݩ󤺰��ݰ_�ӤH���֡A���`�O���|
���H�ӳo�̪��A�ݰ_�ӤQ�����N�M�A�ߤW���a���H��D���Pı�A�ҥH��
�H�̩]�߬ҳ��Q���֨즹�a�Ať�����ӷ|���H�b���E�|�C
LONG
        );
        set("exits", ([  
"south" : __DIR__"po11",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}








