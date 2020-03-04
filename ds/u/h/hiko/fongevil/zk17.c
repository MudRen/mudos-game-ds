inherit ROOM;
void create()
{
        set("short", "山間野林");
        set("long",@LONG
你走到山中的林地，眼前所見都是陰暗的樹林，且還有陰風陣陣吹襲
枝葉，發出嗚嗚的怪聲，讓你感覺毛骨悚然，西面望去似乎有個遺跡，不
知內裡是做什麼的，西北邊亦是一片山林。
LONG
        );
  
set("exits", ([
  "west" : __DIR__"zk13",
  "northwest" : __DIR__"zk16",
  "southwest" : __DIR__"zk18",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}

 

