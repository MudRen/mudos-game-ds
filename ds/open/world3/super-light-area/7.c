inherit ROOM;
void create()
{
     set("short","超•光子練習場『中級區』");
      set("long",@LONG
這裡都是稍有根基的中級生，與剛剛的初級生有很大的差別，四周傳
出十成光束砲的神威，令人吃驚不已，這一條道路是讓稍有根基的人練功
用的，前方有一個電子佈告欄(BBS)。
LONG);
set("exits",([
      "south":__DIR__"2.c",
      "east":__DIR__"10.c",
      "west":__DIR__"8.c",
]) );
set("item_desc",([
"BBS":"向左是lv 1x修練所，右邊是進階之路。\n"
]));
        set("world", "future"); 
set("objects",([
__DIR__"npc/lv10" :4
]) );
setup();
replace_program(ROOM); 
}
