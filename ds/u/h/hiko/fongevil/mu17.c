inherit MOBROOM;
void create()
{
        set("short", "後山");
        set("long",@LONG
這裡是屬於後山的地方，幾乎看起來是渺無人跡，動物也相當的多
，在你眼前有著一些山中小動物活躍著，讓你也想放開胸懷和它們一起
倘佯在大自然裡，附近似乎傳來陣陣野獸吼聲。
LONG
        );
  
set("exits", ([
  "northeast" : __DIR__"mu18",
  "westdown" : __DIR__"mu16",
   ]) );
  set("chance",50);
        set("mob_amount",1);
        set("mob_object",({
  __DIR__"animal/big-snake",
}) );
       set("no_clean_up", 0);
        set("outdoors","land");
        setup();
}
 








