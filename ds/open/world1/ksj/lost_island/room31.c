#include <ansi.h>
inherit ROOM;

void create()
{
  set("short", "��@�q��"HIG"�}�]"NOR);
  set("long", @LONG
�o�̬O�@�ӳ��t���}�]�A�|�P�����j����A�a�������\�h���e�A
�����t�B���G���F��b�s���A�A�Ů𤤺��O�ͨ��ξ`���C
LONG
);
  set("exits", ([ /* sizeof() == 4 */
      "out" : __DIR__"room30",
     ]));
  set("no_clean_up", 0);
  set("no_auc", 1);
  set("light", 0);
  set("objects",([
      __DIR__"npc/eagle-bat":1,
      __DIR__"npc/ghost-spider":1,
      __DIR__"npc/dream-tapir":1,
      __DIR__"npc/eq/captain-corpse":1,
     ]) );
  setup();
}
