#include <ansi.h>
#include <armor.h>
inherit MASK;

void create()
{
        set_name(HIY"�{�d��"NOR,({"faceoff mask","mask"}) );
        set("long",@LONG
�@�Ӱ{�{�o��������A���o�ۤ��ݩ�o�ӥ@�ɪ�����....
LONG
);
        set_weight(300); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_int",15);
                set("unit", "��");       
                set("value",2000);          
                set("volume", 2);                       
                set("material", "gold");   
        }
        set("armor_prop/armor",1);       
        set("armor_prop/int",1);
        setup();
}

