#include <ansi.h> 
inherit ROOM; 
void create() 
{
        set("short", "���H�P�}");
        set("long", @LONG
�a��U���A�a�U�����k�`�z�P���_�A�J��X�L�Ʀa�}�A�M�G�i
���A�j�����e���`�q�o�̬y���A�B�y�����t�׫ܧ֡C
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room7",  
  "north" : __DIR__"room3",
])); 
        set("objects", ([ /* sizeof() == 1 */
 __DIR__"npc/la-ah" : 1,
]));
        set("no_clean_up", 0);

        setup();
}

