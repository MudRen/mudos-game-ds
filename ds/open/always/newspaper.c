// ����
// Luky @DS 1999.9.2
#include <localtime.h>
#include <ansi.h>
#define NEWS_DIR "/example/news/"
inherit ITEM;

void create()
{
         set_name("�ڤۤ��",({"dream newspaper", "newspaper"}) );
        set("long",@LONG
�@���L���������ȡA�W���n�F�@�ǳ̪�o�ͪ��j�ƩM�@�Ǻ��H
���s�i�C�ڤۤ�����a�A�o��C
LONG
);
        set_weight(200);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("value",15);
                set("unit","��");   //luky
        }
        setup();
}

string short()
{
        mixed *local;
        string str;
          local = localtime(time());
                str=sprintf("�ڤۤ��(Dream newspaper) [���إ���%d�~%d��%d��]",
                local[LT_YEAR]-1911,local[LT_MON]+1,local[LT_MDAY] );
        return str;
}


// ����j��
string daily_news() {
        string str = NOR+YEL"\n\t\t\t\t\t�i�Ĥ@�� "HIW"����j��"NOR+YEL"�j\n";
        str += YEL"�ʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡ�\n"NOR;
        str += RECORD_D->query_temp_rec();
        str += "\n";
        return str;
}

// ���b����
string scroll_news() {
        string str = NOR+YEL"\n\t\t\t\t\t�i�ĤG�� "HIW"���b����"NOR+YEL"�j\n";
        str += YEL"�ʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡ�\n"NOR;
        //str += HIY"�@���X��"+ RECORD_D->getTotalScroll()+ "�i�j�ƨ��b�C\n"NOR;
        str += HIY"�j�ƨ��b���i�@�B�����A���ʶR�u���b�p��(scroll note)�v�C�C\n"NOR;
        str += "\n";
        return str;
}

// �ڤۦW�H�]
string users_page() {
        string str = YEL"\n\t\t\t\t\t�i�ĤT�� "HIY"�ڤۦW�H�]"NOR+YEL"�j\n";
        str += YEL"�ʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡ�\n"NOR;
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
        string str = NOR+YEL"\n\t\t\t\t\t�i�ĥ|�� "HIG"���n����"NOR+YEL"�j\n";
        str += YEL"�ʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡ�\n"NOR;
        if( file_size(NEWS_DIR"news_3.txt") < 1 ) str +="\n �S�a�����N�O�n���� \n\n";
        else str += read_file(NEWS_DIR"news_3.txt");
        return str;
}

string sub_publish() {
        string str = NOR+YEL"\n\t\t\t\t\t�i�Ĥ��� "HIW"�ƥZ"NOR+YEL"�j\n";
        str += YEL"�ʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡ�\n"NOR;
        if( file_size(NEWS_DIR"news_5.txt") < 1 ) str +="\n";
        else str += read_file(NEWS_DIR"news_5.txt");
        str += "\n";
        return str;
}

string news_title() {
        int idx;
        string *titles = NEWS_D->getTitles();
        string str = NOR+YEL"\n\t\t\t\t\t�i�Ĥ��� "HIW"�F�˷s�D�Y��"NOR+YEL"�j\n";
        str += YEL"�ʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡ�\n"NOR;
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

        str = NOR+YEL"\n\t\t\t\t\t�i "HIC"�����s�i��"NOR+YEL"�j\n";
        str += YEL"�ʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡ�\n"NOR;
        if( file_size(NEWS_DIR"news_4.txt") < 1 ) str +="\n �x�D�s�i�� \n\n";
        else str += read_file(NEWS_DIR"news_4.txt");
        str += NOR+YEL"�ʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡ�\n"NOR;
        if(sizeof(numbers))
        str += sprintf("�ڤ۱m�� [��%d��] <�W�ůS���w�ֿn��:%d>\n�������X: \n\t�W�ůS��: %d\n"
                "\t�Y��: %d\n\t�G��: %d\n\t�T��: %d\n\t�|��: %d\n\t����: %d\n\t����: %d\n\t�C��: %d\n\t�K��: %d\n\n\n"
                "  �ثe�� %d ���m�����b�ƨg���椤!! �m�ʤH�餣�_, \n  �ھڳ̷s�լd���, �ܥثe����w��X %d �i�F!!\n\n"
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
        str += "\t�� Luky�D�s�ATmr�ƽs: �H��N�|����W�[�M��, �q�д��ݡC\n\n";

        return str;
}

