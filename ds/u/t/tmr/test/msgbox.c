#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("�_���T����ܾ�",({"msg's box","box"}) );
        set("long","�o�O�_�Ψ����msg ��user() ���D�������C\n");
        set_weight(100);
        if (clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","��");
                set("value",100);
        }
        setup();

}
void init()
{
        add_action("do_show","show");
}


int do_show()
{
        message("world:world1:vision",
HIG"�^�ѩӹB�A�_�ݬL��:\n\n"
+HIW"����ӤѮ�n���ԡA�B�B�n�����A�|�������M�H�ξi�ߩʡC\n"
+HIW"�M�H�ͦۥj�ֵL���A�w�^���~�L�H�A����"+HIY" �C�s�L(kkeenn) \n"HIW
 +"�ĥ��o���A"+HIW"���Τ߾ǲߡA�o�� DS �C\n\n" NOR

+CYN "(�C�s�L���v���q (apprentice) �ɦ� (admin) �C)\n\n" NOR
      ,users() );







return 1;
}

