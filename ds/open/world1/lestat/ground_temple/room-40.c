#include <ansi.h>
inherit ROOM;

void create()
{
        set( "short", HIR"����g��}"NOR) ;
        set( "long", @LONG
�i�J�o�̫�A�A�o�{�A�g���F�I�|�P�����H�@�����_�ܤơA���A
�����D�A���b��B�A�s�i�Ӯɪ��J�f�������F�A�p�G�@���䤣�����}
�o�̪����A�A�i��o�b�o��ݤ@���l�F�C
LONG
);
        set("hide_exits", ([ /* sizeof() == 6 */
                  "east" : __DIR__"room-38",
                  "west" : __DIR__"room-39",
                  "north" : __DIR__"room-43",
                  "south" : __DIR__"room-37",
                  "northwest" : __DIR__"room-42",
                  "southwest" : __DIR__"room-36",
        ]));
        set("light",0);
        set("no_map",1);
        set("no_clean_up", 0);
        setup();
}