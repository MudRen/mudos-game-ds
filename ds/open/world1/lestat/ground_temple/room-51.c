inherit ROOM;

void create()
{
        set( "short", "�o���q�|") ;
        set( "long", @LONG
�p�L�F�p�p���q�D��A�A�Ө�F�q�|���`�B�A�U�観�@�Ӭ}�ޥi
�H�~�򩹤������A���Oť�F��診�Ӧ��q�u�����ܡA�A�߸�ı�o���
���A���G�P��U��}�޶ǨӤ@�ѳ��˴˪��Pı�C
LONG
);
        set("exits", ([ /* sizeof() == 2 */
                  "down" : __DIR__"room-33",
                  "north" : __DIR__"room-50",
        ]));
        set("light",0);
        set("no_clean_up", 0);
        setup();
}

