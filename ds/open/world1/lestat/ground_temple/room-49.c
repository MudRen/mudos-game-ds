inherit ROOM;

void create()
{
        set( "short", "�o���q�|") ;
        set( "long", @LONG
�~�[���ת��q�|���A�ٴݯd�ۤ��֪��q�áA�̪���G�S���H�}�l
�}�ĳo���q���F�A�@��媺�q�u�Ө�o�̤u�@�A���o�Ӥw�g�o���q
�|�S�}�l���F�H��C
LONG
);
        set("exits", ([ /* sizeof() == 2 */
                  "east" : __DIR__"room-50",
                  "north" : __DIR__"room-47",
        ]));
        set("objects",([
                   __DIR__"../npc/mine_leader" : 1,
                 ]) );
        set("light",0);
        set("no_clean_up", 0);
        setup();
}

