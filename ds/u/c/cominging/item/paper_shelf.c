// ����
// Luky @DS 1999.9.2
// Comigning @DS 1999.9.25

#include <localtime.h>
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("���Ȭ[",({ "paper shelf","shelf"}) );
        set("long",@LONG

�@�[�Ψ��\����ȱM�Ϊ��[�l�A�W���u���ۤ@�����ȡA
���ӴN�O�ڤۤ�����ҵo�檺�ڤۤ���F�A�A�i�H��
[ read_paper {�ĴX��} ] �Ӿ\Ū�o�@�����ȡI

1.�ڤۤ��                     �ڤۤ�����a�A�o��C

LONG
        );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("value",15);
                set("unit","�[");
        }
        setup();
}

string short()
{
        mixed *local;
        string str;
        local = localtime(time());
        str = sprintf( HIC"���Ȭ["NOR"(paper shelf) "HIG"[ ���: ���إ���%d�~%d��%d�� ]"NOR,
                local[LT_YEAR]-1911,
                local[LT_MON]+1,
                local[LT_MDAY] );
        return str;
}

void init()
{
        if( environment(this_object()) == this_player() )
                this_object()->move(environment(this_player()));
        add_action("do_setup","setup");
        add_action("do_read","read_paper");
}

int do_read(string arg)
{
        object me;
        int chose, *numbers;
        string str;

        numbers = LOTTERY_D->query_number();
        me = this_player();

        if( !arg || sscanf(arg,"%d edition",chose)!=1 )
                return notify_fail("�A�nŪ�ĴX���r�H(read {����} edition). \n");
        if( chose > 6 || chose < 1 )
                return notify_fail("�A½�F½����, ���G�S���o�@�����ˤl�I\n");
        switch(chose)
        {
                case 1: // �Ĥ@��
                        str = YEL"\n\t\t\t\t\t�i�Ĥ@�� "HIY"�ڤۦW�H�]"NOR+YEL"�j\n";
                        str += YEL"�ʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡ�\n"NOR;
                        str += RECORD_D->query_popularity_rec();
                        str += "\n";
                        str += RECORD_D->query_past_money_rec();
                        str += "\n";
                        str += RECORD_D->query_now_money_rec();
                        str += "\n";
                        str += RECORD_D->query_mk_rec();
                        str += "\n";
                        str += RECORD_D->query_pk_rec();
                        str += "\n";
                break;
                //---------------------------------------------------------
                case 2: // �ĤG��
                        str = NOR+YEL"\n\t\t\t\t\t�i�ĤG�� "HIW"����j��"NOR+YEL"�j\n";
                        str += YEL"�ʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡ�\n"NOR;
                        str += RECORD_D->query_temp_rec();
                        str += "\n";
                break;
                //---------------------------------------------------------
                case 3: // �ĤT��
                        str = NOR+YEL"\n\t\t\t\t\t�i�ĤT�� "HIG"���n����"NOR+YEL"�j\n";
                        str += YEL"�ʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡ�\n"NOR;
                        if( file_size("/open/always/news_3.txt") < 1 ) str +="\n �x�D�s�i�� \n\n";
                        else str += read_file("/open/always/news_3.txt");
                break;
                //---------------------------------------------------------
                case 4:
                        str = NOR+YEL"\n\t\t\t\t\t�i�ĥ|�� "HIC"�����s�i"NOR+YEL"�j\n";
                        str += YEL"�ʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡ�\n"NOR;
                        if( file_size("/open/always/news_4.txt") < 1 ) str +="\n �x�D�s�i�� \n\n";
                        else str += read_file("/open/always/news_4.txt");               
                break;
                //---------------------------------------------------------
                case 5:
                        str = NOR+YEL"\n\t\t\t\t\t�i�Ĥ��� "HIC"�����}��"NOR+YEL"�j\n";
//                      str = NOR+YEL"�ʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡ�\n"NOR;
                        str += YEL"�ʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡʡ�\n"NOR;
                        if(sizeof(numbers))
                        str += sprintf("�ڤ۱m�� [��%d��] <�W�ůS���w�ֿn��:%d>\n�������X: \n\t�W�ůS��: %d\n"
                                "\t�Y��: %d\n\t�G��: %d\n\t�T��: %d\n\t�|��: %d\n\t����: %d\n\t����: %d\n\t�C��: %d\n\t�K��: %d\n\n\n"
                                "  �ثe�� %d ���m�����b�ƨg���椤!! �m�ʤH�餣�_, \n  �ھڳ̷s�լd���, �ܥثe����w��X %d �i�F!!\n\n",
                        LOTTERY_D->query_times(),
                        LOTTERY_D->query_super_jack_pot(),
                        LOTTERY_D->query_super_jack(),
                        numbers[0],numbers[1],numbers[2],numbers[3],numbers[4],numbers[5],numbers[6],numbers[7],
                        LOTTERY_D->query_times()+1,
                        LOTTERY_D->query_ticket_amount() );             
                break;
                
                case 6:
                        str = NOR+WHT"\n\t\t\t\t\t�i�S�O�W�[��"HIY"��"HIC"�C��@�ֵ�"NOR+WHT"�j\n";
                        str += HIW"�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i\n"NOR;
                        if( file_size("/u/c/cominging/song.txt") < 1 ) str +="\n �|����s \n\n";
                        else
                        {
                                str += HIC+read_file("/u/c/cominging/song.txt")+NOR;
                        }
        }
//      str += "\t�� �s���D�s: �H��N�|����W�[�M��, �q�д��ݡC\n\n";
        write(str);
        return 1;
}

int do_setup()
{
        object me;
        me = this_player();
        this_object()->move(environment(me));
        return 1;
}
