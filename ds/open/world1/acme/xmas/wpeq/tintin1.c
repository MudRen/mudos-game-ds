//�t�Ϭ��ʲĤG�W �@�@(tintin) §�� -by tmr-

#include <ansi.h>
#include <armor.h>
inherit LEGGING;

void create()
{
        set_name(HIR "�t�Ϭ���" NOR ,({ "tintin leggings","leggings" }) );
        set("long",
"�t�Ϭ��ʲĤG�W �@�@�ұo����§���C\n"
"�@���j���⪺���w�w���A�򵳵����N�_�ӫD�`�ΪA�ŷx�C\n"
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

                  set("armor_prop/armor", 8);
                set("armor_prop/dex",1);
        }
        setup();
}

int query_autoload() { return 1; }
