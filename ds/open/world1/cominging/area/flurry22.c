#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIC"龍風小舍"NOR);
        set("long", @LONG

這裡是疾風門莊院四舍中的龍風小舍，許多廢刀槍於此，地板有些
髒亂，天花板也似乎有些漏洞，跟樺葉小舍有天壤之別，但卻有些武功
集錄，似乎還不錯的樣子，屋內還有個大灶，裡面充滿了許多燒過的柴
灰和炭，在靠近窗戶的地方還有一個書架，上面不知道有什麼書籍，只
見零零落落的幾本。

LONG
        );
        set("exits", ([
  "east" : __DIR__"flurry23.c",
]));
	set("objects", ([
  __DIR__"npc/obj/shelf.c" : 1,
]));
        set("no_clean_up", 0);
        set("light",1);
        set("item_desc",([
  "大灶" : "大灶裡的空間大到好像可以容納的了你。\n",
]));
        setup();
}

void init()
{
        add_action("do_enter","enter");
}

int do_enter(string arg)
{
        if( arg!="大灶" )return 0;
        else {
                message_vision(HIY"$N一進去大灶就被大灶的煙薰得受不了而出來了。\n"NOR,this_player());
                return 1;
        }
}