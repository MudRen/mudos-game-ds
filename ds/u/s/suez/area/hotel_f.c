#include <ansi.h>
inherit ROOM;

void create()
{
 set("short",HIG"月嵐客棧"NOR);
        set("long",@LONG
在山道上走了許久，突然眼前一亮，一間看起來很舒適的客棧就在你
面前。門口的竹簾輕輕擺動著，發出細微的沙沙聲。門旁疊著四個大酒罈
當招牌，三四個旅人坐在簷下談天，附近林中不停傳來陣陣的鳥叫聲，淙
淙流水在客棧背後緩緩流過。
LONG
        );

         set("exits", ([
         "in": __DIR__"hotel_hall",
       "northup": __DIR__"path_1",
         ]));

        set("objects",([
              __DIR__"npc/traveler" : 1,
              ]) );
        
         set("item_desc",([
        "酒罈":"酒罈上以金漆寫了四個大字"HIY"『月嵐客棧』\n"NOR,
        "竹簾":"細竹編織而成的竹簾，樸素但淡雅。\n",
         ]));
        set("outdoors","forest");
        
        setup();
        replace_program(ROOM);

 }