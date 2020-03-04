#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"寢房"NOR);

set("long",@LONG
這裡是掌門人和教主夫人的寢房, 這裡同樣是用幾塊木板搭
建而成, 可以見得治藥一派的落寞. 這裡值得注意也就只有牆邊
的書櫃, 和床上躺著的那個人了. 
LONG
    );
 set("exits",([ "northwest":__DIR__"pill5",
    ]));
 set("objects", ([__DIR__"npc/master_walf" : 1,
    ]));
 set("item_desc",([
         "書櫃" : "一個木製書櫃，外表雖破爛不堪，但想必裡頭的書一定大有來頭。\n",
    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();                  
}

