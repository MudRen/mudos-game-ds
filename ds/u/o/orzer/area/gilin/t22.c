inherit ROOM;
void create()
{
        set("short","祭靈森林東側");
        set("long",@LONG
這裡已經接近森林的最內側，從地面隱約傳來陣陣涼風，而地上有
一個奇怪的符號，不知道代表著什麼意思，森林東邊傳來奇特的鳴叫聲
，不知道棲息著什麼生物。
LONG
        );
        set("exits", ([
  "east" : __DIR__"t21",
   ]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        set("item_desc", ([
            "符號" : "一個奇特的符號，你從來都沒看過，中間有著一個矩形的小孔\n", 
            "小孔" : "奇特形狀的小孔，看來頗為不尋常，也許\可以試著放(put)東西進去\n",            
        ]));   
        setup();
}




