inherit ROOM;
void create()
{
        set("short","祭靈森林西側");
        set("long",@LONG
你走到了森林的西南邊，往前看去似乎一片迷茫，被極為濃厚的霧
給遮掩住，看不清前方到底有著什麼東西，似乎有什麼力量影響著這裡
隱約可以看到霧氣和一股寒氣交旋，感覺有什麼力量制約著寒氣無法輕
易的擴張出來，這裡有兩個守衛，看來是無法前進了。
LONG
        );
        set("exits", ([
  "south" : __DIR__"t10",
]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}











