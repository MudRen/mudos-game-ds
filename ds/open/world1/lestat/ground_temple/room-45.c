inherit ROOM;

void create()
{
        set( "short", "�a���}��") ;
        set( "long", @LONG
���j���q�D���A�Ѥ@��������^������Ӧ����a�O�W�A���ƥB�M
��A���O��^���a�O�����_�o�ǨӰ}�}�G��A�ثe�i�H�T�w���O�A�q
�D�����Y���ӴN�O�o�Ӧa���}�ު��u�۩Ҧb�A�ѳo�˳W�Ҫ��H�y�q�D
�ӬݡA�e�����Ӧ��۷��j���ؿv�C
LONG
);
        set("exits", ([ /* sizeof() == 2 */
                  "north" : __DIR__"room-46",
                  "south" : __DIR__"room-44",
        ]));
        set("light",0);
        set("no_clean_up", 0);
        setup();
}
