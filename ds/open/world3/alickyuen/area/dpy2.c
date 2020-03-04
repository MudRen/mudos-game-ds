#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIC"ST.FIRE＠DPY地下二樓"NOR);
	set("long", @LONG
下到來地下二樓，你發現這裡的音樂比上面還要嘈吵得多，人們都在
瘋狂地跳舞，有些人在喝酒。在你的左手面是一個大酒櫃和一棵聖誕樹，
酒保機械人都在繁忙地為人客送酒。
LONG
	);
 set("exits",([ 
"up":__DIR__"dpy1.c",
"down":__DIR__"dpy3.c",
]));
	set("world", "future");
set("light", 1);
	set("no_clean_up", 0);
set("item_desc",(["酒櫃":"這是一個放酒的酒櫃,看起來有一些不普通.....\n",
"聖誕樹" : "一棵很高大的樹，上頭有一粒星星正在閃著，真是想把它弄下來用。\n", 
])); 
	setup();
}
void init()
{
	add_action("typepush","push");
add_action("do_pick","pick");
}
int do_pick(string arg)
{
        object me,to;
        me = this_player();
        to = new(__DIR__"obj/star.c");
        if( !arg ) return 0;
        if( arg!="星星" ) return 0;
if( query_temp("getstar") )
{
    return 0;
}
        message_vision("$N偷偷地從聖誕樹上拿下了星星。\n",me);
        to->move(me);
        set_temp("getstar",1);
set("item_desc",(["酒櫃":"這是一個放酒的酒櫃,看起來有一些不普通.....\n",
])); 
        return 1;
}
int typepush(string arg)
{
 	object me;
	me=this_player();
	if (arg != "酒櫃") 
                   return 0;
	else {
                   message_vision("只見$N手一推，便連人帶櫃轉到另一個房間裡。\n\n" ,me);
                   me->move(__DIR__"drm1");
                   tell_room(environment(me),me->query("name")+"突然出現在你眼前。n",me);
	   return 1;
                 }
}

void reset()
{
        delete_temp("getstar");
        set("item_desc",([
        "酒櫃":"這是一個放酒的酒櫃,看起來有一些不普通.....\n",
        "聖誕樹" : "一棵很高大的樹，上頭有一粒星星正在閃著，真是想把它弄下來用。\n", 
          ])); 
}

