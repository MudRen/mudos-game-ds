//u/t/tqc/world1/blackly_forest/nivi_vacancy.c
#include <ansi.h>

inherit ROOM;
void create()
{
        set("short", "�Ŧa");
        set("long", @LONG
�o�̬O�Ԫ̧��F�䪺�@�p���Ŧa,
�|�P�����V�m��d�U������,�����O��H��!!
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  
   "northwest"  : __DIR__"parade3",      //�V�m��3
 
 ]));
       
        setup();
replace_program(ROOM);
}

