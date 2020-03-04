// v1.02 版
// 1. Luky del idle
// v1.01 版
// 1. 增加 疾風 adv
// QC: Luky [10.21.1999] 開放實際測試.
/* 疾風門 ： 殘月心法(moon_force) 由 Cominging 於 1999/5/29 日所創 */
//修正殘影訣強度 by linjack
// luky del idle
// 如果一定要蹲. 不蹲會很難過. 那就請你們開發一套讓玩家
// 用指令來運氣的系統. 比如說什麼時候該運氣到 ( motion 天靈 )
// 這個系統要讓玩家不能用 robot，也就是不能用相同的提示訊息.

#include <ansi.h>
inherit SKILL;
inherit SSERVER;

void delay(object me);
void arc(object me,object target);
void long_arc(object me, object *tar);
void rewield(object me, object weapon);
void moon_shadow(object me, int ar1, int ar2);
void help(object me);

string *random_train_msg = ({
                                "你正在膳養內息，暫時不能移動。",
                                "你現在正在練功當中，無法做任何移動的動作！",
                                "邊練功邊走路？",
                                "假如你想要行動，請先停止練功，否則將運氣不順而走火入魔了！"
                            });

string help_msg = @SKILL_HELP

                  殘月心法使用方法:       exert moon_force <參數>
                  參數:
                  recover         消耗AP來回覆HP
                  moon-arc        將手臂上的內力化為月型氣勁震落敵人武器
                  long-arc        長月型氣勁, 將可攻擊全體 ( 進階 )
                  shadow          可以增加閃躲的技能 - 殘影訣 ( 進階 )

                                            PS. ( 進階 ) - 為進階才可使用。

                                            SKILL_HELP;

                                            int exert(object me,object target, string arg)
                                            {
                                                int heal,reheal,sk,lv;
                                                int p, ar1=0, ar2=0;
                                                object weapon, *tar;
                                                sk = me->query_skill("moon_force");

                                                //這種有參數的exert skill.. 請加上參數說明. Luky
                                                return notify_fail("BUG 太多, 待修..!\n");
                                                if( arg == "?" )
                                                {
                                                    write(help_msg);
                                                    return 1;
                                                }

                                                if( arg=="off" )
                                                {
                                                    if( me->query_skill_mapped("force")!="moon_force" )
                                                        return notify_fail("你並沒有在運功\。\n");
                                                    me->delete_temp("is_busy/moon_force");
                                                    message_vision(HIY"$N閉起的兩眼慢慢睜開，內息又流回經脈中了。\n"NOR,me);
                                                    me->map_skill("force");
                                                    return 1;
                                                }

                                                if( me->query_skill_mapped("force")=="moon_force" )
                                                    return notify_fail("你現在還在修煉殘月心法中。\n");

                                                if( !arg )
                                                {
                                                    return notify_fail(help_msg);
                                                    if( me->is_fighting() )
                                                        return notify_fail("你現在正忙著打架, 沒空練功\。\n");
                                                    if( me->query("hp") < 20 || me->query("ap") < 20 )
                                                        return notify_fail("你目前的狀況不佳，無法修煉心法。\n");
                                            if( !me->skill_active( "moon_force",(: call_other, __FILE__, "delay", me :), 3) )
                                                        if( me->query_temp("class_wind/on_shadow") )
                                                            return notify_fail("目前你正在使用殘影訣！\n");
                                                        else return notify_fail("你結束運功\的動作還沒完成。\n");
                                                    //		if( me->query_skill("moon_force",1) < 85 )
                                                    //			return notify_fail("你的殘月心法根本還不用自己修煉, 去找老師學吧。\n"); //廢止Idle Skill. Luky

                                                    message_vision(HIC"$N隨地盤腳坐下，氣運百骸，聚檀中而養息。\n"NOR,me);

                                                    me->map_skill("force","moon_force");
                                                    me->receive_damage("ap", 5);
                                                    me->receive_damage("hp", 2);
                                                    me->set_temp("is_busy/moon_force", random_train_msg[random(sizeof(random_train_msg))]);
                                                    me->start_busy(2);
                                            me->skill_active( "moon_force",(: call_other, __FILE__, "delay", me:), 2);
                                                    return 1;
                                                }

                                                if( arg=="recover" )
                                                {
                                                    sk = (int)me->query_skill("moon_force");
                                                    sk = (sk > 50) ? 50 + (( sk-50 )/2) : sk;
                                                    lv = (int)me->query("level");
                                                    heal = (int)me->query("max_hp");
                                                    heal = (heal > 4000) ? 4000 + (heal-4000)/8 : heal;
                                                    reheal = (heal / 20) + ((sk/5)*3) + random(9) + (lv/2);

                                                    if( me->query("ap") < 20 )
                                                        return notify_fail("你目前的狀況不佳，無法使用殘月心法。\n");
                                                    if( me->query_skill("moon_force") < 10 )
                                                        return notify_fail("你的殘月心法基礎不夠！\n");
                                                    if( me->query("hp") >= heal )
                                                        return notify_fail("你目前的生命狀況已經是極限了。\n");

                                                    me->receive_heal("hp",reheal);
                                                    me->receive_damage("ap",27 + reheal/7 + random(4));
                                                    me->start_busy(2);

                                                    message_vision(HIR"$N一時間靜下心來，運氣點了身上各傷口旁的大穴。\n"NOR,me);

                                                    me->improve_skill("moon_force",me->query("int")/8 + random(3));
                                                    me->improve_skill("force",me->query("int")/7 + random(3));

                                                    return 1;
                                                }

                                                if( arg=="moon-arc" )
                                                {
                                                    if( !me->is_fighting() )
                                                        return notify_fail("你並沒有在戰鬥中。\n");
                                                    if( me->query_skill("moon_force") < 45 )
                                                        return notify_fail("你的殘月心法並不夠成熟！\n");
                                                    if( !target ) target = offensive_target(me);
                                                    if( !target ) return notify_fail("你要對誰使用「弧月」？\n");

                                                    weapon=target->query_temp("weapon");
                                                    if( !weapon )
                                                        return notify_fail("敵方並沒有拿武器，「弧月」無法發揮效用。\n");
                                                    if( me->query("hp") < 100 || me->query("ap") < 100 )
                                                        return notify_fail("你的身體狀況不好。\n");

                                                    message_vision("\n$N雙手一合一分，隨空虛劃凝出一片「弧月」。\n"
                                                                   HIY "弧月似有生命一般，以快捷無倫的疾速攻向$n拿武器的雙手！！\n" NOR,me,target);

                                                    me->receive_damage("hp",30);
                                                    me->receive_damage("ap",50);
                                                    me->start_busy(2);
                                                    me->improve_skill("moon_force",me->query("int")/6 + random(4));
                                                    me->improve_skill("force",me->query("int")/5 + random(4) );
                                            me->skill_active( "moon_force",(: call_other, __FILE__, "arc", me,target:), 2+random(1) );
                                                    return 1;
                                                }

                                                if( arg == "long-arc" ) // wind adv 的功用: 長弧月
                                                {
                                                    if( me->query("level") < 30 )
                                                        return notify_fail("你的等級還不夠﹐無法領略長弧月！\n");
                                                    if( me->query_skill("moon_force", 1) < 90 )
                                                        return notify_fail("你對於殘月心法還無法透析﹐所以無法使用長弧月！\n");
                                                    if( !me->is_fighting() )
                                                        return notify_fail("你不在戰鬥中喔﹐想要對誰使出長弧月呢？\n");
                                                    tar = me->query_enemy();
                                                    if( !tar )
                                                        return notify_fail("你好像沒有目標耶！\n");
                                                    if( me->query("ap") < 125 )
                                                        return notify_fail("你的體力狀況不濟﹐無法使出『長弧月』。\n");

                                                    me->start_busy(1);
                                                    me->receive_damage("ap", 120);
                                                    message_vision(HIW"\n$N雙手一合一分﹐隨空虛劃凝出一大片「弧月」。\n"NOR
                                                                   "弧月似有生命一般﹐以快捷無倫的疾速攻向對手！！\n" NOR,me);
                                            me->skill_active("moon_force", (: call_other, __FILE__, "longarc", me, tar :), random(1));
                                                    return 1;
                                                }

                                                if( arg == "shadow" ) // wind adv 新增: 殘影訣
                                                {
                                                    if( me->query("level") < 30 )
                                                        return notify_fail("你的等級還不夠﹐無法使用殘影訣！\n");
                                                    if( me->query_skill("moon_force", 1) < 70 )
                                                        return notify_fail("你對於殘月心法還無法透析﹐所以無法領略殘影訣！\n");
                                                    if( me->query("mp") < 45 )
                                                        return notify_fail("你的法力不夠喔！\n");
                                                    if( me->query("ap") < 90 )
                                                        return notify_fail("你的體力不支足以使出殘影訣！\n");
                                                    if( me->query_temp("class_wind/on_shadow") )
                                                        return notify_fail("你已經使用過殘影訣了﹐無法再繼續增強了！\n");

                                                    message_vision(BLU"只見$N身形漸漸模糊﹐似乎是引出了殘月心法中的殘影訣！！\n"NOR, me);

                                                    me->add_temp("apply/dodge", ( ar1=(int)(sk*3/2 + random(sk/10)) ) );
                                                    //me->add_temp("apply/armor", ( ar2=(int)(sk/5 + random(sk/40)) ) ); // 不要加 armor point by linjack

                                                    me->receive_damage("ap", 90);
                                                    me->receive_damage("mp", 45);
                                                    if( me->is_busy() ) me->add_busy(2);
                                                    else me->start_busy(1);
                                                    me->set_temp("class_wind/on_shadow", 1);

                                            me->skill_active("moon_force", (: call_other, __FILE__, "moon_shadow", me, ar1, ar2 :), 600 - random(60));
                                                    return 1;
                                                }
                                                else return notify_fail("殘月心法沒有這種功\能！\n");

                                            }

                                            void moon_shadow(object me, int ar1, int ar2)
                                            {
                                                if( me->query_temp("apply/dodge") <= ar1 )
                                                    me->set_temp("apply/dodge", 0);
                                                else me->add_temp("apply/dodge", -ar1);

                                                if( me->query_temp("apply/armor") <= ar2 )
                                                    me->set_temp("apply/armor", 0);
                                                else me->add_temp("apply/armor", -ar2);

                                                me->delete_temp("class_wind/on_shadow");
                                                message_vision(HIB"$N的身形漸漸隱露了出來﹐顯然是殘影訣失去了效用！\n"NOR, me);

                                                return;
                                            }

                                            void arc(object me, object target)
                                            {
                                                object wp;
                                                int t, m, sk_lv;
                                                if(!me || !target ) return;

                                                sk_lv = me->query_skill("moon_force");
                                                wp = target->query_temp("weapon");
                                                t=target->query_skill("dodge")+target->query_dex();
                                                m=me->query_skill("dodge")+me->query_dex();

                                                if( !wp )
                                                {
                                                    message_vision("「弧月」凌空轉了數圈，化成一陣輕煙消失了。",me);
                                                    return;
                                                }
                                                if( random(t) < random(m) && wp->unequip() ) {
                                                    message_vision(HIC "「鏘」地一聲響，弧月撞得$N脫落了手中的武器！！\n" NOR ,target);
                                                    target->start_busy(1);
                                                    call_out("rewield", sk_lv*5/4, target, wp);
                                                } else {
                                                    message_vision(CYN "「鏘」地一聲響，弧月一撞上$N手中的武器反而被震碎了！！\n" NOR,target);
                                                    me->add_busy(1);
                                                }
                                                me->improve_skill("force",1+random(5+me->query("level"))+me->query_int()/4 );
                                                me->improve_skill("moon_force",1+random(5+me->query("level"))+me->query_int()/4 );
                                                return;
                                            }

                                            void rewield(object target,object wp)
                                            {
                                                if( !target || userp(target) || !wp ) return;
                                                if( environment(wp) != target ) return;
                                                if( wp->query("equipped") ) return;
                                                message_vision("弧月對於$N的效力漸減，$N裝備起$n。\n",target,wp);
                                                wp->wield();
                                            }

                                            void longarc(object me, object *tar)
                                            {
                                                object weapon;
                                                int x=0, q, tar_d, me_d;

                                                for(q=0;q<sizeof(tar);q++)
                                                {
                                                    if(!tar[q]) continue;
                                                    if( !(weapon=tar[q]->query_temp("weapon")) ) continue;
                                                    if( 20+random((tar_d=tar[q]->query_skill("dodge")+tar[q]->query_dex())*7/12) < random(me_d=me->query_skill("dodge")+me->query_dex())
                                                            && weapon->unequip() ) {
                                                        message_vision(HIC "「鏘」地一聲響，一道弧月撞得$N脫落了手中的武器！！\n" NOR , tar[q]);
                                                        tar[q]->start_busy(1);
                                                        //			call_out( (: rewield, tar[q], weapon :), me->query_skill("moon_force"));
                                                    } else {
                                                        message_vision(CYN "「鏘」地一聲響，弧月一撞上$N手中的武器反而被震碎了！！\n" NOR, tar[q]);
                                                        me->add_busy(1);
                                                    }
                                                    x++;
                                                }
                                                if( !x ) {
                                                    message_vision("「弧月」凌空轉了數圈，化成一陣輕煙消失了。",me);
                                                    return;
                                                }
                                                me->improve_skill("force", 1 + random(me->query("level")+x+5) + me->query_int()/5 + random(me->query_int()/10));
                                                me->improve_skill("moon_force", 1 + random(me->query("level")+x+5) + me->query_int()/5 + random(me->query_int()/10) );
                                                return;
                                            }

                                            void delay(object me)
                                            {
                                                int sk_level,lv,i;

                                                sk_level = me->query_skill("moon_force");
                                                lv = me->query("level");
                                                i = me->query_int();

                                                if( !me ) return;

                                                if( me->query_skill_mapped("force")!="moon_force" ) return;

                                                if( me->query("ap") < 13 || me->query("hp") < 13 )
                                                {
                                                    message_vision(HIR"$N心神如一道光劃過，瞿然停止了運功\。\n"NOR,me);
                                                    me->delete_temp("is_busy/moon_force");
                                                    me->map_skill("force");
                                                    return;
                                                }
                                                else if ( sk_level < 50 )
                                                {
                                                    me->receive_damage("ap",8);
                                                    me->receive_damage("hp",5);
                                                }
                                                else if ( sk_level > 49 )
                                                {
                                                    me->receive_damage("ap",12);
                                                    me->receive_damage("hp",7);
                                                }
                                                me->improve_skill("force",1 + random(5+lv/2) + (sk_level/5) + (i/3) );
                                                me->improve_skill("moon_force",1 + random(5+lv/2) + (sk_level*3/8) + (i/3) );
                                            me->skill_active( "moon_force",(: call_other, __FILE__, "delay", me :), 3);
                                            }

                                            int valid_learn(object me)
                                            {
                                                return 1;
                                            }

                                            int practice_skill(object me)
                                            {
                                                return 1;
                                            }

                                            void skill_improved(object me) // 注意, 一個skill能增加的屬性總和以 5 為上限
                                            {
                                                int b,c;
                                                b = me->query_skill("moon_force",1);
                                                c = me->query("skill/moon_force"); //luky

                                                if( b % 20==19 && b > c)
                                                {
                                                    if(random(2))
                                                    {
                                                        tell_object(me, HIR "你的動作由於領悟殘月心法有道而更加輕盈了。\n" NOR);
                                                        me->add("addition/dex", 1);
                                                    }
                                                    else
                                                    {
                                                        tell_object(me, HIR "你的體質由於領悟殘月心法有道而增強了。\n" NOR);
                                                        me->add("addition/con", 1);
                                                    }
                                                    me->set("skill/moon_force", b);
                                                }
                                                me->save();
                                            }

                                            int improve_limite(object ob)
                                            {
                                                int a;

                                                a=(ob->query("level")*3)+(ob->query_int());
                                                if( a > 90 && ob->query("level") < 26 ) a=100;
                                                else if( a > 100 ) a =100;
                                                return a;
                                            }
