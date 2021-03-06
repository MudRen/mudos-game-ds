// Room: /d/wiz/hall6.c
#include <ansi.h>
inherit ROOM;

void create()
{
 set("short", "魔神會議室");
 set("long", @LONG

  這裡是大巫師們相互討論與開會的地方，往下是職業技能討論廳。

LONG
	);
 set("light",1);
 set("exits", ([ /* sizeof() == 2 */
    "down"   : __DIR__"hall_guild",
 ]));
 set("no_clean_up", 0);
 set("valid_startroom", 1);
 setup();
 call_other("/obj/board/arch_b", "???");
}

void init()
{
 if(this_object()->query("open")) return;
 if(userp(this_player()))
 {
   if(wiz_level(this_player()) < wiz_level("(arch)"))
   {
     message_vision(HIW"天上傳來威嚴的聲音說:"HIR+this_player()->name()+",你等級不夠不可進入!!\n\n"NOR, this_player());
     tell_object(this_player(),"突然一陣強光將你傳送到了另一個地方...\n");
     this_player()->move(__DIR__"hall_guild");
   } else 
   {
     message_vision(HIW"\n 嗨! "+this_player()->name()+" 歡迎來到魔神會議室!!\n\n"NOR, this_player());
     add_action("do_lock","lockhere");
     add_action("do_unlock","unlockhere");
   }
 }
 return;
}

int do_unlock(string arg)
{
	if(this_object()->query("open")) return notify_fail("巫師過濾力場已經關閉了。\n");
	message_vision(HIW"$N關閉了巫師過濾裝置磁力場!!\n\n"NOR, this_player());
	this_object()->set("open",1);
	return 1;
}

int do_lock(string arg)
{
	object *inv;
	int i;
	if(!this_object()->query("open")) return notify_fail("巫師過濾力場已經啟動了。\n");
	message_vision(HIW"$N啟動了巫師過濾裝置磁力場!!\n\n"NOR, this_player());
	this_object()->delete("open");
	inv = all_inventory(this_object());
	for(i=0;i<sizeof(inv);i++)
	{
	   if(!userp(inv[i])) continue;
	   if(wiz_level(inv[i]) < wiz_level("(arch)"))
	   {
	     message_vision(HIW"天上傳來威嚴的聲音說:"HIR+inv[i]->name()+",你等級不夠不可進入!!\n\n"NOR, inv[i]);
	     tell_object(inv[i],"突然一陣強光將你傳送到了另一個地方...\n");
	     inv[i]->move(__DIR__"hall_guild");
	    }
	}
	return 1;
}
