inherit MOBROOM;
void create()
{
        set("short", "山道");
        set("long",@LONG
這裡是通往山上的山道，路上的臺階看來年久失修，看來很少人來
到此地，道路兩旁十分狹窄，因此走起來非常緩慢，看來要到山上該要
花不少時間，北邊有一條路往山上，東北則是往山腰。
LONG
        );
  
set("exits", ([
  "northup" : __DIR__"mu5",
  "northeast" : __DIR__"mu11",
  "south" : __DIR__"mu3",
]));
set("chance",50);
        set("mob_amount",3);
        set("mob_object",({
  __DIR__"animal/sciurine",
}) );
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
}
 







