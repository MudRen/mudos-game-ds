// tuijianxin-1.c ���˫H �M-��

inherit ITEM;

void create()
{
        set_name("���˫H", ({"quanzhen xin1", "xin1", "letter1"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","�o�O�@�ʲM�r���v�L�̬��A�g�����˫H�A�̦��i�����V�Ӧr���v���̾ǲߪZ���C\n");
//		set("no_drop", "�o�˪F�褣�����}�A�C\n");
                set("material", "paper");
        }
}

