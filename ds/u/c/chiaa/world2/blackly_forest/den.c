//u/c/chiaa/world2/blackly_forest/den.c

#include <ansi.h>
inherit ROOM;

void create ()
{
  set("short", "�K��");
  set("long", @LONG
�@�Ӷ·t���K��,��ӳo�̬O�Ԫ̧����k�ͥX�f,
�n�O���ĤH��ŧ,�ӤJ�f�S�Q�ʦ�,�N�i�H�Ѧ��q���~����
�·t�˪L!!
LONG
        );
  set("exits", ([ /* sizeof() == 1 */
 "up"    : __DIR__"road8", //�˪L�~�B
  
]));


 setup();
  replace_program(ROOM);
}
