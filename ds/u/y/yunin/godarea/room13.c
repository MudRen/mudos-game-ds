#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW"�D�׫�"NOR);
        set("long", @LONG
�@Ĳ�N�_�Ǫ����Y��A�ߧY�Ө�F�@�ӯ������a��A�o�̪��\�]
�۷�����A�k�W�誺����W���F�Ƨ���@�W�������A�A�߸̤@�Q
�A�o�@�ӤH�@�w�O�@�Ӧb����̬۷��a�쪺�H�C
LONG
        );
        
                set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"room15",
  "west"  : __DIR__"room14",
]));  
        set("no_clean_up", 0);
        setup();
}     

