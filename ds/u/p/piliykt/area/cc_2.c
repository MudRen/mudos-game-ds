inherit ROOM;

void create()
{

set("short","山路");
set("long", @LONG
你正走在石階上, 你看著一格格的石階通往深山裡, 你一想到還要走好長的一段路,
就覺得很累, 兩旁的樹林伴隨的風起舞, 發出沙沙的聲音, 形成了好聽的音樂.
LONG
);
set("outdoors","forest");
set("exits", ([                
        "southdown" : __DIR__"cc_1.c", 
        "eastup" : __DIR__"cc_3.c",
   ]));

 setup();
}

