#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","寨牆");

 set("long",@LONG
這裡已經是寨牆的盡頭了, 在你的眼前是一些極其陡峭的山
壁, 如果你自信你的輕功不錯, 可以試試看飛簷走壁的功夫, 不
過就算輕功不好, 你也發現寨牆角有一個小洞, 你也可以爬進去.
LONG
    );
 set("exits",([	"south":__DIR__"ten17",
    ]));
 set("item_desc",([
        "山壁":"你發現你的估計錯誤,就算輕\功\再\高也絕對過不去!\n",
	"小洞":"一個不知道為什麼存在的洞,你可以爬(enter)進去....\n",
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();                    
}

void init()
{
        add_action("do_enter","enter");
}

int do_enter(string arg)
{
      object me;
      me=this_player();
      if (arg != "小洞") return 0;
      message_vision("$N從牆角的小洞鑽了進去....\n"  ,me);
      me->move( __DIR__"ten19");   
      return 1;
      }
