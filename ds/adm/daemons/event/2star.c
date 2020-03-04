#include <ansi.h>

// 獎勵
private void do_bonus(object room)
{
        object *obs;
        string msg;
        int r,i;
        int chance;

        obs = all_inventory(room);
        chance = sizeof(obs);
        if(chance > 20 ) chance = 20;
        if (sizeof(obs) < 1) {
                message("world:world1:vision",HIM"【謠言】"+"傳聞紫陽山頂夜空"HIW"牛郎織女星"HIM"相會，良宵美景，蘊意深長。\n"NOR,users());
                return;
        }
        
        if( random(100) < 40) {
                msg =  HBK "\n\t眼見夜空一片漆黑，讓你什麼都看不清楚。\n" NOR;
                msg += HIG "\n\t你不禁嘆息道：「太可惜了...」\n" NOR;
                tell_object(room, msg);
                return;
        }

        msg = HIW "\n\t在頭頂附近，銀河中間與兩邊有３顆明亮的星星，其中最亮的一顆呈青白色，\n"
                   "\t她在銀河西北邊，這就是織女星。另一顆亮星在織女星的南偏東，即銀河的東南\n"
                   "\t邊，他就是牛郎星。\n";

        // 大奇
       if( random(365) < chance ) {
                msg += HIM "\n\t纖雲弄巧，飛星傳恨，銀漢迢迢暗度。金風玉露一相逢，便更勝卻人間無數。\n"
                       "\t柔情似水，佳期如夢，忍顧鵲橋歸路！兩情若是久長時，又豈在朝朝暮暮。\n";
                 msg += HIG "\n\t你清楚地望見牛郎織女星鵲橋相會，心中感動莫名，武藝更上一層樓了。\n\n" NOR;
               for ( i = 0 ; i < sizeof(obs); i++)  {
                        if( !living(obs[i]) || !userp(obs[i]) ) continue;
                                obs[i]->add("popularity", 10 + random(3) );
                                obs[i]->add("war_art", 10 + random(3) );
                                obs[i]->add("exp", 50000 + random(40000) );
                }
        } else {
               msg += HIG "\n\t你隱約見得牛郎織女雙星相會，心有所感之餘，也增長了武藝的造詣。\n\n" NOR;
               for ( i = 0 ; i < sizeof(obs); i++)  {
                        if( !living(obs[i]) || !userp(obs[i]) ) continue;
                                obs[i]->add("popularity", 3 + random(3) );
                                obs[i]->add("war_art", 3 + random(3) );
                                obs[i]->add("exp", 20000 + random(25000) );
                }
        }

        tell_object(room, msg);
        message("world:world1:vision",HIM"【謠言】"+"傳聞紫陽山頂夜空"HIW"牛郎織女星"HIM"相會，良宵美景，蘊意深長。\n"NOR,users());
}

// 事件觸發
void trigger_event()
{
        object room;

        if (objectp(room = find_object("/open/world1/cominging/purple_sun/4fs")))
                do_bonus(room);
}

void create() 
{ 
        seteuid(getuid()); 
}


