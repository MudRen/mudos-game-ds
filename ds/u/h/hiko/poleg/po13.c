inherit ROOM;
void create()
{
        set("short", "泊浪村街道");        
        set("long",@LONG
這裡是泊浪村廣場南側的街道，而四周都是一些民宅，看起來似乎
沒有什麼奇異之處，不過有時平靜也是暗藏玄機的，聽村人說這裡附近
常常晚上有著一些奇怪的聲音，感覺起來透露異狀。
LONG
        );
        set("exits", ([  
"south" : __DIR__"po13-1",
"north" : __DIR__"po10",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}








