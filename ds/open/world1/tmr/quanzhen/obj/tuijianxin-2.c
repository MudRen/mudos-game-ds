// tuijianxin-2.c ���˫H ��-�B

inherit ITEM;

void create()
{
        set_name("���˫H", ({"quanzhen xin2", "xin2", "letter2"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","�o�O�@�ʧӦr���v�L�̬��A�g�����˫H�A�̦��i�����V�B�r���v���̾ǲߪZ���C\n");
//		set("no_drop", "�o�˪F�褣�����}�A�C\n");
                set("material", "paper");
        }
}

