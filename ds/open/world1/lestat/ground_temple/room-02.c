inherit ROOM;

void create()
{
        set( "short", "�a���������") ;
        set( "long", @LONG
�n���e�������F�S���S�t���q�D�A�A�Ө�F�@�y���j���a�U����
�e���A���j�������[�W�P��Q�}�w���}�ޡA�u�����D�n�h�֪��H�O�~
�৹���A���A�����Ϋݦa�Q�i�h�ݬݡC
LONG
);
        set("exits", ([ /* sizeof() == 2 */
                  "up" : __DIR__"room-01",
                  "north" : __DIR__"room-03",
        ]));
        set("objects",([
                   __DIR__"../npc/s_guard" : 2,
                 ]) );
        set("light",0);
        set("no_recall","�����������ϳ��B���F�Ҧ����ǰe�O�q�C");
        set("no_clean_up", 0);
        setup();
}

