#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��@�q��"HIG"�~��"NOR);
        set("long", @LONG
�o�̬O�@��L�ڪ��j���A�����ν����C�A����A�٦��\�h����
�W�����Ӫ��A���B���s�����������K���}�f�A�}�f�Ǫ����ý����a
�A�ݰ_�ӳ���˴ˡA���Ӥ��O����n�a��C
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "enter" : __DIR__"room31",
  "southwest" : __DIR__"room29",
  "south" : __DIR__"room28",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        set("no_auc", 1);
        set("objects",([
             __DIR__"npc/eq/bone":1,
           ]));
        setup();
}
