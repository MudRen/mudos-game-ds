//u/c/chiaa/world2/blackly_forest/garrison1.c

#include <ansi.h>   //�w�q�C��
inherit ROOM;

void create ()
{
  set("short", "�n�u�B");
  set("long", @LONG
�o�̬O�Ԫ̧����n�u�B,���X�Ӭ�������Ԫ̪A�˪��H,
���n�ۧA��,���~�����X��,�L�̫O�����ת�ĵ�٤�,
�ϧA�ۤv�Pı���٬O���n���|�k�ʪ��n!!
LONG
        );


  set("exits", ([ /* sizeof() == 1 */
   
  "east"  : __DIR__"garrison2",         //�n�u�B2
   
]));


 setup();
  replace_program(ROOM);
}
