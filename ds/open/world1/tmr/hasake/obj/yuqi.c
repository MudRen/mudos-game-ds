#include <ansi.h>

inherit ITEM;

void create()
{
         switch(random(13)) {
        case 0 : set_name(GRN"�ɤH�Y��"NOR, ({ "yu pei", "yu", "pei"})); break;
        case 1 : set_name(HIY"�~�������z"NOR, ({"yu pei", "yu", "pei"})); break;
        case 2 : set_name(HIW"�T�e�Υɾ�"NOR, ({"yu pei", "yu", "pei"})); break;
        case 3 : set_name(MAG"���s"NOR, ({"yu pei", "yu", "pei"})); break;
        case 4 : set_name(YEL"���s�Υɯ\��"NOR, ({"yu pei", "yu", "pei"})); break;
        case 5 : set_name(WHT"���t"NOR, ({ "yu pei", "yu", "pei"})); break;
        case 6 : set_name(WHT"�ߧΥɯ\"NOR, ({"yu pei", "yu", "pei"})); break;
        case 7 : set_name(YEL"��Υɯ\"NOR, ({"yu pei", "yu", "pei"})); break;
        case 8 : set_name(GRN"��κ��P�ۨ�"NOR, ({"yu pei", "yu", "pei"})); break;
        case 9 : set_name(HIY"�����ɤH"NOR, ({"yu pei", "yu", "pei"})); break;
        case 10 : set_name(CYN"����ɤH"NOR, ({"yu pei", "yu", "pei"})); break;
        case 11 : set_name(CYN"�ɪ�"NOR, ({"yu pei", "yu", "pei"})); break;
        case 12 : set_name(MAG"�ɻ�"NOR, ({"yu pei", "yu", "pei"})); break;
        }
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("unit", "��");
                set("weight", 1000);
		set("long", "�o�O�F�~�ɥ۹��~�����@�ӡA�X�۰���A�s�F�A�e�n�@�a�C\n");
		set("material", "stone");
		}
	setup();
}