#include <ansi.h>
inherit ROOM;
void create()
{
                 set("short",HIY"���B��"NOR);

                 set("long", 
HIC"�o�̬O�����B�����ж�,�]�O���B�� BOSS ���̷R,�o\n"NOR
HIC"���ж������L BOSS ��L����������l,�]�� BOSS �@\n"NOR
HIC"�_�ﱵ��@��D�`�n�n���o��\n"NOR
          );

        set("light", 1);

set("exits", ([  /* sizeof() ==  1  */
"back" : "/u/t/tako/workroom" ,

])); 
set("objects", ([ /* sizeof() == 1 */
  "/u/t/tako/pooding oven.c" : 1, 
]));
set("valid_startroom", 1);

setup(); 

}



void init()

{
     object me=this_player();

     me->set("startroom","/u/t/tako/pooding room");

                 } 




