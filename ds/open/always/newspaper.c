// 報紙
// Luky @DS 1999.9.2
#include <localtime.h>
#include <ansi.h>
#define NEWS_DIR "/example/news/"
inherit ITEM;

void create()
{
         set_name("夢幻日報",({"dream newspaper", "newspaper"}) );
        set("long",@LONG
一份印刷精美的報紙，上面登了一些最近發生的大事和一些瑣碎
的廣告。夢幻日報社榮譽發行。
LONG
);
        set_weight(200);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("value",15);
                set("unit","份");   //luky
        }
        setup();
}

string short()
{
        mixed *local;
        string str;
          local = localtime(time());
                str=sprintf("夢幻日報(Dream newspaper) [中華民國%d年%d月%d日]",
                local[LT_YEAR]-1911,local[LT_MON]+1,local[LT_MDAY] );
        return str;
}


// 本日大事
string daily_news() {
        string str = NOR+YEL"\n\t\t\t\t\t【第一版 "HIW"本日大事"NOR+YEL"】\n";
        str += YEL"﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋\n"NOR;
        str += RECORD_D->query_temp_rec();
        str += "\n";
        return str;
}

// 卷軸消息
string scroll_news() {
        string str = NOR+YEL"\n\t\t\t\t\t【第二版 "HIW"卷軸消息"NOR+YEL"】\n";
        str += YEL"﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋\n"NOR;
        //str += HIY"共產出有"+ RECORD_D->getTotalScroll()+ "張強化卷軸。\n"NOR;
        str += HIY"強化卷軸的進一步消息，請購買「卷軸小報(scroll note)」。。\n"NOR;
        str += "\n";
        return str;
}

// 夢幻名人榜
string users_page() {
        string str = YEL"\n\t\t\t\t\t【第三版 "HIY"夢幻名人榜"NOR+YEL"】\n";
        str += YEL"﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋\n"NOR;
        str += RECORD_D->query_popularity_rec();
        str += "\n";
        str += RECORD_D->query_past_money_rec();
//      str += "\n";
//      str += RECORD_D->query_now_money_rec();
        str += "\n";
        str += RECORD_D->query_mk_rec();
        str += "\n";
        str += RECORD_D->query_pk_rec();
        str += "\n";
        str += RECORD_D->query_usage_rec();
        str += "\n";
        return str;
}

string big_news() {
        string str = NOR+YEL"\n\t\t\t\t\t【第四版 "HIG"重要消息"NOR+YEL"】\n";
        str += YEL"﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋\n"NOR;
        if( file_size(NEWS_DIR"news_3.txt") < 1 ) str +="\n 沒壞消息就是好消息 \n\n";
        else str += read_file(NEWS_DIR"news_3.txt");
        return str;
}

string sub_publish() {
        string str = NOR+YEL"\n\t\t\t\t\t【第五版 "HIW"副刊"NOR+YEL"】\n";
        str += YEL"﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋\n"NOR;
        if( file_size(NEWS_DIR"news_5.txt") < 1 ) str +="\n";
        else str += read_file(NEWS_DIR"news_5.txt");
        str += "\n";
        return str;
}

string news_title() {
        int idx;
        string *titles = NEWS_D->getTitles();
        string str = NOR+YEL"\n\t\t\t\t\t【第六版 "HIW"東森新聞頭條"NOR+YEL"】\n";
        str += YEL"﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋\n"NOR;
        if(sizeof(titles)<1) return str + "\n";
        for(idx=0;idx<sizeof(titles);idx++) {
                str +=  CYN"" + sprintf("%4d: %s\n", idx+1, titles[idx] );

        }
        str += "\n" NOR;
        return str;
}


string advert() {
        int *numbers;
        string str;
        numbers=LOTTERY_D->query_number();

        str = NOR+YEL"\n\t\t\t\t\t【 "HIC"分類廣告版"NOR+YEL"】\n";
        str += YEL"﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋\n"NOR;
        if( file_size(NEWS_DIR"news_4.txt") < 1 ) str +="\n 徵求廣告中 \n\n";
        else str += read_file(NEWS_DIR"news_4.txt");
        str += NOR+YEL"﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋﹋\n"NOR;
        if(sizeof(numbers))
        str += sprintf("夢幻彩卷 [第%d期] <超級特獎已累積至:%d>\n中獎號碼: \n\t超級特獎: %d\n"
                "\t頭獎: %d\n\t二獎: %d\n\t三獎: %d\n\t四獎: %d\n\t五獎: %d\n\t六獎: %d\n\t七獎: %d\n\t八獎: %d\n\n\n"
                "  目前第 %d 期彩卷正在瘋狂熱賣中!! 搶購人潮不斷, \n  根據最新調查資料, 至目前為止已賣出 %d 張了!!\n\n"
        ,LOTTERY_D->query_times(),LOTTERY_D->query_super_jack_pot(),LOTTERY_D->query_super_jack(),
        numbers[0],numbers[1],numbers[2],numbers[3],numbers[4],numbers[5],numbers[6],numbers[7],LOTTERY_D->query_times()+1,
        LOTTERY_D->query_ticket_amount()
         );
        return str;
}



string long()
{
        string str;
        str = short();

        str += daily_news();
        str += scroll_news();
        str += users_page();
        str += big_news();
        str += sub_publish();
//        str += news_title();
        str += advert();
        str += "\t□ Luky主編，Tmr副編: 以後將會陸續增加專欄, 敬請期待。\n\n";

        return str;
}

