#include <ansi.h>
#include <armor.h>
inherit HANDS;
void create()
{
        set_name(WHT"������Q�غ�"NOR ,({ "iron gauntlets","gauntlets" }) );
        set("long","�@���Υ��K����y�Ӧ�����M�A���q�����A���o��j�j��ϥ�\n"
                   "�p�����l�ұa�Ӫ��t���A�G�S���@�W���u�p����M�v�C\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(9400);
        set("material", "iron");
        set("unit", "��" );
        set("value",4300);
        set("armor_type", "hands");
        }
        set("limit_str",50); 
        set("limit_level",40);
        set("armor_prop/armor", 15);
        set("armor_prop/dodge",-15); 
        set("armor_prop/con",4);
        set("armor_prop/str",4);
        set("armor_prop/dex",-3);     
        setup();
}

