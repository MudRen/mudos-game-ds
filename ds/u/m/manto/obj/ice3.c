inherit ITEM;
#include <ansi.h>
inherit F_FOOD;

void create()
{
        set_name(YEL"���Ԧ�Ĭ"NOR, ({ "tiramisu" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
    set("long", "���Ԧ�Ĭ�ATiramisu�A�b�q�j�Q�娽�A�� �u�a�ڨ� �v���t�q�A�a�������u�O�����A�٦��R�M���֡C\n�@�h���z�FEspresso�@�ػP�s�]Masala�BRum��Brandy�^�B��P�M�����J�|���I��������氮�A�@�h\n�V�X�FMascar�Rponecheese�]�̾A�X�M���ΨӰ�Tiramisu���ۤh�^�B�J�B�A���o�M�}���ۤh�k�A�h�h\n�|�W�h�A�W�Y�A���@�h�������i�i���K�K�o�N�O���Ԧ�ĬTiramisu�C\n");
                set("value", 10);  
                set("food_remaining",10);
        }
}
