#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIW"剎月"HIC"星海"NOR,({"elder box","box"}));
        set("unit", "個");
        set("long",@LONG
        
  當你一打開這個寶箱，你被一道亮光照耀著，使你張不開眼睛，
  等你恢復過來，盡入眼底的是整個宇宙，雖然只是個箱子，不過
  竟然如此之大，真令人嘆為觀止，仔細的瞧了瞧，發現裡頭擺了
  許多珍奇的寶物。


  放東西: put [東西] in box
  拿東西: get [東西] from box

LONG
);
        set("value", 1);
        set("no_sac", 1);
        set("no_get", 1);
        set("no_clean_up",1);
        set_max_encumbrance(999999);
      set_max_capacity(400);  // 2003.4.16 10000->400  by ksj
        setup();
}
