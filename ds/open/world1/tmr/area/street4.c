inherit ROOM;

void create()
{
        set("short", "大街");
        set("long", @LONG
你走在一條人來人往的大街上，左邊就是附近最馳名的「朝天樓」，
樓高三層，門前放著兩隻大石獅，門上掛著一個金框招牌，再往上就看到
二樓的客人正在大肆朵頤。右邊則是這裡最大的錢莊－「歲寒錢莊」，由
於是「傲梅山莊」的人所經營的，所以並無宵小敢去作亂。往北是個小廣
場，往南是條大街。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"street5",
  "west" : __DIR__"hotel",
  "north" : __DIR__"square",
  "east" : __DIR__"bank",
]));
set("light",1);
        set("objects", ([ /* sizeof() == 1 */
 __DIR__"npc/dog" : 1,
]));
        set("outdoors","land");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

