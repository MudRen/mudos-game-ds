// quanzhen-ling.c ���u�O

inherit ITEM;

void create()
{
        set_name("���u�O", ({"quanzhen ling", "letter", "ling"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","�o�O�@���ȥ��{�{���O�P�A�Ѥ����u�Hñ�o�A�̦��i�̤l�ۥѦV�v�L�D�ԡC\n");
//		set("no_drop", "�o�˪F�褣�����}�A�C\n");
                set("material", "steel");
        }
}

