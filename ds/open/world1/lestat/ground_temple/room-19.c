inherit ROOM;

void create()
{
        set( "short", "�a���������") ;
        set( "long", @LONG
�Ө�o�̡A�A�������ѱo�����@�G�A�b�a�U�g�c���A�~�M�٦��o
�ˤ@�Ӧa��A���W�����F�@�T�T���W�e�A�ж����\�]�۷�j���u���A
�U�ئW�Q���j�����G�b�|�P�C
LONG
);
        set("exits", ([ /* sizeof() == 1 */
                  "east" : __DIR__"room-20",
        ]));
        set("objects",([
                   __DIR__"../npc/hong" : 1,
                 ]) );
        set("light",0);
        set("no_recall","�����������ϳ��B���F�Ҧ����ǰe�O�q�C");
        set("no_clean_up", 0);
        setup();
}

