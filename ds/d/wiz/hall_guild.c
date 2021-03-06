// Room: /d/wiz/hall2.c
#include <path.h>
inherit ROOM;

void create()
{
 set("short", "職業研究室");
 set("long", @LONG
這個白色的房間就是資深巫師們公佈新職業和大神們發表新規定
的地方，四周擺著許多大鐵櫃，裡面都是巫師們的研究心得報告，能
夠來此研習的巫師都已經有相當程度的經驗與能力。夢幻區域的巫師
必須先發表區域才有資格來此學習。有關區域的基本規定與注意事項
請用 < [1;34mabout guild[m > 查詢。往北走會有一連串的導師範例。

  [此處提供count指令讓巫師估算各種不同技能難度所對應的花費]

LONG
	);
 set("light",1);
 set("exits", ([ /* sizeof() == 2 */
    "down"   : __DIR__"hall_area",
    "up"     : __DIR__"hall_arch",
    "east"   : __DIR__"hall_skill",
    "west"   : __DIR__"hall_spell",
    "north"  : __DIR__"hall_master",
//    "south"   : __DIR__"hall_special",
 ]));

 set("no_clean_up", 0);
 set("valid_startroom", 1);
 setup();
 call_other("/obj/board/guild_b", "???");
}

void init()
{
 add_action("do_help","about");
 add_action("do_count","count");
}

int do_help(string arg)
{
 if(arg=="guild")
 {
   if( file_size("/doc/wiz/guild.txt")>0 )
   {
    this_player()->start_more( read_file("/doc/wiz/guild.txt") );
    write("\n");
   } else write(" SORRY. 說明檔尚未建立. \n");
  return 1;
 }
 return 0;
}

int do_count(string arg)
{
	int hard,i,exp_sum=0,money_sum=0;
	if(!arg || sscanf(arg,"%d",hard)!=1) return notify_fail("指令: count <難度值>。\n");
	printf("難度值: %d \n",hard);
	if( hard > 999 || hard < 1) return notify_fail("請重設一個1到999的難度值。\n");
	for(i=1;i<100;i++)
	{
		exp_sum=exp_sum+(i*i*hard/50);
		money_sum=money_sum+(i*i*hard/70);
		if(i%10==0) printf("技能等級:[%3d] 經驗累計:[%8d]  學費累計:[%8d]\n",i,exp_sum,money_sum);
	}
	printf("技能等級:[ 99] 經驗累計:[%8d]  學費累計:[%8d]\n",exp_sum,money_sum);
	return 1;
}