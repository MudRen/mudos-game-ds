#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(YEL"��֤j��"NOR,({"tiger cloth","cloth"}) );
        set("long",@LONG
�o�@���֤j��O�H�e�E�׻s��z���ɭ�,�@�ñq�r�ꪺ
���W���U�Ӫ�,�H�ۨ��骺�U�O�Ϊ��A�K,���S�����^,�O
�@��W�����n��,�����L��C
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
        set("armor_prop/armor",20);
        set("armor_prop/dodge",40); 
        set("armor_prop/parry",5);
        set("armor_prop/blade",20);
        set("armor_prop/dex",1);
        setup();
}



