// Room: /d/wiz/hall2.c
#include <path.h>
inherit ROOM;

void create()
{
 set("short", "物品材料鑑定室");
 set("long", @LONG

  這裡是巫師討論裝備材質寫法和發表新材質的地方﹐往西是裝備討
論廳。 要觀看材質注意事項請輸入 < about material > 

LONG
	);
 set("light",1);
 set("exits", ([ /* sizeof() == 2 */
    "west"   : __DIR__"hall2",
 ]));
 set("objects",([
// "/u/l/luky/obj/fighterneck":1,
 ]));
 set("no_clean_up", 0);
 set("valid_startroom", 1);
 setup();
 call_other("/obj/board/material_b", "???");
}

void init()
{
 add_action("do_help","about");
}

int do_help(string arg)
{
 if(arg=="material")
 {
   if( file_size("/doc/wiz/material.txt")>0 )
   {
    this_player()->start_more( read_file("/doc/wiz/material.txt") );
    write("\n");
   } else write(" SORRY. 說明檔尚未建立. \n");
  return 1;
 }
 return 0;
}