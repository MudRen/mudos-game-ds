inherit ITEM;

void create()
{
        set_name("�����ҷ�",({ "citizen licence","licence"}) );
        set_weight(40);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("long","�o�O�@�iA �Ť����ҷӡA�ݨӨèS�����B�C\n");
                set("value",1);
                set("no_sell",1);
                set("no_sac",1);
                set("card_level",1); //�ҷӵ��� A
        }
        setup();
}

int query_autoload() { return 1; }

