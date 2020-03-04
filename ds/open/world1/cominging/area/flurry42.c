#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"土冀小舍"NOR);
	set("long", @LONG

這裡是一間小小的小舍，跟尋常的小舍不同的是，這個小舍還會有
許多的地下室來存放東西，大概是跟風水有關吧，這間小舍是疾風門莊
內四大舍之一，屋內塵沙佈滿了每個地方，似乎四周一切都霧茫茫的，
令你看不清，也摸不著。

LONG
	);
	set("exits", ([
  "west" : __DIR__"flurry41.c",
]));
	set("no_clean_up", 0);
	set("light",1);
	setup();
}

void init()
{
	call_out("delay",2,this_player());
}

void delay(object me)
{
	if( environment(me)!=this_object())return;
	else {
		write(HIY"地下儲藏室似乎有些聲響。\n"NOR);
		return;
	}
}