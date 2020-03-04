// Room: /d/wiz/hall5.c

inherit ROOM;

void create()
{
 set("short", "法術討論廳");
 set("long", @LONG
這裡是巫師討論職業法術寫法和發表新法術的地方，往東是職業
研究室。要觀看法術注意事項請輸入 < about spell > 

LONG
	);
 set("light",1);
 set("exits", ([ /* sizeof() == 2 */
    "east"   : __DIR__"hall_guild",
 ]));
 set("no_clean_up", 0);
 set("valid_startroom", 1);
 setup();
 call_other("/obj/board/spell_b", "???");
}

void init()
{
 add_action("do_help","about");
}

int do_help(string arg)
{
 if(arg=="spell")
 {
   if( file_size("/doc/wiz/spell.txt")>0 )
   {
    this_player()->start_more( read_file("/doc/wiz/spell.txt") );
    write("\n");
   } else write(" SORRY. 說明檔尚未建立. \n");
  return 1;
 }
 return 0;
}
