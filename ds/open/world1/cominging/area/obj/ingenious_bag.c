#include <ansi.h>
inherit ITEM;
void create()
{
         set_name(HIC"巧手"HIW"如意袋"HIM"【"HIY + query("player_id") + HIM"】"NOR, ({ "ingenious bag","bag" }) );
        set_weight(800);
        set_max_capacity(450);
        set_max_encumbrance(550000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "口");
                set("long", "這是劉靖文特別製作的袋子，共分成四層，內部以神風袋和獸王的胃\n"
                            "裁剪後重新縫合，最內部墊上銀狼的毛皮，在外面包覆羽雕皮再以蟒\n"
                            "錦皮革包裹，上面還有銀絲繡成的圖案，袋口再用血蛟軔帶紮緊，袋\n"
                            "底還有特別用金絲繡上的名字，不過眼尖的你在名字下面還看到了一\n"
                            "排小字「步靈城織布紡劉靖文製作」。\n");
                set("value",8000);
               }
        set("player_id", "unknown");
        setup();
}

int query_unique() { return 1; }  // 視為 daily eq


