#include <ansi.h>
inherit ITEM;

string pows(int index);
string version_card(int ver);

void create()
{
        set_name("�ȵP�s����", ({ "card browse set", "set", "browse set" }));
        set("long", @LONG
�o�O�@�x�����D����Ӫ�����, �A�i�H�� browsec �s���A���W���ȵP.
LONG
        );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "�x");
                set("value", 300);
        }
        setup();
}

void init()
{
        add_action("do_browse", "browsec");
}

int do_browse(string arg)
{
        object me = this_player(), card, *objs = all_inventory(me);
        int i, *pow, cards=1; 
        string msg = "", pow_m;

/*
 �P��    �d ��  �� ��    ��O�I��    ��  ��   �d��  ����
�¡¡�  �¡¡¡¡¡¡�  �¡ááá�  �ǡǡǡ�  �ǡ�  �¡�
    1    ���j  ���Ѥ�    ��������   �s���ǩ_   30    6
*/

//      if( arg != "card" ) return 0;

        if( !card=present("magic card", me) )
                return notify_fail("�A���W�S���P�I\n");

        for(i=0;i<sizeof(objs);i++)
                if( pointerp(pow=objs[i]->query("pow")) )
                {
                        pow_m = pows(pow[0]) + pows(pow[1]) + pows(pow[2]) + pows(pow[3]);
                        if( cards == 1 )
                                msg += HIG" �P��    "HIY"�d ��  �� ��    "HIM"��O�I��    "HIC"��  ��   "NOR+CYN"�d��  "YEL"����\n"NOR+
                                        HIG"�¡¡�  "HIY"�¡¡¡¡¡¡�  "HIM"�¡ááá�  "HIC"�ǡǡǡ�  "NOR+CYN"�ǡ�  "YEL"�¡�\n"NOR;
                        msg += sprintf(HIW"  %3d    %12s    %8s   %8s   %2d    %2d\n"NOR ,
                                cards++,
                                objs[i]->query("short"),
                                pow_m,
                                version_card(objs[i]->query("ver")),
                                objs[i]->query("num"),
                                objs[i]->query("lv"));
                }

        if( msg == "" ) return notify_fail("�A���W�S���P, �Ϊ̬O�P���]�w���~. \n");
        me->start_more(msg+NOR);
        return 1;
}

string version_card(int ver)
{
        // 1�\�� 2�s���ǩ_ 3�Z�� 4�s�j�t�C 5���s�p�� 6�ѫ����� 7�s�]�ûR 8�j�N�@��
        switch(ver)
        {
                case 1:
                        return "�\\��";
                case 2:
                        return "�s���ǩ_";
                case 3:
                        return "�Z��";
                case 4:
                        return "�s�j�t�C";
                case 5:
                        return "���s�p��";
                case 6:
                        return "�ѫ�����";
                case 7:
                        return "�s�]�ûR";
                case 8:
                        return "�j�N�@��";
                default:
                        return "���w�q";
        }
}

string pows(int index)
{
        string *match = ({"��","��","��","��","��","��","��","��","��","��"});
        if( index >= sizeof(match) ) return "��";
        return match[index];
}
