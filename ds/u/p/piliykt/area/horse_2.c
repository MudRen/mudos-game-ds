inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�o�̬O�����j��, �b���f�W�観�Ӱ��B, �b�����j�����G�ǦU���F��
�Ӧu��, �b�������|�B���Q���𵹥]�F�_��, ���H�@�د����P, ���A�ܷQ
�i�J�����@�ݴN��. 
LONG
);
set("light",1);
set("exits", ([ 
               "out" : __DIR__"road_4.c", 
               "north" : __DIR__"aa_1.c.c",     

]));
set("objects",([
__DIR__"npc/guard_1.c" : 2,
       ]) );

        set("no_clean_up", 0);

setup();
}   
int valid_leave(object me, string dir)
{
       if( dir=="out" && !userp(me) )
                return notify_fail("���̥u�����a�~��i�h�C\n");
        return ::valid_leave(me, dir);
}


