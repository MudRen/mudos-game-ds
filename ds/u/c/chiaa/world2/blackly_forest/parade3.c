//u/c/chiaa/world2/blackly_forest/parade3.c

#include <ansi.h>
inherit ROOM;

void create ()
{
  set("short", "�V�m��");
  set("long", @LONG
�o�̬O�V�m�s��Ԫ̪��a��,�M�J�A��î���O�@�ǤH���i���
�۷��Y�V���V�m,�Ů��j���۷ϹлP�[���n!!
LONG
        );


  set("exits", ([ /* sizeof() == 1 */
 
     "north" : __DIR__"parade2",         //�V�m��2
]));

setup();
  replace_program(ROOM);
}
