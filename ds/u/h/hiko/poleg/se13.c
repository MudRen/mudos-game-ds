inherit ROOM;
void create()
{
        set("short", "泊浪村海灘");        
        set("long",@LONG
這裡是已經是海灘的尾端，海灘上的生物也都比較少了，附近的人
們也沒有剛剛那麼多了，而事實上這裡的景色卻是最宜人，由於少人來
使得這裡的天然樣子十分完善，四周的岩豁各有特色，而海浪聲輕輕襲
來讓人感到很平靜。
LONG
        );
        set("exits", ([
   "northeast" : __DIR__"se12",
   "south" : __DIR__"se14", 
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}









