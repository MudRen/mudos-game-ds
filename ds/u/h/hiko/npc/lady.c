#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIG"飛船服務員"NOR, ({ "waiter","w" }) );
        set("chat_chance", 15);
           set("long",@STORY                    
他正面帶著一副親切的微笑，用著和藹可親的態度為你打理一切乘坐飛船的問
題，同時還一方面對你解說一些飛船上一切的規矩所應該注意的事項，讓你絲
毫不感到任何的麻煩，同時還有著受到尊重、彷彿就像是認識的人一般熟悉的
感覺。
STORY); 
        set("age",23);
        set("level",25);
        set("no_kill",1);
        set("race","人類");
        set("chat_msg",({
            "飛船服務員說:歡迎光臨\n",
             })); 
        set("talk_reply","需要我服務的地方嗎?");
        setup();
         

              
}

