inherit ROOM;
void create()
#include <ansi.h>
{
        set("short",HIC "天上天"NOR);
     set("light",1);
        set("long", @LONG
這是一個未知的地方，只見四處花草芬芳，一對對的小鹿正四處的遊玩，
看起來沒什麼地方不同，但是為什麼秦棺會通往這裡呢？	
LONG
        );
        set("no_clean_up", 0);
      set("item_desc", ([
"毒鬼花" : "這是一朵有毒的花，小心別被刺傷，不然大羅金仙也難救阿。\n",
      ]));
        setup();
}
