// ����
// Luky @DS 1999.9.2
#include <localtime.h>
#include <ansi.h>
#define NEWS_DIR "/example/news/"
inherit ITEM;

void create()
{
        set_name("�ڤۭ�ķs�D��",({"ettoday paper","paper"}) );
        set("long",@LONG
�@���L���������ȡA�W���n�F����U���ɨƷs�D�Y���C
LONG
);
        set_weight(200);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("value",15);
                set("unit","��");
        }
        setup();
}

string short()
{
        mixed *local;
        string str;
        local = localtime(time());
                str=sprintf("�ڤۭ�ķs�D��(ettody paper) [���إ���%d�~%d��%d��]",
                local[LT_YEAR]-1911,local[LT_MON]+1,local[LT_MDAY] );
        return str;
}

string news_title() {
        int idx;
        string *titles = NEWS_D->getTitles();
        string str = NOR+YEL"\n\t\t\t\t\t�i "HIW"��� ETToday �s�D�Y��"NOR+YEL"�j\n";
        str += YEL"�ʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡ�\n"NOR;
        if(sizeof(titles)<1) return str + "\n";
        for(idx=0;idx<sizeof(titles);idx++) {
                str +=  CYN"" + sprintf("%4d: %s\n", idx+1, titles[idx] );

        }
        str += "\n" NOR;
        return str;
}


string long()
{
        string str;
        str = short();

        str += news_title();
        str += YEL"�ʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡ�\n"NOR;
        str += "\t�� Tmr �s���A�Цh�h���СC\n�г��� 2007/01/25�C\n\n";
        return str;
}


