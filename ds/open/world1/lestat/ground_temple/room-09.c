inherit ROOM;

void create()
{
        set( "short", "�a���������") ;
        set( "long", @LONG
�w�w���������n�ѤW�ӤU�ǨӡA�@����h�A�i�H�ݨ�a�����o�@
�������ѪšA�}���j�p�j���i�H���@�ӤH�q�L�A�Ѭ}������������
�ݡA�o�Ӭ}���G�O���H�G�N�}�w���A�i��O���F���u�@����]���l
���������q���ΡC
LONG
);
        set("exits", ([ /* sizeof() == 1 */
                  "north" : __DIR__"room-13",
        ]));
        set("objects",([
                   __DIR__"../npc/dark_zombie" : 2,
                 ]) );
        set("light",0);
        set("no_recall","�����������ϳ��B���F�Ҧ����ǰe�O�q�C");
        set("no_clean_up", 0);
        setup();
}

