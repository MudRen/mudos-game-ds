#include <ansi2.h>

string WAR_DIR = "/open/world1/moonhide/westarea/";
string *god=({"lin","ean","mon","sha",
              "poo","dang","unin","liu"
             });

 string *guard=({"guard", "guard2" });

string *place=({"room2","room1","startroom","room3",
                "room4","room5","room6","room7","room8",
                "room9","room10","room11","room12","room13",
                "room14","room15","room",
                "way1", "way2", "way3", "way4", 
                "way5", "way6", "way7"
               });

int query_god()
{
    object god;

    while ( objectp(god=find_living("westwar")) )
    {
        if ( !environment(god) )
        {
            destruct(god);
            god = 0;
        }
        else break;
    }

    if ( objectp(god) ) return 1;
    return 0;
}


private void create() {
    seteuid(getuid());
}

// 表示是一個戰爭檔
int isWar() {
    return 1;
}

// 戰爭的持續時間
// 如果設為0, 表示戰爭的持續時間自行設定，不由系統控制
int getDuration() {
     return 300; // 5 min
}

// 開始戰爭所要執行的操作
// 傳回 1 表示戰爭啟動, 0 表示沒啟動
int doStartWar(object me)
{
    int i;
    object g;

    message("world:world1:vision",
            HIY"\n\t"+me->query("name") +HIW "闖入九天雲端，點燃香狄亞的燈火...\n\n"
            HIC"\t\t【雷神 艾涅爾】: 愚蠢的凡人！！眾神聽令，將所有入侵者"HIR"通 通 格 殺 ！\n\n" NOR
            ,users() );

    g = new(WAR_DIR + "obj/pill");
    g->move(WAR_DIR + place[random(sizeof(place))]);
    g = new(WAR_DIR + "obj/pill");
    g->move(WAR_DIR + place[random(sizeof(place))]);

   // soul    
    for (i=0;i< 12;i++)
    {
        g=new( WAR_DIR + "npc/"+god[random(sizeof(god))]);   // Add by -Acme-
        g->move(WAR_DIR+place[random(sizeof(place))]);   // Add by -Acme-
    }

    // guard 
    for (i=0;i< 12;i++)
    {
        g=new( WAR_DIR + "npc/"+guard[random(sizeof(guard))]);
        g->move(WAR_DIR+place[random(sizeof(place))]);
    }

     // thunder
      g = new( WAR_DIR + "npc/thunder");
     g->move(WAR_DIR+place[random(sizeof(place))]);

    
    return 1;
}
// 結束戰爭所要執行的操作
// 傳回 1 表示戰爭結束, 0 表示沒結束
int doEndWar( )
{
    // non finish
    if ( query_god() ) return 0;

    message("world:world1:vision",
            HIY"\n\t\t\t噹∼∼∼噹∼∼∼噹∼∼∼∼\n"NOR
            HIC"\n\t\t九天雲端的巨大"HIY"黃金鐘"HIC"被敲響，美妙的鐘聲傳遍整個世界！！！\n"NOR
        , users() );

    return 1;
}

void doHeartBeat()
{
    // nothing to check
}

