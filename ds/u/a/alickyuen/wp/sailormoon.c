#include <armor.h>
#include <ansi.h>
inherit MASK;
void create()
{
        set_name("�ܨ���", ({ "dunno" }) );
        set_weight(2100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","�o�O�@���ܨ����C\n[�i�x�s�˳�]\n");
                set("unit", "��");
                set("material", "silk");
                set("no_give",1);
                set("no_drop",1);
                set("no_sell",1);
                set("no_sac",1);
                set("value",180);
        }
        //============�H�U���q�}��ϰ�ť�, �_�h�|�j�V��===============
        //==    �Y�}��ϰ�n�g���ذ���eq , ���w�n�]�� Only One EQ    ==
        set("armor_prop/id",({"sailormoon"}));
        set("armor_prop/name",({"���֤k�Ԥh"}));
        set("armor_prop/short",({"���֤k�Ԥh (Sailormoon)"}));
        set("armor_prop/long",({"�@�ӥ��q�i�������֤k�C\n"}));
        //==============================================================
        set("armor_prop/shield",50);
        set("armor_prop/dodge",50);
        set("armor_prop/armor",50);
                set("wear_msg",HIR"$N�j�s�@�n�i�ܨ��j, �y�ɤ@�ѤO����¶$N�P��!��M�A����X�{�F�@����֤k....."NOR);
                set("remove_msg",GRN"$N��M��F�@��, ����O���������h.."NOR);
        setup();
}

int query_autoload() { return 1; }
