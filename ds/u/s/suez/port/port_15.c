#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","碼頭廣場");
        set("long",@LONG
這裡是薩爾薩斯碼頭廣場，所有的貨物都運送到這裡再分到船上，甚
至有一個誇張的說法「在薩爾薩斯碼頭廣場，你可以找到世界上所有的東
西，包括你媽三十年前穿的內褲。」這也是諷刺商人只要有錢什麼都賣的
笑話，不過這裡有著東西方大部分的值錢商品倒是不假。
LONG 
);
        set("exits",([
            "east":__DIR__"port_19",
            "north":__DIR__"port_08",
            "south":__DIR__"port_18",
                ]));
        set("objects",([
             __DIR__"npc/waterman":3,
                ]));

        set("world","world1");
        set("outdoor","land");

        setup();

}
int room_effect(object me)
{
        switch(random(14))
        {
                
         case 7:        message_vision("一艘貨船漸漸靠港了，只見港口上一片混亂。\n",me);
                        return 1;
         case 6:        message_vision("嗚∼∼∼∼∼遠方船上傳來了低沉的號角聲。\n",me);
                        return 1;
         case 5:
         case 4:        message_vision("水手們唱著﹕「他說風雨中∼這點痛算什麼∼∼」\n",me);
                        return 1;
         
         case 3:
         case 2:        message_vision("水手們吆喝著﹕「來喔！來喔！好！再過來一點！」\n",me);
                        return 1;
         case 1:
         case 0:        message_vision("帶著鹹味的海風呼呼的吹著∼∼。\n",me);
                        return 1;
         
         default:       return 1;
        }
}


