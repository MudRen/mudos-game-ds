#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"獵狐村"NOR"－"HIC"英雄宅"NOR);
 set("long",@LONG
這裡就是獵狐村英雄的住所了•你猛然一看，眼前居然有顆
跟柱子一樣高大的牙齒，看來這就是九尾的牙齒了，這個英雄看
來也是身手不凡•
LONG);
 set("item_desc",([
        "牙齒":"這顆牙齒應該就是九尾的牙齒，上面還隱隱發出妖氣•\n",     ]));
 set("objects",([__DIR__"npc/hero" : 1,
               ]));
 set("exits",([
               "east":__DIR__"village13", 
               ]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
}

