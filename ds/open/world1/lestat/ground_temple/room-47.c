#include <path.h>
inherit ROOM;
void create()
{
	set( "short", "�o���q�|") ;
	set( "long", @LONG
��L�F�r����A�A�������u�u�a�Ө�F�@�Ӥs�}���A�ÿB���Ů�
�R����ӪŶ��A�O�H���T�ݤf�дe�A�J�Ӳ�ť�|�P���n���A���G���V
�V�������n���Ѥs�}�`�B�ǨӡC
LONG
);
        set("exits", ([ /* sizeof() == 3 */
                  "out" : ACME_PAST"bonze/b19",
                  "east" : __DIR__"room-48",
                  "south" : __DIR__"room-49",
        ]));
       set("objects",([
                   ALWAYS"torch" : 1,
                 ]) );
        set("light",0);
        set("no_clean_up", 0);
        setup();
}
