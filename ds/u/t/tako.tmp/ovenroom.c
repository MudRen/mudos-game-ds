#include <ansi.h>
inherit ROOM;
void create()
{
                 set("short",YEL"�N�ѥ]��"NOR);

                 set("long", 
HIW"�A�@�i��o���ж���,���W���@�ѲH�H���ѥ]����������Ө�\n"NOR
HIW"�A�J�Ӫ��@��,�o�̦��@�O�N�c,�̭���۪iù�ѥ],���o�ѥ]\n"NOR
HIW",���,���嵥��..���ѥ],���خ����A���f�����_���y�X��\n"NOR
          );

        set("light", 1);

set("exits", ([  /* sizeof() ==  1  */
"back" : "/u/t/tako/workroom" ,

])); 
set("objects", ([ /* sizeof() == 1 */
  "/u/t/tako/oven.c" : 1, 
]));
set("valid_startroom", 1);

setup(); 

}



void init()

{
     object me=this_player();

     me->set("startroom","/u/t/tako/ovenroom");

                 } 



