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
                  "west" : __DIR__"room-47",
                  "south" : __DIR__"room-50",
        ]));
        set("objects",([
                   __DIR__"../npc/mine_worker" : 3,
                 ]) );
        set("light",0);
        set("no_clean_up", 0);
        setup();
}
