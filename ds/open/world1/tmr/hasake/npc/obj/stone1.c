#include <ansi.h>

inherit ITEM;

void create()
{
        /* switch(random(7)) {
        case 0 : set_name("������ӵe����", ({ "xiang shi", "shi", "stone"})); break;
        case 1 : set_name("���M�L���e����", ({ "xiang shi", "shi", "stone"})); break;
        case 2 : set_name("���y�e����", ({ "xiang shi", "shi", "stone"})); break;
        case 3 : set_name("���Y��Եe����", ({ "xiang shi", "shi", "stone"})); break;
        case 4 : set_name("���~�e����", ({ "xiang shi", "shi", "stone"})); break;
        case 5 : set_name("�����T�h�e����", ({ "xiang shi", "shi", "stone"})); break;
        case 6 : set_name("��Z�e����", ({ "xiang shi", "shi", "stone"})); break;
        } */

        set_name("���M�L���e����", ({ "xiang stone", "stone"})); 
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("weight", 1000);
                set("long", "�o�O�F�~���J�����䤤�@�ӡA�X�۰���A�s�F�A�e�n�@�a�A\n�O�D���`���Ȫ��j���C\n");
                set("material", "stone");
                }
                set("value", 100);
        setup();
}
