inherit ROOM;
void create()
{
        set("short", "泊浪村特產店");        
        set("long",@LONG
這裡是泊浪村的特產店，看起來十分整潔，許多遊客來此村都在此
選購特產，因此賣的名聲也算不錯，裡面賣的東西和物品都是屬於泊浪
村的特產別地方是買不到的，因此生意還不錯，本店主人則是一臉正直
，有著忠厚的樣貌。
LONG
        );
set("exits", ([
  "south" : __DIR__"po7",
]));
set("objects", ([__DIR__ "npc/jang-sha" : 1,
    ]));
        set("light",1);
        set("no_clean_up", 0);
        setup();
}








