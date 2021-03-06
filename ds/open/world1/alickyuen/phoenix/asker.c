#include <ansi.h>

inherit NPC;

string where ="";

mapping areas= ([
        "/open/world1/acme/area/" : "天城",
        "/open/world1/acme/bonze/" : "凌雲寺",
        "/open/world1/acme/cominging/" : "天城大牢",
        "/open/world1/cominging/purple_sun/" : "紫陽山",
//        "/open/world1/ground_temple/" : "地下神殿",
        "/open/world1/moonhide/area/" : "天界",
        "/open/world1/tmr/area/" : "滄縣",
        "/open/world1/tmr/ghost-forest/" : "鬼斷森林",
        "/open/world1/wilfred/meadow/" : "牯牛草原",
        "/open/world1/wu_sha_town/" : "無沙鎮",
        "/open/world1/kkeenn/love/" : "情城池",
          "/open/world1/tmr/dragoncity/" : "磐龍城",
          "/open/world1/tmr/frost/" : "倚霄山",
]);

int restart();
string eq_check();

void create()
{
        set_name("寶藏家", ({ "rich man", "man" }) );
        set("level", 1);
        set("long", @long
這一個人身上滿是名貴的服飾，應該非常富裕，但臉上卻露出一個
無奈的表情，不知為什麼事而煩惱似的。
long);
        set("str", 100);
        set("can_speak", 1);
        set("no_kill", 1);
        set("inquiry/裝備", (: eq_check :) );
        setup();
        set_living_name("phoenix_asker");
}

int talk_action(object me)
{
        object living;
        string msg;

        if( me->query("level") < 31 && !wizardp(me) ) return 0;
        living = find_living("phoenix");
        if( living && environment(living) ) return 0;

        if( !me->query_temp("quest/phoenix") )
        {
                command("whisper "+me->query("id")+" 我在尋找一樣名叫[鳳凰之羽(Plume of phoenix)]的東西");
                command("whisper "+me->query("id")+" 我是從其中一幅藏寶圖中發現的,這種珍貴的東西只有在鳳凰身上才找到..");
                command("whisper "+me->query("id")+" 但呼喚鳳凰的方法是找齊在古代各處的共七個有[★]型圖案的夜明珠..");
                command("whisper "+me->query("id")+" 藏寶圖上雖有大概位置說明...但我還是找不到");
                command("whisper "+me->query("id")+" 你能夠幫我這個大忙嗎？(若幫我的話，請再次跟我talk)");
                me->set_temp("quest/phoenix", 1);
                return 1;
        }
        msg = "";
        restart();
        restart();
        restart();
        restart();
        restart();
        restart();
        restart();
        if( sizeof(filter_array( children("/open/world1/alickyuen/phoenix/pearl"), (: clonep :) )) )
        {
                foreach(object pearl in filter_array( children("/open/world1/alickyuen/phoenix/pearl"), (: clonep :) ) )
                {
                        object room;
                        room = environment(pearl);
                        if( room->is_room() ) msg += room->query("short")+", ";
                        else if( userp(room) ) msg += room->name()+"(玩家), ";
                        else msg += room->name()+", ";
                }
        }
        command("whisper "+me->query("id")+" 嗯,先謝過啦,希望你能順利把這羽毛帶回來給我:Q ");
        command("whisper "+me->query("id")+" 根據地圖上顯示,這七個夜明珠應該是在 "+where+" 這幾個區域之中");
        command("whisper "+me->query("id")+" 但現在聽說在 "+msg+" 這幾個人或地點有出現過~~");
        return 1;
}

int accept_object(object me, object ob)
{
        if( ob->query("id") != "plume of phoenix" || !me->query_temp("quest/phoenix") )
                return notify_fail(this_object()->name()+"說:我不要你這爛東西。\n");

        if( this_object()->is_busy() ) 
                return notify_fail(this_object()->name()+"正在忙著，沒空回答你。\n");

        message_vision("$N給了"+this_object()->name()+"一根$n。\n", me, ob);

        me->add_temp("quest/give_phoenix", 1);

        command("whisper "+me->query("id")+" 謝過了,你有沒多出來的羽毛喔?我可以幫你免費製作一件裝備:)");
        command("whisper "+me->query("id")+" 想要的話,再來找我吧(ask me about 裝備)");

        call_out( (:destruct($1):), 1, ob);

        return 1;
}

int restart() {
        string dir, *file, dest;
        object pearl;

        this_object()->set("pearl", sizeof(filter_array( children("/open/world1/alickyuen/phoenix/pearl"), (: clonep :) )));

        if( this_object()->query("pearl") >= 7 ) 
                return 1;

        dir = keys(areas)[random(sizeof(keys(areas)))];
        file = get_dir(dir);
        dest = dir+file[random(sizeof(file))];

        if( !objectp(load_object(dest)) 
        || !load_object(dest)->query("short")
        || !load_object(dest)->query("exits")
        || !load_object(dest)->is_room()
        ) {
                return restart();
        }

        where += values(areas)[member_array(dir , keys(areas))]+",";
        pearl = new(__DIR__"pearl");
        pearl->move(dest);
        this_object()->add("pearl", 1);
        return 1;
}

string eq_check()
{
        object me = this_player();

        command("whisper "+me->query("id")+" 你若認為現在的羽毛數量足夠的話就answer yes吧，當然越多羽毛，弄出來的裝備就越強。\n");
        return "你現在共給了我 "+me->query_temp("quest/give_phoenix")+" 根羽毛.";
}
void init()
{
        add_action("do_answer", "answer");
}

int do_answer(string arg)
{
    object me, leather;
    int temp;
    me = this_player();

    if( !me->query_temp("quest/phoenix") || !me->query_temp("quest/give_phoenix") )
        return 0;

    if( !arg || arg != "yes" ) return 0;

    leather = new(__DIR__"leather");
    leather->move(this_object());
    temp = me->query_temp("quest/give_phoenix");
    me->delete_temp("quest/phoenix");
    me->delete_temp("quest/give_phoenix");

    leather->set("armor_prop/shield", 0);
    leather->set("armor_prop/damage", 0);
    leather->set("armor_prop/armor", temp);
    if( temp >= 25 )
        leather->set("armor_prop/armor", 25);

    if( temp >= 35 ) leather->set("armor_prop/int", 1);
    if( temp >= 45 ) leather->set("armor_prop/dex", 1);
    if( temp >= 55 ) leather->set("armor_prop/str", 1);
    if( temp >= 65 ) leather->set("armor_prop/con", 1);
    if( temp >= 256 )
    {   
        leather->set("armor_prop/sou", 1);
        leather->set("armor_prop/tec", 1);
        leather->set("armor_prop/bio", 1);
        leather->set("armor_prop/wit", 1);
        leather->set("armor_prop/bar", 1);
    }
     if( temp >= 512 )
    {
                leather->set("armor_prop/int", 2);
                leather->set("armor_prop/dex", 2);
                leather->set("armor_prop/str", 2);
                leather->set("armor_prop/con", 2);
                leather->set("armor_prop/bio", 2);
                leather->set("armor_prop/bar", 2);
                leather->set("armor_prop/wit", 2);
                leather->set("armor_prop/tec", 2);
                leather->set("armor_prop/sou", 2);
                leather->add("armor_prop/armor", -50);
                leather->set("wear_msg", HIR"$N穿上$n"HIR"後全身變成了火紅色，身體有發生異變的狀況。\n"NOR);
    }
    
    command("give leather to "+me->query("id"));
    return 1;
}

void clean()
{
        remove_call_out("clean");
        where="";
        foreach(object pearl in filter_array( children("/open/world1/alickyuen/phoenix/pearl"), (: clonep :) ) ) {
                pearl->gone();
        }
}

