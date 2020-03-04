#include <room.h>
inherit ROOM;
void create()
{
 set("short","東北澤林﹝泥沼區﹞");
 set("long",@LONG
你來到泥沼區的深處, 在你的眼前是一棵大約要十三
個人才能抱住的千年大神木, 在樹上傳來一陣奇特的鳥叫
聲, 前面沒有路前進了, 看來你只能往回走.

LONG
    );
 set("item_desc",([
        "神木":"這是一棵擁有上千年的神木，你可以爬上去看看\n",]));
 set("exits",(["north":__DIR__"en65",
               "northeast":__DIR__"en66",
               ]));
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}
void init()
{
        add_action("do_climb","climb");
}

int do_climb(string arg)
{
        object me;
        me=this_player();
        if (arg != "神木") return 0;
        
        message_vision("只見$N手、足並用，慢慢地爬上了神木。\n" ,me);
        me->move(__DIR__"en80.c");
        tell_room(environment(me),me->query("name")+"氣喘噓噓地爬了上來。n",me);
        return 1;
}                  
