inherit ROOM;
inherit DOOR;
#include <room.h>
#include <ansi.h>

void create()
{

   set ("short", HIM"�ѧ��s�}"NOR) ;
   set ("long", "�o�̴N�O�ѧ��s�}�A�۶Ǧ����ѧ��Q�j���ʦL�b��...�a�W���G�����t���E\n") ;
;
        set("exits", ([ /* sizeof() == 3 */
                    "east":__DIR__"infinite9.c",
                    "down":__DIR__"skyevil1.c",
]) ) ;

















       

        set("no_clean_up", 0);
        set("light", -1); 
        set("objects",([
                   __DIR__"guardwolf" : 1,
                 ]) );

        setup();
create_door("down",HIM"�ѧ���"NOR,"up",DOOR_LOCKED,"skyevilkey");
}



















