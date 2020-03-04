#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","竹林");
        set("long", @LONG
這是一片竹林，在你眼前可看見一見竹舍，竹舍傍水而建，竹舍
四周，由內而外，極有秩序地，佈置著三層裝設，內層是十二塊尋丈
巨石，中間是二十五支按梅花樁方式，排置的木椿，最外圍則是你現
在身處的位置，有著數百株參天竹林。
LONG
            );
        set("item_desc", ([ /* sizeof() == 1 */
          "梅花樁" : "這梅花椿排列整齊，但卻形成奇奧無比的陣勢，你可(jump)上椿。\n",
          "巨石" : "這巨石離你相當近，但要靠近卻十分困難。\n",
        ]));
set("exits", ([
  "south" : __DIR__"p8",
]));
        set("light",1);
        setup();
}
void init()
{ 
  add_action("do_jump","jump");
}
int do_jump(string arg)
{
          object me;
          me=this_player();
          if(arg!="梅花樁") return 0;
          message_vision("$N一提氣，輕輕的躍上了梅花椿。\n",me);
          me->move(__DIR__"may3");
          return 1;
}
