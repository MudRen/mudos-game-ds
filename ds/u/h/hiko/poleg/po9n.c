inherit ROOM;
void create()
{
        set("short", "泊浪村漁產店");        
        set("long",@LONG
這裡是泊浪村的漁產店，迎面傳來一陣魚腥味，許多遊客來此村都
是因為要來此滿新鮮漁產大快朵頤，因此生意十分不錯，裡面賣的漁產
都是從漁會漁夫們剛上岸便送來的，所以品質新鮮，而亦是一個老饕們
愛來的地方，有空不妨看看。
LONG
        );

set("objects", 
([__DIR__ "npc/fish-seller" : 1,
    ]));
set("exits", ([
  "south" : __DIR__"po9",
]));
        set("light",1);
        set("no_clean_up", 0);
        setup();
}








