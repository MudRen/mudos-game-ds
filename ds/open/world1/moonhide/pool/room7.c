#include <ansi.h> 
inherit ROOM; 
void create() 
{
        set("short", "���H�P�}");
        set("long", @LONG
�}�����_�w�U�Ӫ����A�C�@�w���d�U�F�@�I��ѥۡA�]���ѤF
�ۦǥۡA�C�C�ֿn�����B�W�@�˪��a�����ۡA���o�ش��[�A�ܤ֭n
�n�X�ʦ~�~��Φ��C
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"room10",  
  "east" : __DIR__"room4",
  "north" : __DIR__"room6",
])); 
        set("objects", ([ /* sizeof() == 1 */
 __DIR__"npc/bu-la-fish" : 1, 
]));
        set("no_clean_up", 0);

        setup();
}

