#include <ansi.h>
inherit MOBROOM;
void create()
{
  set ("short", YEL"黃沙平原"NOR);
  set ("long", @LONG
你發現你己漸漸失去方向感了，不管怎麼走都好似在同一地方打
轉，向四周望去，所見者僅浩浩黃沙，不禁令人心急，要是再走不出
這沙漠，可能要慘死在這裡了，另外聽傳聞到了晚上這裡將毒蛇猛獸
盡出，令人聞之色變。
LONG
);

  set("exits", ([
  "east" : __DIR__"room30",
  "west" : __DIR__"room26",
  "north" : __DIR__"room26",
  "south" : __DIR__"room27",
]));

  set("objects",([
  __DIR__"npc/npc3" : 1,
]));

  set("chance",40);
  set("mob_amount",4);
  set("mob_object",({
  __DIR__"npc/npc1",
  __DIR__"npc/npc2",
  __DIR__"npc/npc7",
  __DIR__"npc/npc8",
}) );

  set("no_map",1);
  set("outdoors", "land");
  set("no_clean_up", 0);
  set("valid_startroom", 1);
  setup();
}
