#include <armor.h>
#include <ansi.h>
inherit WRISTS;

void create()
{
        set_name(YEL"�Ϥ��@��"HIR"(S)"NOR,({ "magnetic wrists","wrists" }) );
        set("long",@LONG
�H�S����q�s�����@���@��A���M���������m��O���j�A���o�i�H�N
��ŧ���L�����ک�@�ǡA�ɨ��䨾�m�O�C
LONG);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(2000);
                set("material", "steel");
                set("unit", "��");
                set("value",3000);
                set("volume",2);
        }
                set("armor_prop/armor", 8);
        setup();
}

int query_autoload() { return 1; }
