// ����
// Luky @DS 1999.9.2
#include <localtime.h>
#include <ansi.h>
#define NEWS_DIR "/example/news/"
inherit ITEM;

void create()
{
         set_name("���b�p��",({"scroll note", "note"}) );
        set("long",@LONG
�@���L���������b�p���A�W���Z�n�۱j�ƨ��b���X���q��
��L�H�ϥΪ����ΡC�o�W���������A�C��b�]12�I�Y�|�M�šC
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
                str=sprintf("���b�p��(scroll note) [���إ���%d�~%d��%d��]",
                local[LT_YEAR]-1911,local[LT_MON]+1,local[LT_MDAY] );
        return str;
}


// ���b����
string scroll_news() {
        string str = NOR+YEL"\n\t\t\t\t\t�i"HIW"���b����"NOR+YEL"�j\n";
        str += YEL"�ʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡ�\n"NOR;
         str += HIY"�@���X��"+ RECORD_D->getTotalScroll()+ "�i�j�ƨ��b�C\n"NOR;
       str += RECORD_D->query_scroll_record();
        str += "\n";
        return str;
}

string long()
{
        string str;
        str = short();

        str += scroll_news();
        str += "\t�� Luky�D�s�ATmr�ƽs: �H��N�|����W�[�M��, �q�д��ݡC\n\n";

        return str;
}

