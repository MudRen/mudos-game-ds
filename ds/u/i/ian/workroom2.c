#include <ansi.h>
inherit ROOM;
void create()
{
 set("short",HIC"伊恩的工作室"NOR);

 set("long",@LONG
這裡就是伊恩的工作室, 這裡冷的不得了, 你不禁慶幸穿了皮裘進
來, 不然這時你可能變成一坐冰雕了, 這間房間中央擺著一張冰雕刻而
成的辦公桌, 辦公桌前的皮椅已經結冰, 在房間的另一角還有一個水池
, 上面漂著一塊塊的浮冰, 更誇張的是, 居然有幾隻企鵝和北極熊, 你
不禁懷疑, 這個工作室的主人是不是精神病院跑出來的...
LONG
    );
 set("exits",([ "out":"/u/i/ian/workroom",
    ]));
        set("no_fight", 1);
        set("light",1);
 set("no_clean_up", 1);
 setup();
 replace_program(ROOM);
 

}

