//u/c/chiaa/world2/blackly_forest/parade2.c

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


  set("exits", ([ /* sizeof() == 2 */
     "south"  : __DIR__"parade3",       //�V�m��3
     "west"   : __DIR__"parade1",       //�V�m��1
    
]));


 setup();
  replace_program(ROOM);
}
