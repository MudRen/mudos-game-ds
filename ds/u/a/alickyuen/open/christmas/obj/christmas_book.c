#include <ansi2.h>
inherit ITEM;
void create()
{
        set_name("�ﳷ�H���ʤJ����U", ({"christmas book","book" }) );
        set("long", 
"�o���ѬO���ʳ��K�O�ذe���C�̭��g�۰򥻨B�J�M�p���Z�G\n\n"
"1.�����A�ﳷ�H�̰򥻪��N�O�����X�Y(build head)�M����(build body)�C\n"
"2.���кu�ʳ��y(roll snowball)�M���곷�y(compress snowball)�o��Ӱʧ@�C\n"
"  �o�˳��y�~�|�j�A���X�Ӫ����H�~�|���C�ܩ�u�ʩM����o��Ӱʧ@�����ƽ�\n"
"  �U��ѦҸg��C\n"
"3.�̫�N�O�ݦU��Q����ɭԲզX�����H(build snowman)�o�C\n"
"4.�򥻤W�A�H�����Ⱘ������A�U�l�����]�|�q��W�L�U�ӡC�]�����ѮɽФ��n\n"
"  �ǤߡA�X��V�O�a�C\n"
"5.�̫�A���U��θ`�r�֡C\n"
"                                                          ���ʳ��q�W\n"
	);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "��");
        }
        setup(); 
}