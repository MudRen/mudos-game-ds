/* 控制 碎骨寨(CRUSH_BONE) 活動的 MOB.  by -Acme- */

#include <npc.h>
#include <ansi.h>

inherit F_FIGHTER;
inherit F_SAVE;

int start = -1;

string file_path = "/d/crush_bone/";         // 求援的npc位置

/* mob的檔案位置 */
string *mob_file = ({ "orc_follower.c",
                      "orc.c",
                      "orc_hundred_leader.c",
                      "orc_thousand_leader.c",
                      "orc_commander.c",
                      "orc_herald.c",
                      "orc_envoy.c",
                      "orc_emperor.c"
                   });

/* mob所要產生的數量 */
int *mob_amount = ({ 15, 15, 20, 25, 20, 10, 5, 1 });

/* mob產生後要移到的位置 */
string *mob_born1 = ({ "map_22_1.c",
                       "map_11_1.c",
                       "map_1_1.c",
                       "map_1_12.c",
                       "map_1_22.c",
                       "map_11_22.c",
                       "map_22_22.c",
                       "map_22_12.c"
                   });

string *mob_born2 = ({ "map_7_9.c",
                       "map_9_16.c",
                       "map_11_9.c",
                       "map_13_16.c",
                       "map_16_14.c",
                       "map_16_10.c",
                       "map_13_7.c",
                       "map_7_7.c"
                   });

/* 積分記錄 */
mapping record;

/* 獎品列表 */
mapping gift = ([
                 // 魔女的讚揚
                 "1" : ([ "name" : "魔女的讚揚(55th card)",
                          "need" : 300 ,
                          "file" : "/d/cards/card-55.c", ]),
                 // 瀕死的體驗
                 "2" : ([ "name" : "瀕死的體驗(16th card)",
                          "need" : 100 ,
                          "file" : "/d/cards/card-16.c", ]),
                 // 可儲存的袋子
                 "3" : ([ "name" : "痛心碎骨袋(heartache crush bone bag)",
                          "need" : 100,
                          "file" : "/d/crush_bone/npc/obj/bag.c", ]),
                 // 半獸人之淚
                 "4" : ([ "name" : "強獸人之淚(Strong-orc tears pill)",
                          "need" : 10,
                          "file" : "/d/obj/orc-tear.c", ]),
                 "5" : ([ "name" : "海公公的寶貝袋(Seaman's scrotum)",
                          "need" : 20,
                          "file" : "/d/obj/seamanbaby.c", ]),
                   "6" : ([ "name" : "堅若磐石(94th card)",
                              "need" : 200,
                            "file" : "/d/cards/card-94.c", ]),


               ]);

int do_start();
void do_say();
int do_trigger(string arg);

void create()
{
    set_name( "傑森" , ({ "jason" }) );
    set("long",@long
    有著深綠色的粗糙皮膚，滿臉橫肉，一付兇神惡煞的樣子，但是長像
卻和半獸人有相當程度的差異。只聽到他嘴裡喃喃自語，也不知在說啥。
long
);
    set_race("strength");
    set("title", "強獸人" );
    set("age", 38);

    if( !restore() ) {
        record = ([]);
        this_object()->save();
    }


    set("chat_chance", 5);
    set("chat_msg", ({
       (: do_start :),
       (: do_say :), 
    }));

    setup();

    set_living_name("_CRUSH_BONE_CONTROLER_");
}

string query_save_file() { return __DIR__"jason"; }

void init()
{
    if( wizhood(this_player()) == "(admin)" ) add_action( "do_trigger", "trigger" );
    if( wizhood(this_player()) == "(admin)" ) add_action( "do_wizset", "wizset" );
    if( wizhood(this_player()) == "(admin)" ) add_action( "do_wizclear", "wizclear" );
    add_action( "do_list", "list" );
    add_action( "do_receive", "receive" );
}

void do_say()
{
    do_chat( ({ "傑森說道：「什麼叫半獸人，哼！哼！一個一個抓來宰了！」\n",
                "傑森說道：「半獸人？別笑死人了，在獸人族裡就只有「強獸人」而已！」\n",
                "傑森說道：「這世界上不允許有半獸人的存在！」\n",
    }) );
}

void relay_say(object ob, string arg)
{
    if( arg == "半獸人" )  {
        do_chat( ({ "傑森說道：「半獸人是個低劣的種族，獸人就獸人還有一半的？實在是搞不懂。」\n",
                    "傑森說道：「要是你斬殺了半獸人，拿證明來給我看，我會給你好處的。」\n",
        }) );
        return;
    }

    if( arg == "強獸人" ) {
        do_chat( ({ "傑森說道：「我們強獸人是世界上最偉大高尚的種族了，你這低等的傢伙離我遠一點。」\n", }) );
        return;
    }
}

int give_check(object ob)
{
    if( ob->id("_CRUSH_BONE_SHINBONE_") ) return 1;        // 脛骨
    else if( ob->id("_CRUSH_BONE_FOOT_") ) return 2;       // 腳掌
    else if( ob->id("_CRUSH_BONE_SKULL_") ) return 3;      // 頭顱
    else if( ob->id("_CRUSH_BONE_RIB_") ) return 4;        // 肋骨
    else if( ob->id("_CRUSH_BONE_WAR_PLAN_") ) return 5;   // 作戰計畫
    else if( ob->id("_CRUSH_BONE_BLOOD_") ) return 6;      // 血液
    else return 0;
}

void add_reputation(object me, int value)
{
    me->gain_score("reputation", value );
    tell_object(me, HIW"(你獲得了 " + value + " 點的聲望值。)\n"NOR);
}

void add_exp(object me, int value)
{
    me->improve_level(value);
    tell_object(me, HIW"(你獲得了 " + value + " 點的經驗值。)\n"NOR);
}

int give_gold(object me, int amount)
{
    object item;

    if( file_size("obj/money/gold.c") < 0 ) return 0;
    if( catch(item = new("/obj/money/gold.c")) ) return 0;

    item->set_amount(amount);

    if( item->move(me) ) {
        message_vision("$N從口袋裡掏出了一些黃金，拿給了$n。\n", this_object(), me);
    } else {
        if( item->move(environment(me)) ) {
            message_vision("$N從口袋裡掏出了一些黃金，拿給了$n，但是掉在地上了。\n", this_object(), me);
        } else {
            destruct(item);
            return 0;
        }
    }
    return 1;
}

int give_ht_pill(object me, int amount)
{
    object item;

    if( file_size("/d/crush_bone/npc/obj/ht_pill.c") < 0 ) return 0;
    if( catch(item = new("/d/crush_bone/npc/obj/ht_pill.c")) ) return 0;

    item->set_amount(amount);

    if( item->move(me) ) {
        message_vision("$N從褲襠裡掏出了一些飢渴丹，拿給了$n。\n", this_object(), me);
    } else {
        if( item->move(environment(me)) ) {
            message_vision("$N從褲襠裡掏出了一些飢渴丹，拿給了$n，但是掉在地上了。\n", this_object(), me);
        } else {
            destruct(item);
            return 0;
        }
    }
    return 1;
}


void add_record(object me, int value)
{
    string id = me->query_id();
    if( undefinedp(record[id]) ) record[id] = value;
    else record[id] = record[id] + value;
    tell_object(me, HIW"(你獲得了 " + value + " 點的積分。)\n"NOR);
    this_object()->save();
}

int give_gift(object me, string no)
{
    object item;

    if( file_size(gift[no]["file"]) < 0 ) return 0;
    if( catch(item = new(gift[no]["file"])) ) return 0;

    if( item->move(me) ) {
        message_vision("$N從背後拿出" + item->name() + "給$n。\n", this_object(), me);
    } else {
        if( item->move(environment(me)) ) {
            message_vision("$N從背後拿出" + item->name() + "給$n，但是掉在地上了。\n", this_object(), me);
        } else {
            destruct(item);
            return 0;
        }
    }
    return 1;
}

int accept_object(object me, object ob)
{
    if( is_busy() ) {
        tell_object(me, "對方正在忙碌中，請等一下。\n");
        return 0;
    }
    if( is_fighting() ) {
        do_chat((: command, "say 別吵！沒看到我正在打架啊！" :));
        return 0;
    }

    if( give_check(ob) && !ob->move(this_object()) ) {
        tell_object(me, "對方似乎沒辦法一次拿這麼多的東西，或許是太重了，可以試著分攤的給。\n");
        return 0;
    }


    me->start_busy(1);
    this_object()->start_busy(1);

    switch( give_check(ob) ) {
        case 0:
            do_chat((: command, "say 這是什麼玩意兒，拿開！" :));
            return 0;
        break;

        case 1: 
            if( start == -1 ) { if( !give_ht_pill(me, ob->query_amount()) ) return 0; }
            else add_record(me, ob->query_amount());
        break;

        case 2:
            if( start == -1 ) { add_exp(me, ob->query_amount()*100 ); }
            else add_record(me, ob->query_amount());
        break;

        case 3:
            if( start == -1 ) { if( !give_gold(me, ob->query_amount()*3) ) return 0; }
            else add_record(me, ob->query_amount());
        break;

        case 4:
            if( start == -1 ) { add_reputation(me, ob->query_amount()*5); }
            else add_record(me, ob->query_amount()*10);
        break;

        case 5:
            if( start == -1 ) { return 0; }
            else add_record(me, ob->query_amount()*25);
        break;

        case 6:
            if( start == -1 ) {
                if( do_trigger("on") ) { call_out("do_trigger", 1800, "off"); }
                return 1;
            }
            else add_record(me, ob->query_amount()*50);
        break;
    }

    message_vision("$N高興的看著" + ob->short() + "笑道：「哈哈，這就對了，半獸人就是該死啊！」\n", this_object() );

    ob->set_amount(0);
    do_chat( ({ ( : destruct , ob : ), }) );

    return 1;
}

int do_trigger(string arg)
{
    if( arg == "on" && start == -1 ) {
        start = 1;
        message("system", "\n"HIW+this_object()->name()+"狂笑道：殺吧！殺吧！把碎骨寨的半獸人殺光吧！！\n\n"NOR ,users());
    }

    if( arg == "off" && start == 1 ) {
        start = -1;
        message("system", "\n"HIW+this_object()->name()+"狂笑道：哈哈哈！今兒個就饒了碎骨寨的半獸人吧，到此為止！！\n\n"NOR ,users());
    }
    save();
    return 1;
}

int do_wizset(string arg)
{
    int value;
    string player;

    if( sscanf(arg, "%s %d", player, value) != 2 ) return 0;
    
    record[player] = value;
    this_object()->save();

    return notify_fail("wizset ok.\n");
}

int do_wizclear(string arg)
{
    if( arg ) map_delete(record, arg);
    else 
    record = ([]);
    return notify_fail("wizclear ok.\n");
}
int do_list(string arg)
{
    int i, j, size;
    string *players, msg, temp;

    if( start != 1 ) return 0;

    players = keys(record);
    size = sizeof(players);
    
    for(i=0;i<size-1;i++)
        for(j=i+1;j<size;j++) {
            if( record[players[i]] < record[players[j]] ) {
                temp = players[i];
                players[i] = players[j];
                players[j] = temp;
            }
        }

    msg  = "斬殺碎骨寨半獸人排行：\n";
    msg += "----------------------\n";

    for(i=0;i<size;i++)
      if( this_player()->query("id") == players[i] )
            msg += sprintf(HIY"%3d. %-12s: %-5d\n"NOR, i+1, players[i], record[players[i]]);
        else
            msg += sprintf("%3d. %-12s: %-5d\n", i+1, players[i], record[players[i]]);

    msg += "----------------------\n";
    
    this_player()->start_more(msg);

    return 1;
}

int do_receive(string arg)
{
    int i, size;
    string *no, msg;

    if( start != 1 ) return 0;

    no = keys(gift);
    size = sizeof(no);

    if( !arg || undefinedp(gift[arg]) ) {
        msg = "可換取的獎勵列表：\n";
        msg += "------------------------------------------------------------\n";
        msg += " 編號    積分    物品                             \n";
        msg += "------------------------------------------------------------\n";
        for(i=0;i<size;i++)
            msg += sprintf("%5s    %4d    %s\n", no[i], gift[no[i]]["need"], gift[no[i]]["name"] );
        msg += "------------------------------------------------------------\n";
        this_player()->start_more(msg);
    } else {
        if( undefinedp(record[this_player()->query_id()]) ) return notify_fail("你的積分不足，無法換取獎勵。\n");
        if( record[this_player()->query_id()] < gift[arg]["need"] ) return notify_fail("你的積分不足，無法換取獎勵。\n");
        if( give_gift(this_player(), arg) ) {
            record[this_player()->query_id()] = record[this_player()->query_id()] - gift[arg]["need"];
            if( record[this_player()->query_id()] <= 0 ) map_delete(record, this_player()->query_id());
        }
        else return notify_fail("你在領取獎勵時，似乎發生了什麼意外。\n");
    }

    return 1;
}

int do_start()
{
    int i, amount, count=0;
    string file;
    object mob, room;

    if( start != 1 ) return 1;

    do_chat( ({ "傑森說道：「觀看排名：list ，獎品列表：receive ，領賞：receive <編號> 」\n", }) );

    for(i=0;i<sizeof(mob_file);i++) {

        file = file_path + "npc/" + mob_file[i];
        amount = sizeof(children(file));

        if( amount < mob_amount[i] ) {
            amount = mob_amount[i] - amount;

            // 產生至一定數量的 Mob
            while( amount-- ) {

                count++;
                if( count > 30 ) { return 1; }
                mob = new(file);

                // 千夫長等級以下的MOB
                if( i<=3 ) room = load_object( file_path + mob_born1[random(sizeof(mob_born1))] );
                // 軍團長等級以上的MOB
                else room = load_object( file_path + mob_born2[random(sizeof(mob_born2))] );

                if( !mob->move(room) ) {
                    destruct(mob);
                    continue;
                }
            }
        }        
    }
}

