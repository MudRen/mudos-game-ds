#include <ansi.h> 
inherit ROOM; 
void create() 
{
        set("short", "���H�P�}");
        set("long", @LONG
��ǪŵL�@���A�}�޳��ݰ{�{�o�G�A��ӬO�������դ����A�N
�o�̷Ӫ��@�{�@�{���A�a�W�y�ۮ����Ӥ��A�}�f�@�D�ե��N�o�̻P
�~�ɹj���A�ϱo�~�����e�����|����A�Φ��W�S���۵M���[�C

LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room3",  
  "leave" : "/open/world1/tmr/area/m_river",

]));
        set("no_clean_up", 0);

        setup();
}

