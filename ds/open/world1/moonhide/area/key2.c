#include <ansi.h>
inherit ITEM;  
inherit F_UNIQUE;

void create()
{
        set_name(HIW"�ե����_"NOR,({"white-light key","key"}));
        set("long",@long
���L�����O�s���F��A�����D������@�ΡA�u�ݨ��_��
�I����۴X�ӷL�p���r�A�y�u���Y�}�A�����֥X�z�A��
��ĭ�õۤ���N��H
long
                );

        set_weight(100);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("volume",5);
                set("value", 5000); 
                set("door","whitekey");
        }
        setup();
}

