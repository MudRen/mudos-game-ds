#include <ansi.h>
inherit ROOM;

void create()
{
        set( "short", "�a���}��") ;
        set( "long", @LONG
�n���e�����X�F�i�Ȫ�����g��}�A�k���F����c�����l���A�A
�Ө�F�@�������Ӽe�諸�q�D�A�V�_�䩵���ӥh���q�D�A�X�G�ݤ���
���Y�A���O�@�}�}�j�P���]�k�i�ʡA�o�@�����������a�ǨӡC
LONG
);
        set("exits", ([ /* sizeof() == 2 */
                  "north" : __DIR__"room-45",
                  "south" : __DIR__"room-42",                  
        ]));
        set("objects",([
                   __DIR__"../npc/s_soldier" : 2,
                 ]) );
        set("light",0);
        set("no_map",1);
        set("no_clean_up", 0);
        setup();
}
