#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("�����T�h�e����", ({ "xiang stone", "stone"})); 
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("weight", 1000);
                set("long", "�o�O�F�~���J�����䤤�@�ӡA�X�۰���A�s�F�A�e�n�@�a�A\n�O�D���`���Ȫ��j���C\n");
                set("material", "stone");
                }
                set("value", 100);
}
