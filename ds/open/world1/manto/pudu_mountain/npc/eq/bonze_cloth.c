#include <armor.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit CLOTH;
void create()
{
set_name(HIW"�����P��"NOR, ({ "bonze cloth" ,"cloth" }));
set_weight(3000);
if (clonep())
set_default_object(__FILE__);
else {
set("long" , "�o�O�@�󹬫Q�Ҭ諸���y�A�W��¸�ۨǱ��C\n"NOR);
set("material", "silk");
set("unit", "��");
set("limit_str",5);
set("limit_level",25);
set("wear_msg", "�u��$N����@�ݡA�K��@�������z�۵�����m���P�Ʃܦb���W�C\n" NOR);
        set("replica_ob",__DIR__"bonze_cloth2");
        }
        set("armor_prop/armor", 6);
        set("armor_prop/shield", 18);
        set("armor_prop/sou", 1);
        set("armor_prop/bar", -1);
        set("armor_prop/con", 1);
        setup();
}
