//u/c/chiaa/world2/blackly_forest/hut.c

#include <ansi.h>
inherit ROOM;

void create ()
{
  set("short", "�𮧩�");
  set("long", @LONG
�o�̬O�n�u�B�P�V�m�Ϫ��𮧳���!
�����Ǿ�ѰV�m���Ԫ̩M�J�f���n�x�𮧪��a��!!
LONG
        );


  set("exits", ([ /* sizeof() == 2 */
   
     "west"  : __DIR__"garrison2",       //�n�u�B2
     "south" : __DIR__"parade1",         //�V�m��1
]));


 setup();
  replace_program(ROOM);
}
