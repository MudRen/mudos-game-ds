#include <ansi.h>
#include <armor.h>
inherit SHIELD;

void create()
{
        set_name(MAG"�K��"HIM"�X����"HIR"(S)"NOR,({"huge-turtle shield","shield"}));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else 
        {
        set("unit", "��");
        set("volume",3);
        set("long", @LONG
�@���K���Ϊ����޵P�A�K�Ө��H���O�H���P�����ݿĦX���@���X����
�A�Q�ΦU�ت��ݤ��ۤ������S�ʡA��N�Ө��������Ƭ��L�ΡC
LONG
        );
        set("value",8000);
        set("material","steel");
        }
        set("armor_prop/armor",28);
        setup();
}

int query_autoload() { return 1; }
