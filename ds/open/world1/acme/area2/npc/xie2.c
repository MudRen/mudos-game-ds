/* write by -Acme-
   update by -Acme-
*/

#include <ansi2.h>
inherit NPC;

string *way = ({ // 地窖
                 "south", "east", "north", "west", "west", "north", "southwest", "north",
                 "west", "south", "south", "south", "west", "west", "northeast", "northup",
                 "north", "southwest", "north", "west", "south", "west", "south", "south",
                 "south", "eastup", "east", "southwest", "east", "south", "east", "east",
                 "east", "southeast", "southeast", "westup", "northwest", "west", "south",
                 "west", "north", "west", "west", "south", "west", "up",
                 // 施家
                 "north", "west", "west", "south", "south", "out",
                 // 天城
                 "west", "west", "west","west", "west", "west", "west", "southwest", "west",
                 "west", "southwest", "westdown",
                 // 步靈城
                 "southeast", "south", "south", "west", "south", "southwest", "south",
                 "south", "southwest", "southwest",
                 // 李家村
                 "south", "east", "east", "south", "south", "east", "southeast", "eastup",
                 // 雞足山
                 "southeast", "southeast", "southeast", "southeast", "east", "southup", "east",
                 "eastup", "east", "northup", "west", "north",
                 // 凌雲寺
                 "northeast", "north", "north", "west", "east", "south", "south", "southwest",
                 "northwest", "north", 
                 // 凌雲峰
                 "north", "north", "northeast", "north", "east", "east", "east", 
                 // 倚霄山
                 "east", "east", "east", "south", "south", "south", "down", "east", "down",
                 
              });

void go_open_war();
void open_war();
void create()
{
    set_name( "天殘邪佬", ({ "tan chan xie","tan","chan","xie", "__GUARD__" }) );
    set("level",65);
    set("combat_exp",5500);
    set("evil",99);
    set("long", @Long
他是幽冥地窖中的大老，他強若天神，不可一世，他與正派人士
的鬥爭，從未止歇，經過無數的大小戰爭，戰無不克，他已成為
武林中的霸主，正派人士對他都頗為忌憚，許多自成一格的掌門
人，率領著門徒，來圍勦幽冥地窖，卻落得屍骨無存。
Long);
    set("age",100);
    set("gender","男性");
    set("title",HIR"【幽冥惡王】"NOR);
    set("Merits/wit",0);
    set("int",40);
    set_skill("sword",110);
    set_skill("dodge",110);
    set_skill("parry",110);
    set("talk_reply","不必了，只要你不去動我的珍寶就行了！我生平最恨人亂動我的寶物了。\n");
    set("inquiry/珍寶", "嗯！我的珍寶可多了，哪！我手上這本書可是我收藏寶物中最喜愛了。\n");
    set("inquiry/寶物", "嗯！我的珍寶可多了，哪！我手上這本書可是我收藏寶物中最喜愛了。\n");
    set("inquiry/書", "這本書可是有神秘之處的，上頭寫的【幽】字可有是大大的秘密。\n");
    set("inquiry/幽", "我看你這小夥子蠻順眼的，我就跟你說吧！\n"
                      "              你可以在戰鬥中誠心的默唸著幽(you)，可\n"
                      "              以發出驚人之威力哦！！\n",
    );
    set("chat_chance_combat",80);
    set("chat_msg_combat", ({
        (:command("you"):),
        (:command("say 你這惡賊，接我這一招，受死吧！！！"):),
    }) );

    setup();
    set_living_name("__XIE__");
    carry_object(__DIR__"wp/darksword.c")->wield();
    carry_object(__DIR__"obj/book.c");
    carry_object(__DIR__"obj/bone.c");
}
void init()
{
    object demon;
    ::init();
    add_action("do_guard", "go");
    if( "/u/a/acme/god"->query_tune_game("群魔亂舞") ) return;
    if( !this_object()->query("open_war_ok") && objectp(demon = present("_TIAN_DEMON_", environment(this_object()))) ) {
        message_vision("$N遇見$n隨即哈哈大笑道：天妖您佬終於出山來，來吧！一起搞得天翻地覆吧！！\n", this_object(), demon);
        command("wahaha");
        message_vision(HIW"\n$N將手中的萬年枯\骨裝在$n的頭上...\n\n"NOR, this_object(), demon);
        this_object()->set("open_war_ok", 1);   //免得init() 一直執行
        call_out("open_war", 3);
        return;
    }
}

int do_guard(string arg)
{
    object me;
    object obj;
    me=this_player();
    obj=this_object();
    if( (arg!= "southwest") || !this_player()->visible(this_object()) ) return 0;
    write( name() + "將你攔了下來。\n");
    command("say 咦！？小賊！！想偷我的珍寶來著！？");
    command("say 你快走吧！下次別讓我見到你，否則！哼哼！！！");
    obj->kill_ob(me);
    return 1;
}

void die()
{
    object ob;

    if( !ob = query_temp("last_damage_from") ) ob = this_player(1);

    if( !ob ) {
        ::die();  return;
    }

    message("world:world1:vision",CYN"\n  武林傳出了一則驚人的消息:\n\n\t「幽冥惡王」天殘邪佬終於敗給了"+ob->name(1)+"。\n\n"+NOR,users());
    ob->add("popularity",3); //聲望
    ::die();
    return;
}

void go_open_war()
{
    int i, way_point;
    string msg = "";
    object move_to;

    set_temp("war_opening", 1);
    way_point = this_object()->query("way_point");

    /* 如果在戰鬥，戰鬥結束再行動 */
    if( this_object()->is_fighting() ) {
        call_out( "go_open_war", 30);
        return;
    }

    if( !way_point ) CHANNEL_D->do_channel(this_object(), "sys", "發出了行動，準備解除「天妖」的印記！\n");

    /* 走到身處的環境不見時，destruct */
    if( !environment(this_object()) ) {
        CHANNEL_D->do_channel(this_object(), "sys", "身處不明環境...destructing..." );
        destruct(this_object());
        return;
    }

    if( !this_object()->query("move_to") )
        this_object()->set("move_to", environment(this_object())->query("exits/"+ way[way_point]) );

    /* 取亂數，如此才不會定點停止，以防被圍堵 */
    for(i=0;i<=random(4)+3;i++) {

        if( way_point >= sizeof(way) ) break;

        switch( random(10) ) {
            case 1: command("hmm"); break;
            case 2: command("stare"); break;
            case 3: command("say 閃開！閃開！"); break;
            case 4: command("emote 一腳把你踢的遠遠的...\n"); break;
            case 5: command("snort"); break;
        }

        command("go " + way[way_point] );

        /* 如果用 go 會被擋住，直接將之 move */
        if( this_object()->query("move_to") != file_name(environment(this_object())) ) {

            msg += "行使移行之術...";
            message_vision("你看見$N身形漸漸模糊，往" + to_chinese(way[way_point]) +"消失了...\n", this_object());
            if( !objectp( move_to = find_object(this_object()->query("move_to"))) || !this_object()->move(move_to) ) {
                CHANNEL_D->do_channel(this_object(), "sys", "移行之術失敗...行動取消..." );
                return;
            } else msg += "成功\...";
        }

        if( way_point + 1 < sizeof(way) )
            this_object()->set("move_to", environment(this_object())->query("exits/"+ way[way_point+1]) );

        msg += "go " + way[way_point] + " ，走到了" + environment(this_object())->query("short") + "...\n";

        /* 七七嬰杖之處 */
        if( file_name(environment(this_object())) == "/open/world1/acme/bonze/b17" ) {
            object staff;
            staff = new("/open/world1/acme/bonze/npc/wp/seven-staff.c");
            staff->move(this_object());
            command("emote 東翻西瞧，發現了一些端倪...\n");
            message_vision("$N雙手抱住了金身佛，用力地轉過身來，似乎發現了什麼？！\n", this_object());
        }

        /* 寒澈道觀-禪室 */
        if( file_name(environment(this_object())) == "/open/world1/tmr/freezetaoism/temple7" ) {
            this_object()->set("move_to", "/open/world1/tmr/freezetaoism/downroad1");
            command("emote 東翻西瞧，發現了一些端倪...\n");
            command("move 蒲團");
        }

        /* 地下石室 */
        if( file_name(environment(this_object())) == "/open/world1/tmr/freezetaoism/downroad3" ) {
            command("emote 東翻西瞧，發現了一些端倪...\n");
            command("push 石壁");
        }

        /* 地下秘室 */
        if( file_name(environment(this_object())) == "/open/world1/tmr/freezetaoism/downroad4" ) {
                command("hmm");
                command("insert staff into 插槽");
                command("hehe");
        }

//        CHANNEL_D->do_channel(this_object(), "sys", msg );

        this_object()->add("way_point", 1);
        way_point++;
    }

    if( this_object()->query("way_point") < sizeof(way) )
        call_out("go_open_war", 3);

    return;
}

void open_war()
{
    object demon;
    string msg;

    "/u/a/acme/god"->tune_game("群魔亂舞");

    msg = "\n\t\t"HIW"【"HIG"天數異象"HIW"】"NOR"風雲變色，豬羊變瘦，天搖地動，群魔舞動！！！\n\n";
    message("world:world1:vision", msg ,users());
    return;
}
