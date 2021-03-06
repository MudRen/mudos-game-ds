// Room: /d/wiz/hall2.c
#include <path.h>
inherit ROOM;

void create()
{
 set("short", "區域研究室");
 set("long", @LONG
你看到這個白色的房間到處都是一疊疊的紀錄文獻和研究報告，  
這裡就是巫師們公佈新區域和大神們發表新政策的地方，如果你是新
進人員，最好先把這裡附近的公告看完。夢幻區域的巫師必須先發表
區域才有資格升級，也才能向更高級的程式創作挑戰，也[1;37m唯有區域通
過審查並且通過基礎考試的巫師能夠進入上面的房間研究職業技能和
戰爭的寫法[0m。有關區域的基本規定與注意事項請用 < [1;34mabout area[m > 
查詢。

LONG
	);
 set("light",1);
 set("exits", ([ /* sizeof() == 2 */
    "down"   : __DIR__"hall1",
    "up"     : __DIR__"hall_guild",
    "east"   : __DIR__"hall_room",
    "west"   : __DIR__"hall_equip",
    "north"   : __DIR__"hall_quest",
    "south"   : __DIR__"hall_npc",
 ]));
 set("no_clean_up", 0);
 set("valid_startroom", 1);
 setup();
 call_other("/obj/board/area_b", "???");
}

void init()
{
 add_action("do_help","about");
}

int do_help(string arg)
{
 if(arg=="area")
 {
   if( file_size("/doc/wiz/area.txt")>0 )
   {
    this_player()->start_more( read_file("/doc/wiz/area.txt") );
    write("\n");
   } else write(" SORRY. 說明檔尚未建立. \n");
  return 1;
 }
 return 0;
}

int valid_leave(object me, string dir)
{
	if( dir=="up" && wiz_level(me)<=wiz_level("(apprentice)") )
		return notify_fail("只有正式巫師(Wizard)才能上去那個通往職業研究室的樓梯。\n");
	return ::valid_leave(me, dir);
}