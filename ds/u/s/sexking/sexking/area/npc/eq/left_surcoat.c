#include <armor.h>
#include <ansi.h>
inherit SURCOAT;
void create()
{
        set_name(HIC"�v���өܭ�"NOR ,({ "left surcoat","surcoat" }) );
        set("long","�o�O�v��������a�N�N�۶Ǫ��ܭ��A�W���g�ۡu�v�������ӭ��v
                    ���G�O�o��ܭ��̦����D�H�C\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("limit_con",20);
        set("limit_int",25);
        set_weight(7500);
        set("unit", "��" );
        set("value",3350);
        set("armor_prop/armor", 6);
        set("volume",7);
        set("armor_prop/dex",2);
        set("armor_prop/str",1);
        }
        setup();
}

