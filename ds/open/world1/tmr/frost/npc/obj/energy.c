// �٧Q�l shelizi.c

#include <ansi.h>
inherit ITEM;
inherit F_PILL;

void create()
{
        set_name(HIG"�ѧ�����"NOR, ({ "tian-demon energy","energy" }));
        set("long",@LONG
�o�O�@���u�ѧ��v���Ƥd�~���O�һE��������A�������J��j�p�A��
�A��ۤ���ɡA��ı�o�A���F����G�n�Q�l�i�h�@�ˡC
LONG
        );
        set_weight(50);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("eat_msg","$N�Y�U�@���a�ۺ����~�����y�C");
                set("eff_msg",HIY "����̥R�K���X���O�q�H�ɦb�A�餺�|�B�y«�I�I"NOR  );
        }
          set("value", 2500);
        set("heal",([
                "hp"    : 500,
                "ap"    : 500,

        ]));
    setup();
}

