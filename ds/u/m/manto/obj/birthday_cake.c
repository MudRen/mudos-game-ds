#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name("����"HIR"����"NOR"��"NOR""YEL"���Ԧ�Ĭ"NOR, ({ "tiramisu", "cake" }) );
        set_weight(1000);
        if( clonep() )
            set_default_object(__FILE__);
        else {
                set("unit", "��");
set("long", "
���Ԧ�Ĭ�ATiramisu�A�b�q�j�Q�娽�A���u�a�ڨ��v���t�q�A�a�������u�O�����A�٦�"HIR"�R"NOR"�M"HIY"����"NOR"�C

�@�h���z�FEspresso�@�ػP�s�B��P�M�����J�|���I��������氮�A�@�h�V�X�FMascar ponecheese
�B�J�B�A���o�M�}���ۤh�k�A�h�h�|�W�h�A�W�Y�A���@�h�������i�i��...

�j�f�r�U�h�A���������ַP�q�f���X��������C

�W�����۴X������A����Υ��J�O���g�W�F"HIM"��"HIW"�ۢ�����"HIY"�ͤ�ּ�"HIM"��
"NOR);
        }
set("food_remaining", 4);
        set("heal_hp",2000);  
set("heal_mp",2000);
set("heal_ap",2000);

        setup();
}

int query_autoload() { return 1; }
