inherit ITEM;
inherit F_BULLET;
void create()
{

set_name("���b",({"bolt"}));
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("unit", "��");
        set("long","�@���h��b�������b, �i�H���Ѩ}�n���g�{�P���ˤO, �Х�reload ���O�N����W��.\n");
        }
set("value", 50);
set_weight(1000);
set("amount",1);                //�u�Ķq
set("bullet/damage",13);        //���ˤO
set("bullet/unit","��");        //�u�ĳ��
set("bullet/name","���b");      //�u�ĦW��
set("type","small");            //�l�u����
setup();
}
