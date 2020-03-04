#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
set("short",HIW"東北"NOR"澤林"HIW+BLK"－"HIY"狐穴洞口"NOR);

set("long",@LONG
這是一處狐狸的洞穴口，濃厚血腥味從洞內不斷飄來，一股
不安的感覺油然而生，好像隨時會發生可怕的事情，你額頭開始
冒出冷汗，心底裡面正躊躇著是否要進洞裡一瞧。
LONG);
 
 set("exits",(["southeast":__DIR__"en9",
    ]));
   set("item_desc",([
        "洞":"你朝洞裡看了看，裡頭漆黑一片什麼都看不到，

        但是你卻嗅到了一股不正常的血腥味...\n",

        ]));
 set("no_clean_up", 0);
 setup();
}           
void init()
{
        add_action("do_enter","enter");
}

int do_enter(string arg)
{
        object me,b;
        me=this_player();
        if (!arg || arg =="")
        return notify_fail("你要進去那裡？\n"); 
        if( me->is_busy() )
        return notify_fail("你還在忙！\n");
        if (arg != "hole" && arg != "洞") return 0;
        if ( me->query_temp("can_enter") ){
        message_vision("\n\t$N提起勇氣朝"HIY"狐穴"NOR"前進了！\n" ,me);
        me->move(__DIR__"fox1.c"); 
        me->start_busy(2); 
        me->delete_temp("can_enter"); 
                call_out("girl",600,this_object());
        if( sizeof(filter_array( children(__DIR__"npc/qgirl"), (: clonep :) )) < 1 
        && (query_temp("no_girl")) < 1 
        && sizeof(filter_array( children(__DIR__"npc/kfox"), (: clonep :) )) < 1)
        { 
        __DIR__"fox18"->delete("exits/enter");
        b = new(__DIR__"npc/qgirl")->move(__DIR__"fox18");
        }
        tell_room(environment(me),me->query("name")+"走了進來..\nn",me); 
        set_temp("no_girl",1);        } else { 
        tell_object(me,"你是看不懂字還是想死..來這裡做什麼？\n");}
        return 1;
}                  
void girl(object tob)
{
        delete_temp("no_girl");
        return;
}

