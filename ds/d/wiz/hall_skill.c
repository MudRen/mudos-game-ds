// Room: /d/wiz/hall5.c

inherit ROOM;

void create()
{
 set("short", "技能討論廳");
 set("long", @LONG
這裡是巫師討論職業技能寫法和發表新技能的地方，往西是職業
研究室。要觀看技能注意事項請輸入 < about skill > 

LONG
	);
 set("light",1);
 set("exits", ([ /* sizeof() == 2 */
    "west"   : __DIR__"hall_guild",
 ]));
 set("no_clean_up", 0);
 set("valid_startroom", 1);
 setup();
 call_other("/obj/board/skill_b", "???");
}

void init()
{
 add_action("do_help","about");
}

int do_help(string arg)
{
 if(arg=="skill")
 {
   if( file_size("/doc/wiz/skill.txt")>0 )
   {
    this_player()->start_more( read_file("/doc/wiz/skill.txt") );
    write("\n");
   } else write(" SORRY. 說明檔尚未建立. \n");
  return 1;
 }
 return 0;
}
