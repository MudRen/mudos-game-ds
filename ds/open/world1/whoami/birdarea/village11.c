#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"獵狐村"NOR"－"HIW"民房"NOR);
 set("long",@LONG
你走進了這間屋子, 環顧了四周, 牆壁上掛滿了琳瑯滿目的
狐皮製品, 在角落有一架織布機跟一張椅子, 有一個人坐在椅子
上, 他似乎有些煩惱的樣子....
LONG);
 set("exits",(["west":__DIR__"village10",
               ]));
 set("objects",([__DIR__"npc/wang" : 1,
     ]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
}        

