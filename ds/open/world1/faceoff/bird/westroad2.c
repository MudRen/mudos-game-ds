#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"西迴廊"NOR);

 set("long",@LONG
你越往前走﹐越感到奇怪﹐這一條迴廊越來越黑﹐而你又再次聽
到上方傳來怪聲﹐你側起耳朵﹐發現那似乎是人製造出來的聲音﹐你
再次懷疑起密道的存在……而迴廊的盡頭也不遠了…你想﹐不管怎麼
樣, 先走到盡頭在說吧…
LONG
    );
set("exits",([ "east":__DIR__"westroad1",

    ]));
set("no_clean_up",0);
set("light",1);
 setup();
 replace_program(ROOM);
}
