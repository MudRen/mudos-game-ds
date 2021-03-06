#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","堤岸大道");
        set("long",@LONG
自從薩爾薩斯成為與東方大陸溝通的港口後，這裡也同樣成為以海運
將東方來商品發送到其他地方的中心。如此一來，本來漁村規模的港口也
就不敷使用了，在商人自行的聚資下，薩爾薩斯港慢慢成長為一個正式的
商港，這條堤岸大道就是成長的象徵。
LONG 
);
        set("exits",([
            "west":__DIR__"port_05",
            "east":__DIR__"port_11",
            "north":__DIR__"port_07",
            //"south":__DIR__"port_15",
                ]));
        set("objects",([
            __DIR__"npc/business_wm":1,
            __DIR__"npc/business_mn":1,
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

