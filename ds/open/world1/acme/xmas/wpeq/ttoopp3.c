//�t�Ϭ��ʲĤ@�W �ӯT(ttoopp) §�� -by tmr-

#include <ansi.h>
#include <armor.h>
inherit LEGGING;

void create()
{
        set_name("���_�@��" ,({ "ttoopp leggings","leggings" }) );
        set("long",
"�t�Ϭ��ʲĤ@�W �ӯT�ұo����§���C\n"
"�o�O�@�󯫩_���@��Ať����W�����H�N�֦����_���O�q�C\n"
);
        set_weight(800);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "fur");
                set("unit", "��" );
                set("value",1000);
                set("valme",1);
                set("no_sac",1);
                set("armor_prop/armor", 12);
                set("armor_prop/dex",1);
        }
        setup();
}

int query_autoload() { return 1; }


