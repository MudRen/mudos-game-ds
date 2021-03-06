// tmr 2006/11/14

#include <ansi.h>

// 獎勵
private void do_bonus(object room)
{
        object *obs;
        string msg;
        int r,i, chance;

        obs = all_inventory(room);
        if (sizeof(obs) < 1) {
            message("world:world1:vision",HIM"【謠言】"+"聽說"HIY"凌雲峰頂佛光"HIM"出現，令人嘆為觀止，讚嘆不已。\n"NOR ,users());
        	return;
        }
        
        chance = sizeof(obs);
        if(chance > 20 ) chance = 20;
        
        r = random(365);
          if (r < chance )
        {
                //msg = HIY "【自然奇觀】凌雲峰頂日出\n"NOR;
                msg = HIR "\n\t只見太陽一點一點的升了起來，倏的眼前一亮，一道光暈出現在雲際，\n"
                          "\t朦朦矓矓似乎有一個佛影立在當中，令人嘆羨不已。\n" NOR;
                msg += HIG "\t你冥冥中彷彿得到了佛祖的指示，登時有茅塞頓開的感覺。\n\n" NOR;

                // 增加聲望跟戰鬥藝術
                for ( i = 0 ; i < sizeof(obs); i++)
                {
                        if( !living(obs[i]) || !userp(obs[i]) ) continue;
                                        obs[i]->add("popularity", 20 + random(10) );
                                        obs[i]->add("war_art", 20 + random(10) );
                                        obs[i]->add("exp", 30000 + random(10000) );
                    }
                    
                tell_object(room, msg);
                message("world:world1:vision",HIM"【謠言】"+"聽說"HIY"凌雲峰頂佛光"HIM"出現，令人嘆為觀止，讚嘆不已。\n"NOR ,users());
        } else
        if (r < 250)
        {
                //msg = HIY "【自然奇觀】凌雲峰頂日出\n"NOR;
                msg = HIG "\n\t你在凌雲峰山上欣賞日出令人心曠神怡，格外領略凌雲峰的雋秀險奇。\n"NOR;
                
                switch (random(3))
                {
                case 0:
                        msg += HIW "\t一輪"HIR"紅日"HIW"躍出天際，映射得層巒疊翠分外妖嬈，茫茫雲海，盡披紅妝。\n" NOR;
                        break;
                case 1:
                        msg += HIW "\t忽然間一輪"HIR"紅日"HIW"躍了上來，天地之間登時輝煌無比，只射得你眼睛都無法睜開。\n" NOR;
                        break;
                default:
                        msg += HIW "\t驀然眼前金光四射，一輪"HIR"紅日"HIW"冉冉升起。\n" NOR;
                        break;
                }
                msg += HIG "\t你心頭閃過一道靈光，似乎受到了某種啟迪。\n\n" NOR;
                
                for ( i = 0 ; i < sizeof(obs); i++)
                {
                        if( !living(obs[i]) || !userp(obs[i]) );
                                        obs[i]->add("popularity", 3 + random(3) );
                                        obs[i]->add("war_art", 3 + random(3) );
                                        obs[i]->add("exp", 5000 + random(5000) );
                                }

                tell_object(room, msg);
                message("world:world1:vision",HIM"【謠言】"+"聽說"HIY"凌雲峰頂佛光"HIM"出現，令人嘆為觀止，讚嘆不已。\n"NOR ,users());
        } else {
                switch (random(3))
                {
                case 0:
                        msg = WHT "\n\t眼見太陽朦朦矓矓的就要升上來，卻見一片烏雲飄過，遮了個紮紮實實。\n" NOR;
                        break;
                case 1:
                        msg = WHT "\n\t你眼前越來越亮，但是霧氣好重，讓你什麼都看不清楚。\n" NOR;
                        break;
                default:
                        msg = WHT "\n\t天邊漸漸的發白，但是一層一層的雲氣將日頭壓得光芒一絲都看不見。\n" NOR;
                        break;
                }
                msg += HIG "\t你心中連嘆：「太可惜了！」\n\n" NOR;
                tell_object(room, msg);
        }
}

//事件觸發
void trigger_event()
{
        object room;

        // 凌雲峰頂日出
        if (objectp(room = find_object("/open/world1/tmr/advbonze/summit1")))
                do_bonus(room);
}

void create() 
{ 
        seteuid(getuid()); 
//      message("channel:sys", HIR"【自然奇觀】凌雲峰頂日出。\n"NOR, users());
//      trigger_event();
}
