#include <ansi.h>#
inherit ROOM;

void create()
{
        
        set ("short",HIR"��ù�g�}"NOR);
        set ("long", @LONG
�o�̬O�Ѭɩҳ]�U�����}�A���}�O���F�������h�������H�i�X�A
�Q�L���}�A�u�n�߸̵L�b�I�����M���h���ߪ��H�A�V�O�����@�w��q
�L���}���C
LONG

);
set("hide_exits", ([ /* sizeof() == 6 */
                  "east" : __DIR__"room9",
                  "west" : __DIR__"room4",
                  "north" : __DIR__"room1",
                  "northwest" : __DIR__"room11", 
                  "south" : __DIR__"room2",
"southeast" : __DIR__"room6",
"northeastup" : __DIR__"room7",                                          
     ]));
        set("light",0);
        set("no_map",1);
        set("no_clean_up", 0);
setup();
}

