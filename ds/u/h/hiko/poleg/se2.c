inherit ROOM;
void create()
{
        set("short", "泊浪村港口");        
        set("long",@LONG
這裡是柏浪村港口的卸貨區，依然沒有任何大船，泊浪村的的漁夫
們在這裡辛勤的工作著，他們來來去去的整理漁具以及準備出海，這是
他們所能發揮最大力量的時候，在這裡每個人都十分努力，他們深知要
想有好生活就要工作，東邊是一片海灘。
LONG
        );
        set("exits", ([
  "north" : __DIR__"se9",
   "northeast" : __DIR__"se3",
   "west" : __DIR__"se1", 
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}






