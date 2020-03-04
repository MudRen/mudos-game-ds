inherit ROOM;
void create()
{
        set("short", "山道");
        set("long",@LONG
你已經可以隱約看到山頭了，看來該是快到山頂了，忽然寒風吹的讓
你有些奇怪，天氣竟然瞬間變化，令你覺得好像有古怪，看來山上也許有
不尋常的東西，北邊有一條路往山上，南邊則是下山。
LONG
        );
  
set("exits", ([
  "northwest" : __DIR__"mu10",
  "southdown" : __DIR__"mu8",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}
 





