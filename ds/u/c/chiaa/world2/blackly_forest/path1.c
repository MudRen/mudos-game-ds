//u/c/chiaa/world2/blackly_forest/path1.c

#include <path.h>    
inherit ROOM;
void create()
{
        set("short", "�p�|");
        set("long", @LONG
�o�O�@���ᤣ�������p�|,������U�i���L�ƨB���e,
�樫�䶡,�N���O�b��P�𤧶����Żئ樫,
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
     "south"  : __DIR__"trail1",   //�ծ|1
  
]));
       
            setup();
replace_program(ROOM);
}
