#include <ansi.h> 
inherit ROOM; 
void create() 
{
        set("short", "���H�P�}");
        set("long", @LONG
�}�޸̶��������@���A�i�O�A�Pı�줣�ɪ������~�I�S�ӹL�A
�w���@�ݡA��ӳo�¦ⴺ�H���O�}�޳y�����A�ӬO�}�ޤW�诸���F
�ƥH�U�p���j���C
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"room5",
  "south" : __DIR__"room9",
]));
        set("no_clean_up", 0);

        setup();
}

