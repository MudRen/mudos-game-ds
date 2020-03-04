inherit ROOM;
void create()
{
        set("short", "後山");
        set("long",@LONG
你來到後山十分裡面的地方，這裡枝葉茂密樹叢遮天，自然的生機
非常蓬勃，在你眼前有著一個山洞，裡面傳來陣陣的野獸吼聲，看
來可能有什麼猛獸在內棲息，讓你感到好奇。
LONG
        );
  
set("exits", ([
  "enter" : __DIR__"holl",
  "southwest" : __DIR__"mu17",
   ]) );
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}
 







