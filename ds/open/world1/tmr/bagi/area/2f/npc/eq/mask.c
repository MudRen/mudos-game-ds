#include <armor.h>
#include <ansi.h>

inherit MASK;

void create()
{
        set_name("�H�魱��",({"freeze-sun mask" ,"mask" }));
        set_weight(3000);
        set("long", @long
�o�O�@�ƥδH���~�ֻs��������A���M���񪺤��n�ݡA���O���~��
���ٲĤ@��T�@�i�A�@�몺�M�C�Q�n�b�W�Y���Ӭ}������C
long
);
        set("unit", "��");
        set("value", 3500);
        set("armor_prop/armor", 5);
        set("armor_prop/con", 1);
        set("armor_type", "mask");
        set("wear_msg",HIY"$N�y�S�L���A�w�w���N�H�魱�����F�W�h�C"NOR);
        setup();
}

