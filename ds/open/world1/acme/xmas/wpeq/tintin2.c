//�t�Ϭ��ʲĤG�W �@�@(tintin) §�� -by tmr-

#include <ansi.h>
#include <armor.h>
inherit PANTS;

void create()
{
        set_name(HIW "�զ����" NOR ,({ "tintin skirt","skirt" }) );
        set("long",
"�t�Ϭ��ʲĤG�W �@�@�ұo����§���C\n"
"�@��¤������s���զ���ȡA�b����Ӯg�U�A���e�b�z�����C\n"
);
        set_weight(1500);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "fur");
                set("unit", "��" );
                set("value",2500);
                set("valme",3);
                set("no_sac",1);
                  set("armor_prop/armor", 15);
                set("armor_prop/dex",1);
        }
        setup();
}

int query_autoload() { return 1; }
