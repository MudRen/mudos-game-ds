#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIW"神魔交界處"NOR);
        set("long", "
此地是神與魔的交界，兩側都有守衛在守護著，不讓一些閒雜人
等進入。往下望就是邪魔域，聽世人傳言，凡是闖入邪魔域這條不歸
路的人或神，都無法全身而退的走出，可見邪魔域的可怕，讓眾神與
當今武林好手不敢恭維。
");
 
        set("light", 1);
        set("objects", ([ /* sizeof() == 2 */
 __DIR__"npc/e-guard" : 1,
 __DIR__"npc/godguard" : 1,
]));
        set("item_desc", ([
        "邪神柱" : "此柱為邪魔域的代表，象徵的邪魔域的黑暗。在柱子中央有一缺口，不知是否可放入物品？\n",
                
        ]));
        setup();
}

void init()
{
        add_action("do_putin","putin");
}

int do_putin(string arg)
{

object me = this_player();
object mirror;

      if(!arg || arg!="缺口") return notify_fail("你要放入什麼?\n");
      if(!objectp(mirror=present("evil mirror",me) ) )
       return notify_fail("要放入什麼? \n");

        { 
       if( !query("start"))
        {
        message_vision(HIR"$N放入了邪龍鏡後，大地突然驚變。\n"+NOR,me);
        message_vision(HIR"突然有一道紅光照耀此地，此光之閃爍，讓你的眼睛頓時無法張開！\n"+NOR,me);
        set("start", 1);
        call_out("evil_msg",4);
        } else {
         return notify_fail("邪暗之門已打開。\n");
     } 
 }
return 1;

}

int evil_msg()
{
   message("world:world1:vision",
HIW"\n山崩"HIW+BLK"地動，一道紅色耀眼光芒閃爍在某方...............\n\n\n"NOR,users());
  call_out("evil_msg2",3);
} 
int evil_msg2()
{
 message("world:world1:vision",HIC"\n此時"NOR+CYN"邪魔域裡的牛鬼蛇神笑聲貫徹全武林。\n\n"NOR,users());
  call_out("evil_msg_last",7);
}

int evil_msg_last()
{
  object me=this_player();message("world:world1:vision",HIB"邪魔域王"HIW"大聲的對著"HIG+me->query("name")+HIW"咆嘯："HIR"當你踏入邪魔域的那天，隔年便是你的忌日！！\n\n\n"NOR,users());
  call_out("getin_msg",3,me);

  set("start", 0);
  delete("start");
}


int getin_msg(object me)    
{
    me=this_player();

    message_vision(HIR"只見紅色光芒照耀著$N，頃刻間$N隨著紅光慢慢的退散，消失不見了！！\n"NOR,me);
    me->move(__DIR__"room1");     
    call_out("close_msg",20,me);
    return 1;
}
int close_msg(object me)
{
    message("world:world1:vision",HIY"\n\t慢慢的大地又恢復了以往的祥和與平靜了。$！\n"NOR,me);
    return 1;
}

