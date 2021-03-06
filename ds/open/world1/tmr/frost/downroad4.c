// Room: /open/world1/tmr/freezetaoism/downroad4.c
#include <ansi.h>
        inherit ROOM;

void create()
{
        set("short", "地下祕室");
        set("long", @LONG
整間密閉的石室充斥著一股聞之欲吐的血腥味，濃冽的妖氣更是四處
橫竄，耳裡不時聽到喪人心膽的鬼哭聲。在祕室中央擺放著一個大鐵箱，
鐵箱子上密密麻麻地貼滿了符咒，蓋子上還有個奇形怪狀的插槽。
LONG
        );
        set("current_light", 2);
        set("exits", ([ /* sizeof() == 1 */
          "north" : __DIR__"downroad3",
        ]));
        set("no_clean_up", 0);
        set("no_recall",1);
        set("item_desc",([
        	"插槽":"一個約有碗口大般的插槽，做在鐵箱蓋\子上，不知有何用處。\n",
        ]));
        setup();
}

void init()
{
        add_action("do_insert","insert");
}

int do_insert(string arg)
{
        object me=this_player(),ob,wp;
        if(!arg) return 0;
        if(arg!="staff into 插槽") return 0;
        if(me->is_fighting() || me->is_busy() )
                return notify_fail("你正忙著，沒有空做這動作。\n");
        if(query_temp("clone_tian_demon" ) ) return 0;
        
        // 須使用 七七嬰杖(seven staff)
        if(!objectp(wp=present("_SEVEN_STAFF_",me)) )
        {
                if(objectp(wp=present("staff",me) ) )
                {
                        //使用其他種類的杖
                        message_vision("$N將$n"NOR"插入到箱子上的插槽，但是並沒有任何事發生。\n",me,wp);
                        return 1;
                }
                else return 0;
        }
        
        //天妖 (tian demon)
        ob=find_living("_NPC_TIAN_DEMON_");
        // 天妖已經出現了
        if( objectp(ob) ) {
                // 天妖在不合法的房間
                if(!environment(ob) ) {
                        destruct(ob);
                } else {
                        message_vision("$N將$n"NOR"插入到箱子上的插槽，但是並沒有任何事發生。\n",me,wp);
                        return 1;
                }
        }
        // 叫出 天妖 
        message_vision(CYN "$N將$n"CYN"穩穩地插入到箱子上的插槽上......。\n",me,wp);
        message_vision(HIR "\n$n"+HIR"上血淋淋的數十隻嬰靈接二連三的復甦，在整座密室裡疾速地流竄！！\n\n"NOR,me,wp);
        set_temp("clone_tian_demon",1);
        call_out("clone_tian_demon",3,me);
        me->add_busy(2);        
        //摧毀 七七嬰杖 媒介
        destruct(wp);
        return 1;
}

int clone_tian_demon(object me)
{
        object ob=new(__DIR__"npc/tian-demon");
        if(!ob ) {
                message_vision(CYN"最後什麼事也沒有發生。\n"NOR,me);
                delete_temp("clone_tian_demon");
                return 1;
        }
        message_vision(
                HIY "\n數道光芒從鐵箱子中激射出來，流竄的嬰靈逐一地消失在虛空之中...\n"NOR
                + HIM "\n忽然妖氣大盛，整間石室劇烈地搖動起來，由邪氣聚成的人形緩緩出現在你面前！\n\n"NOR
        ,me);
        ob->move(__DIR__"downroad4" );
        delete_temp("clone_tian_demon");
        return 1;
}


