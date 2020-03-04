#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","碼頭");
        set("long",@LONG
長長的碼頭到此結束，帶著鹹味的海風，一望無際的大海，水手吆喝
的聲音，船舶接近時發出的敲打聲，幾個東方來的旅人站在這裡，試著在
海平面上找尋自己的故鄉，在這異國的土地上。
LONG 
);
        set("exits",([
            "east":__DIR__"port_05",
                ]));
        set("world","world1");
        set("outdoor","land");

        setup();

}

int room_effect(object me)
{
        switch(random(14))
        {         case 6:        message_vision("嗚∼∼∼∼∼遠方船上傳來了低沉的號角聲。\n",me);
                        return 1;
         case 0:        message_vision("帶著鹹味的海風呼呼的吹著∼∼。\n",me);
                        return 1;
         
         default:       return 1;
        }
}

