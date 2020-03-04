// Room: /d/wiz/hall5.c

inherit ROOM;

void create()
{
 set("short", "進階導師範例房間");
 set("long", @LONG
這裡是進階導師範例的房間。請鍵入[1;33m about master [m已獲取寫導師的
方法與注意事項。
LONG
	);
 set("light",1);
 set("exits", ([ /* sizeof() == 2 */
    "south"   : __DIR__"hall_master",
    "north"   : __DIR__"hall_master3",
 ]));
 set("objects", ([ /* sizeof() == 1 */
	"/u/s/shengsan/npc/adv_bluemaster": 1,
	]));
 set("no_clean_up", 0);
 set("valid_startroom", 1);
 setup();
// replace_program(ROOM);
}

void init()
{
 add_action("do_help","about");
}

int do_help(string arg)
{
 if(arg=="master")
 {
   if( file_size("/u/s/shengsan/npc/adv_bluemaster.c")>0 )
   {
    this_player()->start_more( read_file("/u/s/shengsan/npc/adv_bluemaster.c") );
    write("\n");
   } else write(" SORRY. 說明檔尚未建立. \n");
  return 1;
 }
 return 0;
}
