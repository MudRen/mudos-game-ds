inherit ROOM;
void create()
{
       set("short","超•光子練習場『醫護室』");
      set("long",@LONG
這裡是超•光子練習場的醫護室，一進到這裡就聞到一股刺鼻的藥味
，旁邊有兩名醫療術士正在用『神•醫療力』搶救一名被光子槍誤射的新
手，旁邊掛著一個牌子(sign)。
LONG);
set("item_desc",([ 
"sign":"醫療劑：1000電子幣。\n"
]) );
set("objects",([
__DIR__"npc/doctor.c"      :1,
]));
        set("world", "future"); 
set("exits",([
      "west":__DIR__"5.c",
]) );
setup();
}
