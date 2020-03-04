inherit ROOM;
void create()
{
        set("short", "山路");
        set("long",@LONG
這裡是天城東邊的山路，路上的臺階看來年久失修，看來很少人來
到此地，道路兩旁雜草叢生十分荒涼，山上該沒什麼人居住，感覺非常
靜謐無聲，西南和東北有兩條分叉小路。
LONG
        );
  
set("exits", ([
  "southwest" : "/open/world1/acme/area/pass8",
  "northeast" : __DIR__"mu2",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}
 




