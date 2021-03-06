#include <ansi.h>
#define OUT_ROOM "/open/world1/acme/area/moon/room7"
inherit ITEM;
void create()
{
    set_name(HIR"月魂水晶"NOR,({"moon crystal","crystal"}));
        set("unit", "個");
        set("long",@LONG
        
  你趨向前去，仔細的觀察著水晶。這個散發著淡紅色光芒的巨大水晶
  ，應該就是那傳說中的月魂水晶(The Crystal of Moon-Soul)了。據
  說月魂水晶是所有月族人民精氣神的根源，如果你向它虔誠祈禱的話
  說不定會有甚麼奇妙的事情發生。

LONG
);
        set("value", 1);
        set("no_sac", 1);
        set("no_get", 1);
        set("no_clean_up",1);
	setup();
}

void init()
{
	add_action("do_pray","pray");
}

int do_pray(string arg)
{
	object me;
	
	me=this_player();
	if(arg!="crystal" && arg!="moon crystal")
	{
		notify_fail("你要對什麼禱告?\n");
		return 0;
	}

	message_vision("$N閉上眼睛向著月魂水晶默念禱詞...\n",me);
	write("忽然有陣低沉的聲音在你的腦中響起。\n");
	if(me->can_move(OUT_ROOM))
	{
		tell_room(environment(me),me->name()+"漸漸消失的無影無蹤了。\n",({me}));
		write(HIC"\n\t吾之子民啊!!!  汝將受吾所佑....\n\n"NOR);
		me->move(OUT_ROOM);
        write("  當你緩緩張開雙眼時，發現已經回到了雕像之前。\n");
		tell_room(environment(me),me->name()+"突然從雕像背後走了出來。\n",({me}));
		return 1;
	} else
	{
		write("結果什麼事都沒發生..你覺得似乎不太對勁。\n");
		return 1;
	}
}
