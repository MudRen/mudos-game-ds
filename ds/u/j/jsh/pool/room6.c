#include <ansi.h> 
inherit ROOM; 
void create() 
{
        set("short", "���H�P�}");
        set("long", @LONG
�I���q���誺���J��}�̪��Ů�A�K�}�l�]�o�A���ѥۦǩ��K
�H�]�o�����@�I�@�w�a�I�n���d�ܸU�ƪ��_�p�ǥۡA�W�K�F�}�޸�
���������P�C
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"room9",  
  "south" : __DIR__"room7",
  "east" : __DIR__"room3",
  "north" : __DIR__"room5",
]));
        set("no_clean_up", 0);

        setup();
}


