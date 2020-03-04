inherit ROOM;
void create()
{
        set("short", "泊浪村南側");
        set("long",@LONG
這裡已經是泊浪村內了，村裡的每個人給人的感覺都十分有活力，
在泊浪村內學問和見聞不夠沒關係，但是體力是必要的，泊浪村的每個
人從小就要學習捕魚，因此每個人都是高超的漁夫，不管是近海或遠洋
的海產都十分豐富，也算是這裡的名產之一，而海風吹來所夾帶的鹹味
正讓人感覺到海邊風味。
LONG
        );
        set("exits", ([
    "north" : __DIR__"po2",
    "south" : __DIR__"po0",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}


