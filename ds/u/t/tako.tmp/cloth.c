#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(HIW"�ƶ��m"NOR,({"fly cloth","cloth"}) );
        set("long",@LONG
�o�O�@��Ѷ��ҽs´�Ӧ�����m�A�n��O�C�C�|�Q�E�~
���ݾ����A��P�A�~�賣�S�ܻ��C
LONG

);
        set_weight(2100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "��");
        }
        set("value",240);
        set("armor_prop/armor",15);
        set("armor_prop/dodge",30); 
        set("armor_prop/parry",10);        setup();
}


