#include <ansi.h>
inherit ITEM;
void create()
{

        set_name(WHT"�o������"NOR,({"zong zi ticket"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "�i");
                set("long",
               "�@�i�o�����ȡA�W���ҽk�a�g��"WHT"�A�o�ɤK���A�o�ˤ]�S���A���h���ͯ��v�D���a�A������"NOR"�C\n"NOR);
             }
        set_weight(100);     
        set("no_drop",1);
        set("no_auc",1);
        set("no_sell",1);

        setup();
} 
