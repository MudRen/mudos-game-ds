#include <ansi.h>
#include <armor.h>
inherit PANTS;

void create()
{
        set_name(HBK "�t�٥��]���" NOR,({ "anmao-troll pants","pants" }) );
        set("long",@LONG
�b���G�ʦ~�e�A�˪��v��t�ٳ����b�j�x�����񪺮q���w�~�A�t��
�����H�H���O��۳o�ؤ�ǡA���F�ΪA�O�x���~�A�b�Ԫ��s�s����
�Ӯɴ��A�o��Ǭ۷�@��A���e���i�l�C
LONG);
        set_weight(3000);
        if ( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("material", "leather");
                set("volume",2);
                set("unit", "��");
                set("value", 1200);
                // �k�ʱM��
                set("male_only", 1);
        }
        set("armor_prop/armor", 5);
        set("armor_prop/shield", 5);
        set("armor_prop/con", 1);
        set("armor_prop/int", 1);
        set("armor_prop/hit", 25);
        setup();
}

