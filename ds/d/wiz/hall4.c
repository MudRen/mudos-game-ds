// Room: /d/wiz/hall4.c

inherit ROOM;

void create()
{
 set("short", "任務討論廳");
 set("long", @LONG

  這裡是巫師討論任務寫法和發表新任務的地方﹐往上是技能討論廳﹐
往下是怪物討論廳。 要觀看任務注意事項請輸入 < about quest > 

LONG
	);
 set("light",1);
 set("exits", ([ /* sizeof() == 2 */
    "down"   : __DIR__"hall3",
    "up"     : __DIR__"hall5",
    "hole"   : __DIR__"quest1",
 ]));
 set("no_clean_up", 0);
 set("valid_startroom", 1);
 set("objects",([
 __DIR__"npc/boy2":1,
 ]));
 setup();
 call_other("/obj/board/quest_b", "???");
}

void init()
{
 add_action("do_help","about");
}

int do_help(string arg)
{
 if(arg=="quest")
 {
   if( file_size("/doc/wiz/quest.txt")>0 )
   {
    this_player()->start_more( read_file("/doc/wiz/quest.txt") );
    write("\n");
   } else write(" SORRY. 說明檔尚未建立. \n");
  return 1;
 }
 return 0;
}