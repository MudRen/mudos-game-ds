inherit ROOM;

void create()
{

set("short","斜坡");
set("long", @LONG
你望著山腳下的無砂鎮, 並看著大海, 讓你有一種興奮的感覺, 往北
是到達無砂鎮, 往西是到神木村的山路.
LONG
);
set("outdoors","forest");
set("exits", ([                
        "westup" : __DIR__"cc_7.c", 
        "northdown" : __DIR__"cc_9.c",
   ]));

 setup();
}

