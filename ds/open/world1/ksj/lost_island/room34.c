#include <ansi.h>

inherit ROOM;
void create()
{
        set("short", "��@�q��"HIW"�۪L�W"NOR);
        set("long", @LONG
�o�̬O�@�p���ƥ۾�L�����ݡA�۪L�K���Ӱ��q�A�A�X�G�L�k��
���U���F��A�۪L�P�򳣬O�~�k�������C
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
        "southwest" : __DIR__"room33",
]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        set("no_auc", 1);
  set("objects",([
      __DIR__"npc/silver-dragon":1,
     ]));

        setup();
}
