#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIW+BLK"��]"NOR+YEL"�s��"NOR"����",({ "crocodile teeth","teeth" }));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("long","�q"HIW+BLK"��]"NOR+YEL"�s��"NOR"���W�ޤU�����A�ݨӨSԣ�γB�E\n");
                set("unit","��");
                set("value",0);
        }
        setup();
}

