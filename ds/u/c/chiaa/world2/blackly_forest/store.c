//u/c/chiaa/world2/blackly_forest/store.c
#include <ansi.h>
inherit ROOM;


void create ()
{
  set("short", "�ө�");
  set("long", @LONG
�o�̬O�Ԫ̧��H�̶R�F�誺�a��,�]�O���h�H���a��!
�Ԫ̧�������j�����O�ѳo�̴��Ѫ�!
LONG
        );
        set("no_fight", 1);         //�ж����T��@�԰ϰ�
        set("no_magic", 1);         //�ж����T��I�k�ϰ�
        set("no_die", 1);
  set("exits", ([ /* sizeof() == 1 */
  
   "east"  : __DIR__"nivi_road3",       //�ԧ��D��3 
   ]));

setup();
replace_program(ROOM);
}
