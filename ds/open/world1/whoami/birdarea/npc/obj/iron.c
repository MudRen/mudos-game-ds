#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("�K��",({ "iron stone","stone" }));
        set_weight(9000);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("long","�@�ӥ��Z�L�_�A�p�@���_�����K�ۡA�A���T�h�æۤv�F�����۳o�تF��...\n");
                set("unit","��");
                set("value",100);
        }
        setup(); 
}

