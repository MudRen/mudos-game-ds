#include <ansi.h>
inherit ROOM;
void create()
{
  set ("short", HIG"���د�~"NOR);
  set ("long", @LONG
�b�o�Ӷ�̭��A�~�M���o��@�ӲM�����a��A�Pı�����ӳ�����
�����ơA�b���Y��F�@�ӦѹD�h�A�Y�L��ƪ��b����o�ۧb�A�`���A
������G���ػ����X�Ӫ��Ǻôb�ۧA�C
LONG
);
        set("exits", ([
  "southwest" : __DIR__"2f_6",
     ]));
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"taoist" : 1,
        ]));

  set("no_clean_up", 0);
  
  setup();
 }

