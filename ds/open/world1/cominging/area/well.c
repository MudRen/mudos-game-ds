#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", YEL"古井"NOR);
        set("long",@LONG
這裡是步靈城中央廣場中心古井中，這裡雖然叫古井，但卻還有一
些水從這裡經過，令你的腳底有一點濕濕的，這裡並無什麼燈光，只靠
上方來的燈光照耀下來，而在你腳下的水流似乎沾有一些些的金色物質
，好像可以撈起來的樣子。
LONG
        );
        set("exits", ([
  "east" : __DIR__"well4.c", 
"west" : __DIR__"well2.c",
"south" : __DIR__"well3.c",
"north" : __DIR__"well1.c",
"up" : __DIR__"boo-lin.c",])); 
        set("item_desc",([
"金色物質":"亮金金的東西，看起來好像沙子[sand]似的。\n",
        ]));
        set("no_clean_up", 0);
        setup();
} 
void init()
{
    add_action("do_scrape","scrape");
}
int do_scrape(string arg)
{ 
    object x,me=this_player(); 
    if(this_object()->query_temp("do_scraped")==1) return notify_fail("剛剛已經有人撈過的樣子，現在半點不剩，只好再等它匯集了..\n");
    if(!me) return 0;
    if(arg != "sand") return notify_fail("你要撈什麼??\n");
    message_vision("\n"+me->name()+"撈了一點金沙起來。\n",me);
    x=new("/open/world1/cominging/area/npc/obj/metallizer")->move(environment(me));
    set_temp("do_scraped",1); 
    call_out("do_scrapedd",1800,this_object());
    return 1;
}
void do_scrapedd()
{ 
    delete_temp("do_scraped"); 
    return;
}

