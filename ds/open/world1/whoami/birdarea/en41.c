#include <path.h>
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIW"東北"NOR"澤林");
 set("long",@LONG
走到這裡，你只有一陣荒涼的感覺，似乎是一個鳥不生蛋的
地方。四周有一些奇怪的昆蟲在你旁邊盤旋，讓你不自覺得揮動
雙手, 想趕走牠們。東北方的雜草似乎在這平凡的土地的透露出
了詭異的訊息..
LONG);
  set("item_desc",([
        "雜草":"在前方你隱約看見有處雜草可以通過，似乎是前往某個地方的小路。\n",
                  ]));
 set("exits",(["southeast":__DIR__"en40",
               "northwest":__DIR__"en46",
               ]));
 set("outdoors","forest");
 set("no_clean_up", 0);
 setup();
}        
void init()
{
  if ( (query_temp("cut_over")) < 1){
   add_action("do_cut","cut");  
   add_action("do_pass","pass"); 
  }
}
int do_pass(string arg)
{
        object me; 
        me=this_player();
        if (!arg || arg =="")
        return notify_fail("你要穿過什麼？\n");  
        if( me->is_busy() )
        return notify_fail("你還在忙！\n");
        if (arg != "雜草") return 0; 
        if (this_object()->query_temp("cut_over") >= 1) {
        tell_object(me,"\n豬頭喔！！直接往東北走啦！！\n");
        } else {        tell_object(me,"\n這雜草太高了，你是穿不過去的..(不砍掉似乎是過不去的)\n"); 
        }        return 1;
}int do_cut(string arg)
{        
        object me,weapon; 
        me=this_player();
        weapon = me->query_temp("weapon");
            
        if (!arg || arg =="")
        return notify_fail("你要砍掉什麼？\n");  
         if( me->is_busy() )
        return notify_fail("你還在忙！\n");
 
        if(!weapon) 
        return notify_fail("你沒裝備武器啊？\n");

        if(weapon->query("skill_type")!="sword" && weapon->query("skill_type")!="blade" 
        && weapon->query("skill_type")!="axe" && weapon->query("skill_type")!="dagger") 
        return notify_fail("想斬開這些東西必須要是把有著刃的武器..\n");
        
        if (arg != "雜草") return 0;
        
        message_vision(HIR"\n$N揮舞手中的"NOR + weapon->name() + HIR"向東北方砍出了一條路來了..\n"NOR ,me);
        __DIR__"en41.c"->add("exits", ([ "northeast" :  __DIR__"en42.c"]));
        me->start_busy(2);
        set_temp("cut_over",1);
        set_temp("long", @LONG
走到這裡，你只有一陣荒涼的感覺，似乎是一個鳥不生蛋的
地方。四周有一些奇怪的昆蟲在你旁邊盤旋，讓你不自覺得揮動
雙手, 想趕走牠們。
LONG);
        call_out("rb", 300);
        return 1;
}          
void rb(object tob)
{
        delete_temp("cut_over"); 
set("long",@LONG
走到這裡，你只有一陣荒涼的感覺，似乎是一個鳥不生蛋的
地方。四周有一些奇怪的昆蟲在你旁邊盤旋，讓你不自覺得揮動
雙手, 想趕走牠們。東北方的雜草似乎在這平凡的土地的透露出
了詭異的訊息..
LONG); 
"/open/world1/whoami/birdarea/en41"->delete("exits/northeast"); 
        return;
}

