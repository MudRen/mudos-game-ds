#include <armor.h>
#include <ansi.h>
inherit BOOTS;

void create()
{
        set_name(HIW"�񵾻ȹu"HIR"(S)"NOR, ({ "phoenix boots","boots" }) );
        set("long",@LONG
�@���ȥժ��u�l�A�u�l�W�U���@���ݮݦp�ͪ�����J���W�A�b�u�l
��Ǧ��i�X�@�����l�A�樫�ɥO�H���p�P�������Pı�C
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
                set("armor_prop/armor", 15);
        setup();
}

int query_autoload() { return 1; }
