#include <ansi.h>
#include <armor.h>
inherit PANTS;

void create()
{
        set_name(HBK "�t�٥��]���" NOR,({ "anmao-troll skirt","skirt" }) );
        set("long",@LONG
�b���G�ʦ~�e�A�˪��v��t�ٳ����b�j�x�����񪺮q���w�~�A�t��
�����H�H���O��۳o�ؤ�ȡA���F�ΪA�O�x���~�A�b�Ԫ��s�s����
�Ӯɴ��A�o��Ȭ۷�@��A���e���i�l�C
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
                set("female_only", 1);
        }
        set("armor_prop/armor", 5);
        set("armor_prop/shield", 5);
        set("armor_prop/str", 1);
        set("armor_prop/dex", 1);
        set("armor_prop/hit", 25);
        setup();
}


