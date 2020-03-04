#include <ansi.h>
inherit ROOM;
void create()
{
       set("short","薩爾薩斯港");
        set("long",@LONG
這裡就是薩爾薩斯港了，各式各樣的人在這裡行走著，各式各樣的商
品在這裡販賣著，這裡是連接東方大陸最主要的港口，是東方的旅行者第
一塊踏到的土地，也是西方旅行者最後接觸的故鄉。在港口的東方，是薩
爾薩斯最受歡迎的酒店「獨角鯨的低喃」。
LONG 
);
        set("exits",([
            "north":__DIR__"port_06",
            "east":__DIR__"port_10",
            "south":__DIR__"port_08",
                ]));
        set("objects",([
            __DIR__"npc/ad_wm":1,
            __DIR__"npc/waterman":3,
            __DIR__"npc/ad_mn":1,
                ]));

        set("world","world1");
        set("outdoor","land");
        set("light",1);
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
