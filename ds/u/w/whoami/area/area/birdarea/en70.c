#include <ansi.h>
#include <room.h>
inherit ROOM;
inherit __DIR__"muder.c";
void create()
{
 set("short",HIW"東北"NOR"澤林"NOR"－"YEL"泥沼區"NOR); 
 set("long",@LONG
你來到泥沼區的深處, 在你的眼前是一棵大約要十三個人才
能抱住的千年大神木, 在樹上傳來一陣奇特的鳥叫聲, 前面沒有
路前進了, 看來你只能往回走.
LONG);
 set("item_desc",([
        "神木":"這是一棵擁有上千年的神木，你可以爬上去看看\n",]));
 set("exits",(["north":__DIR__"en65",
               "northeast":__DIR__"en66",
               ]));
 set("outdoors","forest");
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
        if (!arg || arg =="")
        return notify_fail("你要爬什麼？\n"); 
        if( me->is_busy() )
        return notify_fail("你還在忙！\n");
        if (arg != "神木") return 0;
        if (random(me->query("str")) >= (me->query("con")/2)){
        message_vision("只見$N手、足並用，慢慢地爬上了神木。\n" ,me);
        me->move(__DIR__"en80.c"); 
        me->start_busy(2);
        tell_room(environment(me),me->query("name")+"氣喘噓噓地爬了上來。n",me);
        return 1;
        }
        tell_object(me,"你的力量沒法支撐你的體重..你是爬不上去的..\n");
        me->start_busy(2);
        return 1;
}                  

