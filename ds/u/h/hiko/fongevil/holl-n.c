inherit ROOM;
void create()
{
        set("short", "山洞");
        set("long",@LONG
你來到了山洞內，山洞內黑漆漆的，隱隱好像有著一點光亮，忽
然有看到一種植物在發螢光，不過似乎也有一種奇特的香味，令你感
到十分詭異。
LONG
        );
  
set("exits", ([
  "south" : __DIR__"holl",
   ]) );       
set("objects",([
  __DIR__"light_grass" : 1,
        ]));
        set("no_clean_up", 0);
        set("light",1);
        setup();
 }
 






