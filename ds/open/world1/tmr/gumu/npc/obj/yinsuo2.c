#include <weapon.h>;
#include <ansi.h>;

inherit WHIP;

void create()
{
        set_name(HIW"��������"NOR,({ "gold-silver whip", "whip" }) );
        set_weight(2000);
                set("long", "�@���զ���a�A�����٨t�ۤ@�Ӫ��⪺��y�C\n");
                set("unwield_msg",HIY"$N�H��@�ݡA�N�ȯ���J�h���C\n"NOR);
                set("wield_msg",HIY"$N�w�w�q�h�����X�@�ΦB�`�몺���ƴ��b���⤧�W�C\n"NOR);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 3500);
                set("material", "gold");
        }

        init_whip(55);
        setup();
}

