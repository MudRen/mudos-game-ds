#include <ansi.h>
#include <armor.h>
inherit MASK;

void create()
{
        set_name(HIY"��������"HIR"(S)"NOR,({"crystal mask","mask"}) );
        set("long",@LONG
�@�ӵo�X���~����������A��ӭ��㴹���ẫ�ӥB���ƵL��A��b�O
���ܤѤu���@�~�C
LONG);
        set_weight(500); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_level",25);
                set("unit", "��");       
                set("value",20000);          
                set("volume", 2);                       
                set("material", "stone");   
        }
        set("armor_prop/armor",3);
        set("armor_prop/shield",5);
        setup();
}

int query_autoload() { return 1; }
