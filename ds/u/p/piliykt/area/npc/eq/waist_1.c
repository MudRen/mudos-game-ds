#include <ansi.h>
#include <armor.h>
inherit WAIST;

void create()
{
        set_name("��ָy�a",({"tiger-skin waist","waist"}) );
        set("long",@LONG
�n�s���B�ꪺ��֩һs,ô�b�y���W���A���@�ث­����Pı.
LONG
);
        set_weight(0); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_con",20);
                set("unit", "��");       
                set("value",2000);          
                set("volume", 3);                       
                set("material", "fur");   
        }
        set("armor_prop/armor",5);       
        set("armor_prop/con",1);
        set("armor_prop/str",1);         
setup();
}

