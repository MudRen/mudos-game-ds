#include <ansi2.h>
inherit ITEM;
void create()
{
        set_name("�Ӫ��ؤl", ({"seeds" }) );
        set("long", 
"�@�ɤ@�ɪ��Ӫ��ؤl�C\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "��");
        }
        setup(); 
}