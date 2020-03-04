#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", CYN"藏龍鎖"NOR);
	set("long", @LONG
這裡似乎是個重要的地方，因為這裡不僅四周以石塊堆砌，還雕梁畫
棟，十分精美。和剛剛你所看到的簡陋土室簡直是天壤之別。在你面前是
個木架，架上擺了幾本武學密笈，但是好像少了幾本，而在你身邊則有一
個小石梯，石梯上方似乎有個機關，或許你可以上去(climb)看看。
LONG
       );
	set("exits", ([ /* sizeof() == 1 */
                   "east" : __DIR__"base_5",
               ]));
         set("item_desc",([
        "雕刻":"這裡的雕刻十分精美，但是你總覺得哪裡怪怪的。\n",
        "木架":"木架上的武學密笈內容都十分簡單，你不用看也會。但，最有價值的那幾本呢？\n",
         ]));
	set("no_clean_up", 0);
        set("light",1);
	setup();
}
void init()
{
        add_action("do_climb", "climb");
}

int do_climb(string arg)
{
         int t;
        object me;
        me=this_player();
        if(arg != "石梯") return 0;
        message_vision( HIG "$N爬上石梯後突然覺得腳下一鬆，頭頂突然開了一個洞，$N便向洞中爬去。\n\n" NOR ,me);
        me->start_busy(3);
        call_out("domessage",3,me,3);

        message_vision( HIG "$N整個人消失在洞中後，石壁又轟一聲關上了。\n\n" NOR ,me);
      me->move(__DIR__"little_path");
        return 1;
}
int domessage(object me,int b)
{
 if(b==2) 
        tell_object(me, HIB "你走啊走的，一直覺得好像有水聲在耳邊轟轟的響。\n\n" NOR );
  else if(b==1) 
        tell_object(me, HIB "你終於走到了盡頭，看到前方不遠處有個石輪盤。\n\n" NOR );
  else  if(b==0) 
        {
        tell_object(me,HIY "你轉動了石輪盤，石中傳來了一陣機械轉動的聲音，突然眼前一片光亮！\n\n" NOR );
        this_object()->delete("user");
        me->move(__DIR__"hotel_room4");
       tell_room(environment(me),me->query("name")+HIY"突然在一聲巨響後出現！\n"NOR,me);
        return 1;
        }
b--;
me->start_busy(3);
call_out("domessage",3,me,b);
}