//u/c/chiaa/world2/blackly_forest/garrison2.c

#include <ansi.h>
inherit ROOM;

void create ()
{
  set("short", "�n�u�B");
  set("long", @LONG
��A�q�W�豼�U���ٷd���M����V��,�M�J�A��î���~�M�O�@�ӧ���,
���X�Ӭ�������Ԫ̪A�˪��H,���n�ۧA��,
���D�o�N�O�ǻD���~��b�·t�˪L���Ԫ̤@�ڶ�??
LONG
        );


  set("exits", ([ /* sizeof() == 4 */
     "up"    : __DIR__"nivi_entranceway",   //�Ԫ̧��J�f
     "east"  : __DIR__"hut",               //�𮧩�
     "west"  : __DIR__"garrison1",         //�n�u�B1
     "south" : __DIR__"nivi_road1",        //�ԧ��D��1
]));


 setup();
  replace_program(ROOM);
}
