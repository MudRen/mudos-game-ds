#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name(HIC"Flyin�S�s�J�|"NOR,({ "flyin cake","cake" }) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long",@LONG
                        ��  ��       
                        �i  �i       
                        �i  �i      
                   ����������������  
                   ���ˡˡˡˡˡ���  
                  ������������������ 
                ����������������������
                ���H�H�H�H�H�H�H�H�H�� 
                ����������������������
�o�O�@����o���R�����J�O�f�����J�|�A�@�}�}��������A�u�O�t�H
���C�T�ءB�����j�ʡC�J�|�W�٤p���l�l���D�ۡG
�u���@��]�E����(flyin)���Q���j�� �ͤ�ּ�!!!�v�C
LONG);
        set("unit", "��");
        set("material","food2");
        }
        setup();
        set("value",0);
        set("food_remaining",20);
        set("heal_hp",500);
        set("heal_mp",500);
        set("heal_ap",500);
}
